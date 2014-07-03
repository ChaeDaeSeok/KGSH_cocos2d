/**
 * @file	CBullet.h
 * @breif	�Ѿ� ���õ� Ŭ�����Դϴ�.
 * @date	2014-07-03
 */

#pragma once

#include "cocos2d.h"
USING_NS_CC;

class CBullet : public CCSprite
{
private:
	CCLayer*				m_pLayer;	//!< �� Layer�� �����մϴ�. (AddChild�� RemoveChild �Ҷ� ����մϴ�.)
		
public:
	bool					m_bIsDead;	//!< �Ѿ��� �׾����� ����ִ��� ��Ÿ���� �����Դϴ�.

public:
	CBullet(CCLayer *pLayer);			//!< �����ڸ� �̿��Ͽ� ��Layer�� ���޹޽��ϴ�
	~CBullet();							//!< ������ Release

	void Create(CCPoint Pt, float fDuration, CCPoint MoveDirection);	//!< �Ѿ��� ������ִ� �Լ��Դϴ�.

	void update(float dt);
};