/**
 * @file	CHero.cpp
 * @breif	���ΰ� ĳ���� ���õ� Ŭ�����Դϴ�.
 * @date	2014-07-03
 */
#include "CHero.h"

/**
 * @breif	ĳ���͸� �ʱ�ȭ ��ŵ�ϴ�.
 * @param	pLayer : ������ CCLayer������ �����ɴϴ�.
 * @return	�����ڶ� ����
 */
CHero::CHero(CCLayer *pLayer)
{
	//!< ĳ���� ������ �ʱ�ȭ
	m_pLayer				= pLayer;
	m_nLife					= 3;
	m_bIsDead				= true;

	//!< ĳ���� �̹��� �ε�
	this->initWithFile("���ΰ�ĳ����.png");
	
	//!< ĳ������ ������ �� ����� ����
	this->setAnchorPoint(ccp(0.5f, 0.5f));

	//!< ȭ���� X���� ��� �������� 2/3������ ĳ���͸� ��ġ�մϴ�. �ػ� ������ AppDelegate.cpp ����
	this->setPosition(ccp(768 / 2, 1024 / 3));

	//!< ĳ���Ͱ� �ʹ� �۾Ƽ� Ű��ϴ�. (2��)
	this->setScale(2.0f);

	//!< ������ ������ Layer(����) �ȿ��ٰ� Hero��� Sprite(��ӹ޾���)��� �׸��� �׷��ݴϴ�.
	//!< addchild���ϸ� �׸��� �ȳ��Ϳ� ��_��
	//!< ���ڴ� ���̾� �������� �������� �տ� ���Ϳ� 0�� ������� ������
	pLayer->addChild(this, 1);

	//!< �迭�̱� ������ for�� �̿��Ͽ� �ʱ�ȭ ���ݴϴ�. << �̰� ����������� �� �ݺ����� ������ �𸣴� ����� ���׿�.
	for(int i = 0; i < 20; i++)
		pBullet[i] = new CBullet(pLayer);	//!< ���⼭�� this�� Sprite�� ������ �ȵ��ϴ� CCLayer�� pLayer�� m_pLayer�� �Ѱ��ּ���

	schedule(schedule_selector(CHero::Fire), 0.15f);	//!< �������� �� CCLayer������ ����� �����Ѱ� �ƴմϴ�. �ٸ� CHero:: << �� �κ��� ���� ����ϴ� Ŭ������ �����ּ���
}

CHero::~CHero()
{
	//!< ���������� �޸� ������ ���ݴϴ�.
	release();	//!< �̰� Hero ��������Ʈ

	for(int i = 0; i < 20; i++)	//!< ��� �Ѿ� new���ذ� delete�ϴ°ſ���
		delete pBullet[i];	
}

void CHero::Fire(float dt)
{
	//!< �ϴ� ĳ���Ͱ� ����ִ��� �ƴ��� üũ�մϴ�.
	if(m_bIsDead)
	{
		//!< ����ִٸ� �Ѿ��� �߻��ؿ�
		for(int i = 0; i < 20; i++)
		{
			if(pBullet[i]->m_bIsDead == false)	//!< �Ѿ��� �����Ǿ� ���� �ʴٸ��
			{
				pBullet[i]->Create(getPosition(), 1.0f, ccp(0, 1024));	//!< �Ѿ��� �������ݴϴ�. ���ڰ����� ĳ���� ��ǥ�� MoveBy�������� ���� ��ǥ�Դϴ�.
				break;	//!< �Ѿ��� 1�� ������������ �� �����ϸ� �ȵǴ� break�� ��ŵ�ϴ�.
			}
		}
	}
	else	//!< �׾������� �������� ��������
	{
		unschedule(schedule_selector(CHero::Fire));
	}
}