/**
 * @file	CMonster.cpp
 * @breif	몬스터 관련된 클래스입니다.
 * @date	2014-07-03
 */
#include "CMonster.h"

/**
 * @breif	몬스터를 초기화 시킵니다.
 * @param	pLayer : 씬에서 CCLayer정보를 가져옵니다.
 * @return	생성자라 없음
 */
CMonster::CMonster(CCLayer *pLayer)
{
	//!< 몬스터 정보들 초기화
	m_pLayer				= pLayer;
	m_bIsDead				= false;

	//!< 몬스터 이미지 로드
	this->initWithFile("적몬스터1.png");
	
	//!< 몬스터 중점을 정 가운데로 설정
	this->setAnchorPoint(ccp(0.5f, 0.5f));

	//!< 캐릭터가 너무 작아서 키웁니다. (2배)
	this->setScale(2.0f);

	pBullet = new CBullet(pLayer);	//!< 여기서는 this가 Sprite기 때문에 안들어갑니다 CCLayer인 pLayer나 m_pLayer를 넘겨주세요
}

CMonster::~CMonster()
{
	//!< 마지막으로 메모리 해제를 해줍니다.
	release();	//!< 이건 Hero 스프라이트

	delete pBullet;	
}

void CMonster::Create(int type)
{
	//!< type값에 맞춰 몬스터를 생성하는 모습입니다.
	CCAction* pAction;
	if(type == 1)
	{
		this->initWithFile("적몬스터1.png");
		this->setPosition(ccp(rand() % 200, 1024));
		pAction = CCMoveBy::create(2.0f, ccp(100, -1024));
	}
	else if(type == 2)
	{
		this->initWithFile("적몬스터2.png");
		this->setPosition(ccp(rand() % 200 + 200, 1024));
		pAction = CCMoveBy::create(1.0f, ccp(0, -1024));
	}
	else
	{
		this->initWithFile("적몬스터3.png");
		this->setPosition(ccp(rand() % 200 + 400, 1024));
		pAction = CCMoveBy::create(2.0, ccp(-100, -1024));
	}
	this->runAction(pAction);
	m_pLayer->addChild(this, 2);
	m_bIsDead = true;

	scheduleUpdate();
	m_fCreateTime = 0;	
}

void CMonster::update(float dt)
{
	//!< 총알 생성하는 부분입니다. 시간을 체크해서 0.5초 뒤에 총알이 생성되어있지 않다면 총알을 생성합니다.
	m_fCreateTime += dt;
	if(m_fCreateTime >= 0.5f && pBullet->m_bIsDead == false)
	{
		pBullet->Create(getPosition(), 0.5f, ccp(0, -1024));
	}
	else if(pBullet->m_bIsDead == true)
	{
		m_fCreateTime = 0;
	}

	//!< 화면 벗어나면 삭제!
	if(getPositionY() <= 0)
	{
		m_bIsDead = false;
		m_pLayer->removeChild(this, true);
		unscheduleUpdate();
	}
}