/**
 * @file	CBackground.cpp
 * @breif	��� ���õ� Ŭ�����Դϴ�.
 * @date	2014-07-03
 */
#include "CBackground.h"

CBackground::CBackground(CCLayer *pLayer)
{
	//!< ��� �̹��� �ʱ�ȭ �ϴ� �����Դϴ�.
	//!< �� �̷��� �ߴ��� ���� �ּ��� �޾ƺ�����
	pBG1 = new CCSprite();
	pBG1->initWithFile("����̹���/01.png");
	pBG1->setAnchorPoint(ccp(0, 0));
	pBG1->setPosition(ccp(0, 0));
	pLayer->addChild(pBG1, 0);
	
	pBG2 = new CCSprite();
	pBG2->initWithFile("����̹���/01.png");
	pBG2->setAnchorPoint(ccp(0, 0));
	pBG2->setPosition(ccp(0, 1024));
	pLayer->addChild(pBG2, 0);
}


CBackground::~CBackground()
{
	pBG1->release();
	pBG2->release();
}

//!< HelloWorldScene���� ������� ȣ�����ݴϴ�.
void CBackground::ScrollBG(float dt)
{
	int MoveSpeed = 10;	//!< ������ ������ �̰Ÿ� �ٿ���

	pBG1->setPositionY(pBG1->getPositionY() - MoveSpeed );
	pBG2->setPositionY(pBG2->getPositionY() - MoveSpeed );

	if(pBG1->getPositionY() <= -1024)
		pBG1->setPositionY(pBG2->getPositionY() + 1024);
	if(pBG2->getPositionY() <= -1024)
		pBG2->setPositionY(pBG1->getPositionY() + 1024);
}