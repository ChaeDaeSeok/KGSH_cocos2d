/**
 * @file	CBackground.cpp
 * @breif	배경 관련된 클래스입니다.
 * @date	2014-07-03
 */
#include "CBackground.h"

CBackground::CBackground(CCLayer *pLayer)
{
	//!< 배경 이미지 초기화 하는 과정입니다.
	//!< 왜 이렇게 했는지 옆에 주석을 달아보세요
	pBG1 = new CCSprite();
	pBG1->initWithFile("배경이미지/01.png");
	pBG1->setAnchorPoint(ccp(0, 0));
	pBG1->setPosition(ccp(0, 0));
	pLayer->addChild(pBG1, 0);
	
	pBG2 = new CCSprite();
	pBG2->initWithFile("배경이미지/01.png");
	pBG2->setAnchorPoint(ccp(0, 0));
	pBG2->setPosition(ccp(0, 1024));
	pLayer->addChild(pBG2, 0);
}


CBackground::~CBackground()
{
	pBG1->release();
	pBG2->release();
}

//!< HelloWorldScene에서 스케쥴로 호출해줍니다.
void CBackground::ScrollBG(float dt)
{
	int MoveSpeed = 10;	//!< 빠르다 싶으면 이거를 줄여요

	pBG1->setPositionY(pBG1->getPositionY() - MoveSpeed );
	pBG2->setPositionY(pBG2->getPositionY() - MoveSpeed );

	if(pBG1->getPositionY() <= -1024)
		pBG1->setPositionY(pBG2->getPositionY() + 1024);
	if(pBG2->getPositionY() <= -1024)
		pBG2->setPositionY(pBG1->getPositionY() + 1024);
}