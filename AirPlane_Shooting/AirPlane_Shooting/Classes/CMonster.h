/**
 * @file	CMonster.h
 * @breif	���� ���õ� Ŭ�����Դϴ�.
 * @date	2014-07-03
 */

#pragma once

#include "cocos2d.h"
#include "CBullet.h"
USING_NS_CC;

class CMonster : public CCSprite
{
private:
	CCLayer*				m_pLayer;			//!< �� Layer�� �����մϴ�. (AddChild�� RemoveChild �Ҷ� ����մϴ�.)
		
public:
	bool					m_bIsDead;			//!< ���Ͱ� �׾����� ����ִ��� ��Ÿ���� �����Դϴ�.

	CBullet					*pBullet;			//!< ���Ͱ� 1���� ������ �־�� �׷��� �����
	float					m_fCreateTime;		//!< ��� �Ѿ˸��� ������ �Դϴ�.

public:
	CMonster(CCLayer *pLayer);						//!< �����ڸ� �̿��Ͽ� ��Layer�� ���޹޽��ϴ�
	~CMonster();									//!< ������ Release

	void Create(int type);
	void update(float dt);
};