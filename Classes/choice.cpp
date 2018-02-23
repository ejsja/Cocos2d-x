#include "choice.h"
#include "choice2.h"
#include "playScene.h"
using namespace cocos2d ;

CCSprite* test[12] ;
int flag = 0 ;

CCScene* choice::scene()
{
	CCScene* scene = CCScene::create() ;

	choice* layer = choice::create() ;

	scene -> addChild(layer) ;

	return scene ;
}

bool choice::init(){
	
	if(!CCLayerColor::initWithColor(ccc4(100, 100, 100, 100)))
	{
		return false;
	}

	CCSprite* choice_scene = CCSprite::create("select (test).png") ;
	CCSize winSize = CCDirector::sharedDirector() -> getWinSize() ;
	choice_scene -> setPosition(ccp(winSize.width / 2, winSize.height / 2)) ;
	//choice_scene -> setPosition(ccp(384,512)) ;
	CCMenuItemFont* close = CCMenuItemFont::create("Exit",this,menu_selector(choice::close)) ;
	close -> setColor(ccc3(255,255,255)) ;
	CCMenu* pMenu = CCMenu::create(close,NULL);
	pMenu -> setPosition(ccp(420,780)) ;
	this -> addChild(choice_scene) ;
	this->addChild(pMenu) ;
	CCSprite* songImage[12] ;
	songImage[0] = CCSprite::create("albida (200x200).png") ;
	songImage[1] = CCSprite::create("Kaiser Phoenix (200x200).png") ;
	songImage[2] = CCSprite::create("chronos (200x200).png") ;
	songImage[3] = CCSprite::create("area51 (200x200).png") ;
	songImage[4] = CCSprite::create("concon (200x200).png") ;
	songImage[5] = CCSprite::create("evans (200x200).png") ;
	songImage[6] = CCSprite::create("Macuilxochitl (200x200).png") ;
	songImage[7] = CCSprite::create("natsumatsuri (200x200).png") ;
	songImage[8] = CCSprite::create("sayonara trip (200x200).png") ;
	songImage[9] = CCSprite::create("alstromeria (200x200).png") ;
	songImage[10] = CCSprite::create("over there (200x200).png") ;
	songImage[11] = CCSprite::create("the least 100 sec (200x200).png") ;
	
	
	for(int i = 3 ; i > -1 ; i--)
		for(int j = 0 ; j < 3 ; j++)
		{
			test[j + (3 - i) * 3] = CCSprite::createWithTexture(songImage[j + (3 - i) * 3] -> getTexture(), CCRectMake(0, 0, 200, 200)) ;
			test[j + (3 - i) * 3] -> setPosition(ccp(j * 210 + 160, i * 210 + 120)) ;
			this -> addChild(test[j + (3 - i) * 3]) ;
		}
		
		this->setTouchEnabled(true);//터치 받긔
		
	return true ;
}

void choice::close(CCObject* pSender){
	CCDirector::sharedDirector() -> end() ;
}

void choice::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent* event)
{
	
    CCSetIterator it = pTouches->begin() ;
    CCTouch* touch = (CCTouch*)(*it) ;    
    CCPoint touchPoint = touch->getLocation() ;
    
    CCLog("Touches Began..(%f,%f)",touchPoint.x,touchPoint.y) ;
    float halfWidth[12] ;
	float halfHeight[12] ;

	for(int i = 0 ; i < 12 ; i++)
	{
		halfWidth[i] = test[i]->getTexture() -> getContentSize().width / 2.0 ;
		halfHeight[i] = test[i]->getTexture() -> getContentSize().height / 2.0 ;

		if (touchPoint.x > (test[i] -> getPosition().x + halfWidth[i]) ||
			touchPoint.x < (test[i] -> getPosition().x - halfWidth[i]) ||
			touchPoint.y < (test[i] -> getPosition().y - halfHeight[i]) ||
			touchPoint.y > (test[i] -> getPosition().y + halfHeight[i]) )
		{} 
		else 
		{
			CCLog("%d Touch...",i) ;
			flag = i ;
		}

			doPopup() ;
	}
}

void choice::doPopup()
{
    // 팝업 레이어 삽입
    CCScene* popWin ;
    popWin = choice2::scene(flag) ;
    this->addChild(popWin, 2000, 2000) ;
}