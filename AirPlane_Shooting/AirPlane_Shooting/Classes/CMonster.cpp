/**
 * @file	CMonster.cpp
 * @breif	���� ���õ� Ŭ�����Դϴ�.
 * @date	2014-07-03
 */
#include "CMonster.h"

/**
 * @breif	���͸� �ʱ�ȭ ��ŵ�ϴ�.
 * @param	pLayer : ������ CCLayer������ �����ɴϴ�.
 * @return	�����ڶ� ����
 */
CMonster::CMonster(CCLayer *pLayer)
{
	//!< ���� ������ �ʱ�ȭ
	m_pLayer				= pLayer;
	m_bIsDead				= false;

	//!< ���� �̹��� �ε�
	this->initWithFile("������1.png");
	
	//!< ���� ������ �� ����� ����
	this->setAnchorPoint(ccp(0.5f, 0.5f));

	//!< ĳ���Ͱ� �ʹ� �۾Ƽ� Ű��ϴ�. (2��)
	this->setScale(2.0f);

	pBullet = new CBullet(pLayer);	//!< ���⼭�� this�� Sprite�� ������ �ȵ��ϴ� CCLayer�� pLayer�� m_pLayer�� �Ѱ��ּ���
}

CMonster::~CMonster()
{
	//!< ���������� �޸� ������ ���ݴϴ�.
	release();	//!< �̰� Hero ��������Ʈ

	delete pBullet;	
}

void CMonster::Create(int type)
{
	//!< type���� ���� ���͸� �����ϴ� ����Դϴ�.
	CCAction* pAction;
	if(type == 1)
	{
		this->initWithFile("������1.png");
		this->setPosition(ccp(rand() % 200, 1024));
		pAction = CCMoveBy::create(2.0f, ccp(100, -1024));
	}
	else if(type == 2)
	{
		this->initWithFile("������2.png");
		this->setPosition(ccp(rand() % 200 + 200, 1024));
		pAction = CCMoveBy::create(1.0f, ccp(0, -1024));
	}
	else
	{
		this->initWithFile("������3.png");
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
	//!< �Ѿ� �����ϴ� �κ��Դϴ�. �ð��� üũ�ؼ� 0.5�� �ڿ� �Ѿ��� �����Ǿ����� �ʴٸ� �Ѿ��� �����մϴ�.
	m_fCreateTime += dt;
	if(m_fCreateTime >= 0.5f && pBullet->m_bIsDead == false)
	{
		pBullet->Create(getPosition(), 0.5f, ccp(0, -1024));
	}
	else if(pBullet->m_bIsDead == true)
	{
		m_fCreateTime = 0;
	}

	//!< ȭ�� ����� ����!
	if(getPositionY() <= 0)
	{
		m_bIsDead = false;
		m_pLayer->removeChild(this, true);
		unscheduleUpdate();
	}
}