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

		//!< 오목 체크 공식입니다.
		int TempX;
		int TempY;
		int Count;

		//!< 첫번째 가로 체크입니다.
		TempX = Xindex;
		Count = 0;
		while(Board[Yindex][--TempX] == Board[Yindex][Xindex]);	//!< 현재 좌표와 <<왼쪽 방향으로 계속 갑니다 색이 같으면요
		while(Board[Yindex][++TempX] == Board[Yindex][Xindex])	//!< 이제는 왼쪽 이동이 끝난 부분부터 오른쪽으로 이동합니다 이동하면서 몇칸 이동하는지 카운트를 합니다.
			Count++;
		if(Count == 5)	//!< 카운트가 5라면 똑같은 색이 연속으로 5개가 있다는 소리입니다.
		{
			bIsGaming = false;
			//!< 끝
		}

		//!< 두번째 세로 체크입니다.
		TempY = Yindex;
		Count = 0;
		while(Board[--TempY][Xindex] == Board[Yindex][Xindex]);	//!< 현재 좌표와 위쪽 방향으로 계속 갑니다 색이 같으면요
		while(Board[++TempY][Xindex] == Board[Yindex][Xindex])	//!< 이제는 위쪽 이동이 끝난 부분부터 아래쪽으로 이동합니다 이동하면서 몇칸 이동하는지 카운트를 합니다.
			Count++;
		if(Count == 5)	//!< 카운트가 5라면 똑같은 색이 연속으로 5개가 있다는 소리입니다.
		{
			bIsGaming = false;
			//!< 끝
		}

		//!< 세번째 대각선 / 체크입니다.
		TempX = Xindex;
		TempY = Yindex;
		Count = 0;
		while(Board[--TempY][++TempX] == Board[Yindex][Xindex]);	
		while(Board[++TempY][--TempX] == Board[Yindex][Xindex])		
			Count++;
		if(Count == 5)	//!< 카운트가 5라면 똑같은 색이 연속으로 5개가 있다는 소리입니다.
		{
			bIsGaming = false;
			//!< 끝
		}

		//!< 네번째 대각선 \ 체크입니다.
		TempX = Xindex;
		TempY = Yindex;
		Count = 0;
		while(Board[--TempY][--TempX] == Board[Yindex][Xindex]);	
		while(Board[++TempY][++TempX] == Board[Yindex][Xindex])		
			Count++;
		if(Count == 5)	//!< 카운트가 5라면 똑같은 색이 연속으로 5개가 있다는 소리입니다.
		{
			bIsGaming = false;
			//!< 끝
		}
		
		if(bIsGaming == false)
		{
			CCMessageBox((bTurn == true) ? "블랙이 이겼습니다." : "화이트가 이겼습니다.", "결과");
		}
		bTurn = !bTurn; //!< 승부가 안났다면 턴을 변경합니다.
	}
}