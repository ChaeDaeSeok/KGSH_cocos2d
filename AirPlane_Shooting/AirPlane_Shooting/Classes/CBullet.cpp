/**
 * @file	CBullet.cpp
 * @breif	�Ѿ� ���õ� Ŭ�����Դϴ�.
 * @date	2014-07-03
 */
#include "CBullet.h"

/**
 * @breif	ĳ���͸� �ʱ�ȭ ��ŵ�ϴ�.
 * @param	pLayer : ������ CCLayer������ �����ɴϴ�.
 * @return	�����ڶ� ����
 */
CBullet::CBullet(CCLayer *pLayer)
{
	//!< ĳ���� ������ �ʱ�ȭ
	m_pLayer				= pLayer;
	m_bIsDead				= false;

	//!< ĳ���� �̹��� �ε�
	this->initWithFile("���ΰ��̻���.png");
	
	//!< ĳ������ ������ �� ��� �Ʒ��� ����
	this->setAnchorPoint(ccp(0.5f, 0.0f));

	//!< ȭ���� X���� ��� �������� 2/3������ ĳ���͸� ��ġ�մϴ�. �ػ� ������ AppDelegate.cpp ����
	this->setPosition(ccp(768 / 2, 1024 / 3));

	//!< �ʹ� �۾Ƽ� Ű��ϴ�. (2��)
	this->setScale(2.0f);
}

CBullet::~CBullet()
{
	//!< ���������� �޸� ������ ���ݴϴ�.
	release();
}

/**
 * @breif	�Ѿ��� ����� �ݴϴ�.
 * @param	Pt : �Ѿ��� ��ǥ�Դϴ�.
 * @param	MoveDirection : �Ѿ��� ���� �� ���Դϴ�.
 * @return	void
 */
void CBullet::Create(CCPoint Pt, float fDuration, CCPoint MoveDirection)
{
	//!< �Ѿ��� ������ݴϴ�.
	m_bIsDead = true;

	//!< ��ǥ �������ֱ���
	setPosition(Pt);

	//!< �׸��� ����ݴϴ�.
	m_pLayer->addChild(this, 1);

	//!< �߻�!
	CCAction *pAction = CCMoveBy::create(fDuration, MoveDirection);
	runAction(pAction);

	//!< ȭ�� ������ ������� üũ�ؾ��� ����
	scheduleUpdate();
}

/**
 * @breif	�Ѿ��� ȭ����� �����°� üũ���ݴϴ�.
 * @param	dt : deltatime
 * @return	void
 */
void CBullet::update(float dt)
{
	//!< ȭ�� ���� �Ʒ��� ��������� ű �ϰ� �׿�������
	if(getPositionY() <= 0 || getPositionY() >= 1024)
	{
		m_bIsDead = false; 
		m_pLayer->removeChild(this, true);

		unscheduleUpdate();	//!< �׸��� update�� ���ݴϴ�.
	}
}