/**
 * @file	CBackground.h
 * @breif	���ΰ� ĳ���� ���õ� Ŭ�����Դϴ�.
 * @date	2014-07-03
 */

#pragma once

#include "cocos2d.h"
USING_NS_CC;

//!< ��� CCSprite�� ��� �ȹ޾ƿ� �ֳĸ� �̹����� 2�� �����ŵ��
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