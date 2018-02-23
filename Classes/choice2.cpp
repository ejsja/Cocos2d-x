#include "choice.h"
#include "choice2.h"
#include "playScene.h"
#include "result.h"
#include "SimpleAudioEngine.h"

#define MUSIC_FILE0 "albida (sample).mp3"
#define MUSIC_FILE1 "KAISER PHOENIX (sample).mp3"
#define MUSIC_FILE2 "chronos (sample).mp3"
#define MUSIC_FILE3 "area51 (sample).mp3"
#define MUSIC_FILE4 "concon (sample).mp3"
#define MUSIC_FILE5 "evansama (sample).mp3"
#define MUSIC_FILE6 "Macuilxochitl (sample).mp3"
#define MUSIC_FILE7 "natsumatsuri (sample).mp3"
#define MUSIC_FILE8 "sayonaratrip (sample).mp3"
#define MUSIC_FILE9 "alstromeria (sample).mp3"
#define MUSIC_FILE10 "over there (sample).mp3"
#define MUSIC_FILE11 "The Least 100sec (sample).mp3"


using namespace cocos2d;
using namespace CocosDenshion ;

int s_flag ;

CCScene* choice2::scene(int flag)
{
    CCScene *scene = CCScene::create();
    
    choice2 *layer = choice2::create();
    
    scene->addChild(layer);
    s_flag = flag ;
    return scene;
}

bool choice2::init()
{
    if ( !CCLayerColor::initWithColor(ccc4(255, 255, 255, 0)) )
    {
        return false;
    }
		     
    winSize = CCDirector::sharedDirector() -> getWinSize() ;
    
    // 팝업창 구성용 레이어 추가
	CCSprite* s_music ;

	if(s_flag == 0)
	{
		s_music = CCSprite::create("albida (500x500).png") ;
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE0, true) ;
	}
	else if(s_flag == 1)
	{
		s_music = CCSprite::create("Kaiser Phoenix (500x500).png") ;
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE1, true) ;
	}
	else if(s_flag == 2)
	{
		s_music = CCSprite::create("chronos (500x500).png") ;
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE2, true) ;
	}
	else if(s_flag == 3)
	{
		s_music = CCSprite::create("area51 (500x500).png") ;
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE3, true) ;
	}
	else if(s_flag == 4)
	{
		s_music = CCSprite::create("concon (500x500).png") ;
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE4, true) ;
	}
	else if(s_flag == 5)
	{
		s_music = CCSprite::create("evans (500x500).png") ;
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE5, true) ;
	}
	else if(s_flag == 6)
	{
		s_music = CCSprite::create("Macuilxochitl (500x500).png") ;
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE6, true) ;
	}
	else if(s_flag == 7)
	{
		s_music = CCSprite::create("natsumatsuri (500x500).png") ;
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE7, true) ;
	}
	else if(s_flag == 8)
	{
		s_music = CCSprite::create("sayonara trip (500x500).png") ;
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE8, true) ;
	}
	else if(s_flag == 9)
	{
		s_music = CCSprite::create("alstromeria (500x500).png") ;
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE9, true) ;
	}
	else if(s_flag == 10)
	{
		s_music = CCSprite::create("over there (500x500).png") ;
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE10, true) ;
	}
	else if(s_flag == 11)
	{
		s_music = CCSprite::create("the least 100 sec (500x500).png") ;
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE11, true) ;
	}
	
    popLayer = CCLayerColor::create(ccc4(0, 0, 0, 0), 500, 500) ;
    popLayer -> setPosition(ccp((winSize.width - popLayer -> getContentSize().width) / 2,
                              (winSize.height - popLayer -> getContentSize().height) / 2)) ;
	s_music -> setPosition(ccp((popLayer -> getContentSize().width) / 2,
                              (popLayer -> getContentSize().height) / 2)) ;
    
	this -> addChild(popLayer) ;
	popLayer -> addChild(s_music) ;
	
    // 메뉴 아이템 생성 및 초기화

	CCMenuItemImage* closeButton = CCMenuItemImage::create("closeButton.png", NULL, this, menu_selector(choice2::doClose)) ;
    CCMenu* closeMenu = CCMenu::create(closeButton, NULL) ;
	CCMenuItemImage* startButton = CCMenuItemImage::create("playButton.png", NULL, this, menu_selector(choice2::start)) ;
	CCMenu* startMenu = CCMenu::create(startButton, NULL) ;
    
	closeMenu -> setPosition(ccp(470, 470)) ;
	startMenu -> setPosition(ccp(250, 250)) ;
	popLayer -> addChild(closeMenu) ;
	popLayer -> addChild(startMenu) ;
	

    return true ;
}

void choice2::doClose(CCObject* pSender)
{
    // 팝업창 제거
    //this->removeFromParentAndCleanup(true) ;
	CCScene* pScene = choice::scene() ;
	CCDirector::sharedDirector() -> replaceScene(pScene) ;
	SimpleAudioEngine::sharedEngine() -> stopBackgroundMusic(true) ;
}

void choice2::start(CCObject* pSender)
{
	//int score = 10000, perfect = 300, great = 300, good = 300, miss = 300, combo = 500 ;
	CCScene * pscene = playScene::scene() ;
	CCDirector::sharedDirector() -> replaceScene(pscene) ;	
}