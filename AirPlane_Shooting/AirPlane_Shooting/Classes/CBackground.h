/**
 * @file	CBackground.h
 * @breif	주인공 캐릭터 관련된 클래스입니다.
 * @date	2014-07-03
 */

#pragma once

#include "cocos2d.h"
USING_NS_CC;

//!< 얘는 CCSprite를 상속 안받아요 왜냐면 이미지를 2개 쓸꺼거든요
class CBackground
{
private:
	CCSprite		*pBG1;
	CCSprite		*pBG2;

public:
	CBackground(CCLayer *pLayer);
	~CBackground();

	void ScrollBG(float dt);
};