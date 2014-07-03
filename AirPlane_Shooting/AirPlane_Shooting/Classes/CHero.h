/**
 * @file	CHero.h
 * @breif	주인공 캐릭터 관련된 클래스입니다.
 * @date	2014-07-03
 */

#pragma once

#include "cocos2d.h"
#include "CBullet.h"
USING_NS_CC;

class CHero : public CCSprite
{
private:
	CCLayer*				m_pLayer;			//!< 씬 Layer를 저장합니다. (AddChild와 RemoveChild 할때 사용합니다.)
		
public:
	int						m_nLife;			//!< 캐릭터의 HP를 나타냅니다.
	bool					m_bIsDead;			//!< 캐릭터가 죽었는지 살아있는지 나타내는 변수입니다.

	CBullet					*pBullet[20];		//!< 캐릭터가 총알 20발을 가지고 있습니다.

public:
	CHero(CCLayer *pLayer);						//!< 생성자를 이용하여 씬Layer를 전달받습니다
	~CHero();									//!< 마지막 Release

	void Fire(float dt);
};