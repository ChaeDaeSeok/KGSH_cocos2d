/**
 * @file	CBullet.h
 * @breif	총알 관련된 클래스입니다.
 * @date	2014-07-03
 */

#pragma once

#include "cocos2d.h"
USING_NS_CC;

class CBullet : public CCSprite
{
private:
	CCLayer*				m_pLayer;	//!< 씬 Layer를 저장합니다. (AddChild와 RemoveChild 할때 사용합니다.)
		
public:
	bool					m_bIsDead;	//!< 총알이 죽었는지 살아있는지 나타내는 변수입니다.

public:
	CBullet(CCLayer *pLayer);			//!< 생성자를 이용하여 씬Layer를 전달받습니다
	~CBullet();							//!< 마지막 Release

	void Create(CCPoint Pt, float fDuration, CCPoint MoveDirection);	//!< 총알을 만들어주는 함수입니다.

	void update(float dt);
};