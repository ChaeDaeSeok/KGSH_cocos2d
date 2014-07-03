/**
 * @file	CMonster.h
 * @breif	몬스터 관련된 클래스입니다.
 * @date	2014-07-03
 */

#pragma once

#include "cocos2d.h"
#include "CBullet.h"
USING_NS_CC;

class CMonster : public CCSprite
{
private:
	CCLayer*				m_pLayer;			//!< 씬 Layer를 저장합니다. (AddChild와 RemoveChild 할때 사용합니다.)
		
public:
	bool					m_bIsDead;			//!< 몬스터가 죽었는지 살아있는지 나타내는 변수입니다.

	CBullet					*pBullet;			//!< 몬스터가 1발을 가지고 있어요 그래야 재밋죠
	float					m_fCreateTime;		//!< 얘는 총알만들 딜레이 입니다.

public:
	CMonster(CCLayer *pLayer);						//!< 생성자를 이용하여 씬Layer를 전달받습니다
	~CMonster();									//!< 마지막 Release

	void Create(int type);
	void update(float dt);
};