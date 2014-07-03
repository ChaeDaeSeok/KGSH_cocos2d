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

	//!< 캐릭터 초기화
	pHero = new CHero(this);

	//!< 배경 초기화
	pBackground = new CBackground(this);

	//!< 몬스터 배열을 초기화 해줍니다 꼭 반복문 사용
	for(int i =0; i < 20; i++)
		pMonster[i] = new CMonster(this);


	//!< 이 함수를 부르면 update(float)이 작동해요 두둥 칫
	this->scheduleUpdate();

	//!< 이거는 스케줄을 쓰는 방법이에요
	//!< 0.3초마다 20번을 호출합니다 일단 스타트는 2초뒤에 시작해요 라는 의미입니다 
	schedule(schedule_selector(HelloWorld::CreateMonster), 0.3f, 20, 2.0f);
	CreateMonsterCount = 0;

	//!< 이 함수를 써줘야 터치가 가능해요
	this->setTouchEnabled(true);
    
    return true;
}

void HelloWorld::update(float dt)
{
	pBackground->ScrollBG(dt);

	for(int i = 0; i < 20; i++)
	{
		if(pHero->getColBulletVSMonster(pMonster[i]))
			CreateEffect(pMonster[i]->getPosition());
	}
}

void HelloWorld::CreateMonster(float dt)
{
	//!< 몬스터 20마리가 다 나오면
	if(CreateMonsterCount >= 20)
	{
		//!< 보스를 생성합니다

		//!< 보스 생성후 종료
		return;
	}

	//!< 0~20까지 몬스터를 생성합니다. type은 랜덤(0~2)
	pMonster[CreateMonsterCount++]->Create(rand() % 3);
}

void HelloWorld::CreateEffect(CCPoint pt)
{
	 //< 모든그림이있는 스프라이트 큰 그림을먼저만든다.
	CCSprite* pMan = CCSprite::create("효과이미지/dust.png");
	pMan->setPosition(pt);
	pMan->setScale(2.0f);

	//< 애니메이션에 사용할 애니메이션 객체 생성
	CCAnimation* pAnimation = CCAnimation::create();
	pAnimation->addSpriteFrameWithFileName("효과이미지/dust.png");
	pAnimation->addSpriteFrameWithFileName("효과이미지/dust_02.png");
	pAnimation->addSpriteFrameWithFileName("효과이미지/dust_03.png");
	pAnimation->addSpriteFrameWithFileName("효과이미지/explosion_01.png");

	//< 애니메이션의 시간간격을 설정(몇초마다 스프라이트이미지가 교체될지)
	pAnimation->setDelayPerUnit(0.1f);
	pAnimation->setRestoreOriginalFrame(true);

	//< 디스크립터 객체를가지고 애니메이션을만듬
	CCAnimate* Animate1 = CCAnimate::create(pAnimation);
	CCCallFuncND*	removeAction = CCCallFuncND::create(this, callfuncND_selector(CCNode::removeChild), Animate1);

	CCFiniteTimeAction *action = CCSequence::create(Animate1, removeAction, NULL);

	//< 스프라이트 애니메이션 실행
	this->addChild(pMan, 2);
	pMan->runAction(action);
}

/**
 * @breif	터치 하는 시점에 호출되는 함수입니다.
 * @param	pTouches : 터치한 정보가 있습니다 CCTouch로 형변환 시켜서 사용해야합니다.
 * @param	pEvent : 터치 이벤트정보가 담겨있습니다.
 * @return	void
 */
void HelloWorld::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	//!< CCTouch로 형변환 하는 과정입니다.
	CCTouch* pTouch = (CCTouch*)pTouches->anyObject();

	//!< 터치한 좌표로 캐릭터를 이동시킵니다.
	pHero->setPosition(pTouch->getLocation());
}

void HelloWorld::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	//!< CCTouch로 형변환 하는 과정입니다.
	CCTouch* pTouch = (CCTouch*)pTouches->anyObject();

	//!< 터치한 좌표로 캐릭터를 이동시킵니다.
	pHero->setPosition(pTouch->getLocation());
}

void HelloWorld::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	//!< CCTouch로 형변환 하는 과정입니다.
	CCTouch* pTouch = (CCTouch*)pTouches->anyObject();

	//!< 터치한 좌표로 캐릭터를 이동시킵니다.
	pHero->setPosition(pTouch->getLocation());
}