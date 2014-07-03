#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "AppMacros.h"	//!< 모든 헤더파일을 모아놨어요

class HelloWorld : public cocos2d::CCLayer
{
private:
	//!< 사용자 정의 클래스 입니다.
	CHero			*pHero;
	CMonster		*pMonster[20];
	CBackground		*pBackground;

	int				CreateMonsterCount;

public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

	//!< 터치에 관련된 함수들 CCLayer내부에 virtual로 정의되어 있습니다.
	//!< 가상함수를 오버라이딩해서 사용(모르면 찾아보세요. 네이버 ㄱㄱ -> http://www.naver.com)
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);

	//!< 업데이트 함수입니다.
	void update(float dt);

	void CreateMonster(float dt);

	void CreateEffect(CCPoint pt);
};

#endif // __HELLOWORLD_SCENE_H__
