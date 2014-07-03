#include "HelloWorldScene.h"
#include "AppMacros.h"
USING_NS_CC;


CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

	//!< ĳ���� �ʱ�ȭ
	pHero = new CHero(this);

	//!< ��� �ʱ�ȭ
	pBackground = new CBackground(this);

	//!< ���� �迭�� �ʱ�ȭ ���ݴϴ� �� �ݺ��� ���
	for(int i =0; i < 20; i++)
		pMonster[i] = new CMonster(this);


	//!< �� �Լ��� �θ��� update(float)�� �۵��ؿ� �ε� ĩ
	this->scheduleUpdate();

	//!< �̰Ŵ� �������� ���� ����̿���
	//!< 0.3�ʸ��� 20���� ȣ���մϴ� �ϴ� ��ŸƮ�� 2�ʵڿ� �����ؿ� ��� �ǹ��Դϴ� 
	schedule(schedule_selector(HelloWorld::CreateMonster), 0.3f, 20, 2.0f);
	CreateMonsterCount = 0;

	//!< �� �Լ��� ����� ��ġ�� �����ؿ�
	this->setTouchEnabled(true);
    
    return true;
}

void HelloWorld::update(float dt)
{
	pBackground->ScrollBG(dt);
}

void HelloWorld::CreateMonster(float dt)
{
	//!< ���� 20������ �� ������
	if(CreateMonsterCount >= 20)
	{
		//!< ������ �����մϴ�

		//!< ���� ������ ����
		return;
	}

	//!< 0~20���� ���͸� �����մϴ�. type�� ����(0~2)
	pMonster[CreateMonsterCount++]->Create(rand() % 3);
}

/**
 * @breif	��ġ �ϴ� ������ ȣ��Ǵ� �Լ��Դϴ�.
 * @param	pTouches : ��ġ�� ������ �ֽ��ϴ� CCTouch�� ����ȯ ���Ѽ� ����ؾ��մϴ�.
 * @param	pEvent : ��ġ �̺�Ʈ������ ����ֽ��ϴ�.
 * @return	void
 */
void HelloWorld::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	//!< CCTouch�� ����ȯ �ϴ� �����Դϴ�.
	CCTouch* pTouch = (CCTouch*)pTouches->anyObject();

	//!< ��ġ�� ��ǥ�� ĳ���͸� �̵���ŵ�ϴ�.
	pHero->setPosition(pTouch->getLocation());
}

void HelloWorld::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	//!< CCTouch�� ����ȯ �ϴ� �����Դϴ�.
	CCTouch* pTouch = (CCTouch*)pTouches->anyObject();

	//!< ��ġ�� ��ǥ�� ĳ���͸� �̵���ŵ�ϴ�.
	pHero->setPosition(pTouch->getLocation());
}

void HelloWorld::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	//!< CCTouch�� ����ȯ �ϴ� �����Դϴ�.
	CCTouch* pTouch = (CCTouch*)pTouches->anyObject();

	//!< ��ġ�� ��ǥ�� ĳ���͸� �̵���ŵ�ϴ�.
	pHero->setPosition(pTouch->getLocation());
}