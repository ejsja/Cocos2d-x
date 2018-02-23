#ifndef __CHOICE_SCENE_H__
#define __CHOICE_SCENE_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

//class HelloWorld : public cocos2d::CCLayer
class choice : public cocos2d::CCLayerColor
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    //void menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(choice);

	//void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);//터치이벤트
	void close(CCObject* pSender);
	virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent* event);
	//void click1(CCObject* pSender);

	//void readFile();
};

#endif  // __CHOICE_SCENE_H__