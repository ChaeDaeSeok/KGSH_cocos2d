/**
 * @file	CHero.h
 * @breif	���ΰ� ĳ���� ���õ� Ŭ�����Դϴ�.
 * @date	2014-07-03
 */

#pragma once

#include "cocos2d.h"
#include "CBullet.h"
USING_NS_CC;

class CHero : public CCSprite
{
private:
	CCLayer*				m_pLayer;			//!< �� Layer�� �����մϴ�. (AddChild�� RemoveChild �Ҷ� ����մϴ�.)
		
public:
	int						m_nLife;			//!< ĳ������ HP�� ��Ÿ���ϴ�.
	bool					m_bIsDead;			//!< ĳ���Ͱ� �׾����� ����ִ��� ��Ÿ���� �����Դϴ�.

	CBullet					*pBullet[20];		//!< ĳ���Ͱ� �Ѿ� 20���� ������ �ֽ��ϴ�.

public:
	CHero(CCLayer *pLayer);						//!< �����ڸ� �̿��Ͽ� ��Layer�� ���޹޽��ϴ�
	~CHero();									//!< ������ Release

	void Fire(float dt);
};