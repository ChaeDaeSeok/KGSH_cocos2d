/**
 * @file	CHero.cpp
 * @breif	주인공 캐릭터 관련된 클래스입니다.
 * @date	2014-07-03
 */
#include "CHero.h"

/**
 * @breif	캐릭터를 초기화 시킵니다.
 * @param	pLayer : 씬에서 CCLayer정보를 가져옵니다.
 * @return	생성자라 없음
 */
CHero::CHero(CCLayer *pLayer)
{
	//!< 캐릭터 정보들 초기화
	m_pLayer				= pLayer;
	m_nLife					= 3;
	m_bIsDead				= true;

	//!< 캐릭터 이미지 로드
	this->initWithFile("주인공캐릭터.png");
	
	//!< 캐릭터의 중점을 정 가운데로 설정
	this->setAnchorPoint(ccp(0.5f, 0.5f));

	//!< 화면의 X축은 가운데 세로축은 2/3지점에 캐릭터를 배치합니다. 해상도 관련은 AppDelegate.cpp 참고
	this->setPosition(ccp(768 / 2, 1024 / 3));

	//!< 캐릭터가 너무 작아서 키웁니다. (2배)
	this->setScale(2.0f);

	//!< 씬에서 가져온 Layer(종이) 안에다가 Hero라는 Sprite(상속받았음)라는 그림을 그려줍니다.
	//!< addchild안하면 그림이 안나와요 ㅠ_ㅠ
	//!< 숫자는 레이어 순서에요 높을수록 앞에 나와요 0은 배경으로 쓸꺼임
	pLayer->addChild(this, 1);

	//!< 배열이기 때문에 for을 이용하여 초기화 해줍니다. << 이거 까먹지마세요 왜 반복문을 쓰는지 모르는 사람이 많네요.
	for(int i = 0; i < 20; i++)
		pBullet[i] = new CBullet(pLayer);	//!< 여기서는 this가 Sprite기 때문에 안들어갑니다 CCLayer인 pLayer나 m_pLayer를 넘겨주세요

	schedule(schedule_selector(CHero::Fire), 0.15f);	//!< 스케쥴을 꼭 CCLayer에서만 사용이 가능한건 아닙니다. 다만 CHero:: << 요 부분은 현재 사용하는 클래스와 맞춰주세요
}

CHero::~CHero()
{
	//!< 마지막으로 메모리 해제를 해줍니다.
	release();	//!< 이건 Hero 스프라이트

	for(int i = 0; i < 20; i++)	//!< 요건 총알 new해준거 delete하는거에요
		delete pBullet[i];	
}

void CHero::Fire(float dt)
{
	//!< 일단 캐릭터가 살아있는지 아닌지 체크합니다.
	if(m_bIsDead)
	{
		//!< 살아있다면 총알을 발사해요
		for(int i = 0; i < 20; i++)
		{
			if(pBullet[i]->m_bIsDead == false)	//!< 총알이 생성되어 있지 않다면요
			{
				pBullet[i]->Create(getPosition(), 1.0f, ccp(0, 1024));	//!< 총알을 생성해줍니다. 인자값으로 캐릭터 좌표와 MoveBy기준으로 날라갈 좌표입니다.
				break;	//!< 총알을 1개 생성해줬으니 또 생성하면 안되니 break를 시킵니다.
			}
		}
	}
	else	//!< 죽어있으면 스케쥴을 꺼버려요
	{
		unschedule(schedule_selector(CHero::Fire));
	}
}