#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"



//class HelloWorld : public cocos2d::CCLayer
class HelloWorld : public cocos2d::CCLayerColor
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

	unsigned int m_nSoundId ;
		

	void doSoundAction(CCObject* pSender) ;
	void doClick1(CCObject* pSender) ;
	void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event) ;
	
};

#endif  // __HELLOWORLD_SCENE_H__