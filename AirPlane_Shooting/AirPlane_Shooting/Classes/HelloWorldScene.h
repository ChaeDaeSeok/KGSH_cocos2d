#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "AppMacros.h"	//!< ��� ��������� ��Ƴ����

class HelloWorld : public cocos2d::CCLayer
{
private:
	//!< ����� ���� Ŭ���� �Դϴ�.
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

	//!< ��ġ�� ���õ� �Լ��� CCLayer���ο� virtual�� ���ǵǾ� �ֽ��ϴ�.
	//!< �����Լ��� �������̵��ؼ� ���(�𸣸� ã�ƺ�����. ���̹� ���� -> http://www.naver.com)
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);

	//!< ������Ʈ �Լ��Դϴ�.
	void update(float dt);

	void CreateMonster(float dt);
};

#endif // __HELLOWORLD_SCENE_H__