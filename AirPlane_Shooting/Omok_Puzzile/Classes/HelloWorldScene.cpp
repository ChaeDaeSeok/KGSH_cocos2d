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
   
	CCSprite *pBoard = CCSprite::create("Board.png");
	pBoard->setPosition(ccp(0, 0));
	pBoard->setAnchorPoint(ccp(0, 0));
	this->addChild(pBoard, 0);

	memset(Board, 0, sizeof(Board));

	bTurn = true;
	bIsGaming = true;
	this->setTouchEnabled(true);

    return true;
}

void HelloWorld::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	if(bIsGaming == false)
		return;
	CCTouch *pTouch = (CCTouch*)pTouches->anyObject();

	int Xindex = (pTouch->getLocation().x + 20) / 40;
	int Yindex = (800 - pTouch->getLocation().y + 20) / 40;

	if(Board[Yindex][Xindex] == 0)
	{
		CStone *pStone = new CStone(this, ccp(Xindex * 40, 800 - (Yindex * 40)), bTurn);
		Board[Yindex][Xindex] = (bTurn == true) ? 1 : 2;

		//!< ���� üũ �����Դϴ�.
		int TempX;
		int TempY;
		int Count;

		//!< ù��° ���� üũ�Դϴ�.
		TempX = Xindex;
		Count = 0;
		while(Board[Yindex][--TempX] == Board[Yindex][Xindex]);	//!< ���� ��ǥ�� <<���� �������� ��� ���ϴ� ���� �������
		while(Board[Yindex][++TempX] == Board[Yindex][Xindex])	//!< ������ ���� �̵��� ���� �κк��� ���������� �̵��մϴ� �̵��ϸ鼭 ��ĭ �̵��ϴ��� ī��Ʈ�� �մϴ�.
			Count++;
		if(Count == 5)	//!< ī��Ʈ�� 5��� �Ȱ��� ���� �������� 5���� �ִٴ� �Ҹ��Դϴ�.
		{
			bIsGaming = false;
			//!< ��
		}

		//!< �ι�° ���� üũ�Դϴ�.
		TempY = Yindex;
		Count = 0;
		while(Board[--TempY][Xindex] == Board[Yindex][Xindex]);	//!< ���� ��ǥ�� ���� �������� ��� ���ϴ� ���� �������
		while(Board[++TempY][Xindex] == Board[Yindex][Xindex])	//!< ������ ���� �̵��� ���� �κк��� �Ʒ������� �̵��մϴ� �̵��ϸ鼭 ��ĭ �̵��ϴ��� ī��Ʈ�� �մϴ�.
			Count++;
		if(Count == 5)	//!< ī��Ʈ�� 5��� �Ȱ��� ���� �������� 5���� �ִٴ� �Ҹ��Դϴ�.
		{
			bIsGaming = false;
			//!< ��
		}

		//!< ����° �밢�� / üũ�Դϴ�.
		TempX = Xindex;
		TempY = Yindex;
		Count = 0;
		while(Board[--TempY][++TempX] == Board[Yindex][Xindex]);	
		while(Board[++TempY][--TempX] == Board[Yindex][Xindex])		
			Count++;
		if(Count == 5)	//!< ī��Ʈ�� 5��� �Ȱ��� ���� �������� 5���� �ִٴ� �Ҹ��Դϴ�.
		{
			bIsGaming = false;
			//!< ��
		}

		//!< �׹�° �밢�� \ üũ�Դϴ�.
		TempX = Xindex;
		TempY = Yindex;
		Count = 0;
		while(Board[--TempY][--TempX] == Board[Yindex][Xindex]);	
		while(Board[++TempY][++TempX] == Board[Yindex][Xindex])		
			Count++;
		if(Count == 5)	//!< ī��Ʈ�� 5��� �Ȱ��� ���� �������� 5���� �ִٴ� �Ҹ��Դϴ�.
		{
			bIsGaming = false;
			//!< ��
		}
		
		if(bIsGaming == false)
		{
			CCMessageBox((bTurn == true) ? "���� �̰���ϴ�." : "ȭ��Ʈ�� �̰���ϴ�.", "���");
		}
		bTurn = !bTurn; //!< �ºΰ� �ȳ��ٸ� ���� �����մϴ�.
	}
}