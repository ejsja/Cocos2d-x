#include "result.h"
#include "choice.h"

using namespace cocos2d;

CCLabelTTF* rscoreP ;
char rs[100] = {0} ;
int reScore, rePerfect, reGreat, reGood, reMiss, reCombo, reMcombo ;
float value ;


CCScene* result::scene(int score, int perfect, int great, int good, int miss, int combo, int maxCombo)
{
	reScore = score ;
	rePerfect = perfect ;
	reGreat = great ;
	reGood = good ;
	reMiss = miss ;
	reCombo = combo ;
	reMcombo = maxCombo ;

	CCScene * scene = NULL ;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        result* layer = result::create() ;
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene -> addChild(layer) ;	
    } while (0);

    // return the scene
    return scene;
}

bool result::init()
{
	if(!CCLayerColor::initWithColor(ccc4(255, 255, 255, 255)))
	{
		return false ;
	}
	CCLog("!!!!!!!!!!!!!!!!") ;
	/*value = (rePerfect + reGreat) / reMcombo ;
	CCSprite* result_scene ;
	if( value * 100 > 0.94)
		result_scene = CCSprite::create("result1(test).png") ;
	else if((value * 100 > 0.89) && (value * 100 < 0.95))
		result_scene = CCSprite::create("result2(test).png") ;
	else if((value * 100 > 0.84) && (value * 100 < 0.90))
		result_scene = CCSprite::create("result3(test).png") ;
	else if((value * 100 > 0.79) && (value * 100 < 0.85))
		result_scene = CCSprite::create("result4(test).png") ;
	else if(value * 100 < 0.80)
		result_scene = CCSprite::create("result5(test).png") ;*/

	CCSprite* result_scene = CCSprite::create("result1(test).png") ;

	CCSize winSize = CCDirector::sharedDirector() -> getWinSize() ;
	result_scene -> setPosition(ccp(winSize.width / 2, winSize.height / 2)) ;
	this -> addChild(result_scene) ;
	CCSprite* scoreLayer = CCSprite::create("score.png") ;
	CCSprite* perfectLayer = CCSprite::create("perfect.png") ;
	CCSprite* greatLayer = CCSprite::create("great.png") ;
	CCSprite* goodLayer = CCSprite::create("good.png") ;
	CCSprite* missLayer = CCSprite::create("miss.png") ;
	CCSprite* comboLayer = CCSprite::create("combo.png") ;
	
	sprintf(rs,"%d",reScore) ;
	rscoreP = CCLabelTTF::create(rs ,"Thonburi",34,CCSize(300,120),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter) ;
	rscoreP->setColor(ccc3(0,0,0)) ;
	rscoreP->setPosition(ccp(360, 700)) ;
	scoreLayer -> setPosition(ccp(200, 700)) ;
	this -> addChild(scoreLayer) ;
	this->addChild(rscoreP) ;

	sprintf(rs,"%d",rePerfect) ;
	rscoreP = CCLabelTTF::create(rs ,"Thonburi",34,CCSize(300,120),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter) ;
	rscoreP->setColor(ccc3(0,0,0)) ;
	rscoreP->setPosition(ccp(360, 600)) ;
	perfectLayer -> setPosition(ccp(200, 600)) ;
	this -> addChild(perfectLayer) ;
	this->addChild(rscoreP) ;

	sprintf(rs,"%d",reGreat) ;
	rscoreP = CCLabelTTF::create(rs ,"Thonburi",34,CCSize(300,120),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter) ;
	rscoreP->setColor(ccc3(0,0,0)) ;
	rscoreP->setPosition(ccp(360, 500)) ;
	greatLayer -> setPosition(ccp(200, 500)) ;
	this -> addChild(greatLayer) ;
	this->addChild(rscoreP) ;

	sprintf(rs,"%d",reGood) ;
	rscoreP = CCLabelTTF::create(rs ,"Thonburi",34,CCSize(300,120),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter) ;
	rscoreP->setColor(ccc3(0,0,0)) ;
	rscoreP->setPosition(ccp(360, 400)) ;
	goodLayer -> setPosition(ccp(200, 400)) ;
	this -> addChild(goodLayer) ;
	this->addChild(rscoreP) ;

	sprintf(rs,"%d",reMiss) ;
	rscoreP = CCLabelTTF::create(rs ,"Thonburi",34,CCSize(300,120),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter) ;
	rscoreP->setColor(ccc3(0,0,0)) ;
	rscoreP->setPosition(ccp(360, 300)) ;
	missLayer -> setPosition(ccp(200, 300)) ;
	this -> addChild(missLayer) ;
	this->addChild(rscoreP) ;

	sprintf(rs,"%d",reCombo) ;
	rscoreP = CCLabelTTF::create(rs ,"Thonburi",34,CCSize(300,120),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter) ;
	rscoreP->setColor(ccc3(0,0,0)) ;
	rscoreP->setPosition(ccp(360, 200)) ;
	comboLayer -> setPosition(ccp(200, 200)) ;
	this -> addChild(comboLayer) ;
	this->addChild(rscoreP) ;

	this->setTouchEnabled(true) ;
	
	return true ;
}

void result::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent* event)
{
    
	CCScene* pscene = choice::scene() ;
		CCDirector::sharedDirector() -> replaceScene(pscene) ;


}