#include "HelloWorldScene.h"
#include "playScene.h"
#include "SimpleAudioEngine.h"


#define MUSIC_FILE "KAISER PHOENIX.mp3"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {        
        CC_BREAK_IF(! CCLayerColor::initWithColor(ccc4(255, 255, 255, 255)));
		CCSprite* main_scene =CCSprite::create("main2(768x1024).jpg");
		//main_scene->setTextureRect(CCRectMake(0, 0, 768, 1024)) ;
		CCSprite *start = CCSprite::create("Start.png");
		CCAnimation* blink = CCAnimation::create();
		blink->addSpriteFrameWithFileName("Start.png");
		blink->addSpriteFrameWithFileName("Start2b.png");
		blink->setDelayPerUnit(0.5);
		CCAnimate* blinkk = CCAnimate::create(blink);
		CCAction* rep = CCRepeatForever::create(blinkk);

		main_scene -> setPosition(ccp(384,512));
		start -> setPosition(ccp(384,400));
		
		this -> addChild(main_scene);
		this -> addChild(start);
		this->setTouchEnabled(true);
		start -> runAction(rep);

        bRet = true;
    } while (0);
	
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(MUSIC_FILE) ;

    return bRet;
}

// ��� ����
void HelloWorld::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
	CCScene* pScene = playScene::scene() ;
	CCDirector::sharedDirector() -> pushScene(pScene) ;	
}