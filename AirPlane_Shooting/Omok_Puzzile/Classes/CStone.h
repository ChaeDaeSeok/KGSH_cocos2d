/**
 * @file	CStone.h
 * @breif	�ٵϾ� ���� Ŭ�����Դϴ�.
 * @date	2014-07-03
 */

#pragma once

#include "cocos2d.h"
USING_NS_CC;

class CStone : public CCSprite
{
public:
	CStone(CCLayer *pLayer, CCPoint pt, bool IsBlack)
	{
		if(IsBlack)
			initWithFile("Black.png");
		else
			initWithFile("White.png");

		setPosition(pt);
		pLayer->addChild(this);
	}

	~CStone()
	{
		release();
	}
};