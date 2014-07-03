/**
 * @file	CBullet.cpp
 * @breif	총알 관련된 클래스입니다.
 * @date	2014-07-03
 */
#include "CBullet.h"

/**
 * @breif	캐릭터를 초기화 시킵니다.
 * @param	pLayer : 씬에서 CCLayer정보를 가져옵니다.
 * @return	생성자라 없음
 */
CBullet::CBullet(CCLayer *pLayer)
{
	//!< 캐릭터 정보들 초기화
	m_pLayer				= pLayer;
	m_bIsDead				= false;

	//!< 캐릭터 이미지 로드
	this->initWithFile("주인공미사일.png");
	
	//!< 캐릭터의 중점을 정 가운데 아래로 설정
	this->setAnchorPoint(ccp(0.5f, 0.0f));

	//!< 화면의 X축은 가운데 세로축은 2/3지점에 캐릭터를 배치합니다. 해상도 관련은 AppDelegate.cpp 참고
	this->setPosition(ccp(768 / 2, 1024 / 3));

	//!< 너무 작아서 키웁니다. (2배)
	this->setScale(2.0f);
}

CBullet::~CBullet()
{
	//!< 마지막으로 메모리 해제를 해줍니다.
	release();
}

/**
 * @breif	총알을 만들어 줍니다.
 * @param	Pt : 총알의 좌표입니다.
 * @param	MoveDirection : 총알이 가야 할 곳입니다.
 * @return	void
 */
void CBullet::Create(CCPoint Pt, float fDuration, CCPoint MoveDirection)
{
	//!< 총알을 만들어줍니다.
	m_bIsDead = true;

	//!< 좌표 설정해주구요
	setPosition(Pt);

	//!< 그림을 띄워줍니다.
	m_pLayer->addChild(this, 1);

	//!< 발사!
	CCAction *pAction = CCMoveBy::create(fDuration, MoveDirection);
	runAction(pAction);

	//!< 화면 밖으로 벗어나는지 체크해야죠 이제
	scheduleUpdate();
}

/**
 * @breif	총알이 화면밖을 나가는걸 체크해줍니다.
 * @param	dt : deltatime
 * @return	void
 */
void CBullet::update(float dt)
{
	//!< 화면 위나 아래로 벗어나면은요 킥 하고 죽여버려요
	if(getPositionY() <= 0 || getPositionY() >= 1024)
	{
		m_bIsDead = false; 
		m_pLayer->removeChild(this, true);

		unscheduleUpdate();	//!< 그리고 update를 꺼줍니다.
	}
}