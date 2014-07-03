#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CStone.h"
USING_NS_CC;

class HelloWorld : public cocos2d::CCLayer
{
	int Board[19][19];
	bool bTurn;

	bool bIsGaming;
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
};

#endif // __HELLOWORLD_SCENE_H__
