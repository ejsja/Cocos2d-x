#include "cocos2d.h"
#include "choice.h"
#include "result.h"
#include "playScene.h"
#include "SimpleAudioEngine.h"
#include <fstream>

#define MUSIC_FILE "KAISER PHOENIX (test).mp3"

using namespace cocos2d ;
using namespace CocosDenshion ;
using namespace std ;

CCSprite* panel[12] ;
int check = 0 ;
CCLabelTTF* label ;
CCLabelTTF* scoreP ;
CCLabelTTF* comboP ;
char s[100] = {0} ;
char c[100] = {0} ;

CCAnimate* animate[12] ;
CCAction* rep[12] ;
CCDelayTime* delay ;
CCAction* action ;
CCAnimate* t_animate[12] ;
CCAction* t_action ;

CCSprite* touchedMarker ;
CCAnimation* t_ani ;

int perfect = 0, great = 0, good = 0, miss = 0 ;
int combo = 0 ;
int score = 0 ;
int choiceM = 0 ;
int maxCombo = 0 ;
int positionX[12], positionY[12] ;

CCScene* playScene::scene()
{
	CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        playScene* layer = playScene::create() ;
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene -> addChild(layer) ;	
    } while (0);

    // return the scene
    return scene;
}

bool playScene::init()
{	
	if(!CCLayerColor::initWithColor(ccc4(255, 255, 255, 255)))
	{
		return false ;
	}
	
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(MUSIC_FILE) ;
	CCSprite* play_scene = CCSprite::create("Kaiser Phoenix(test).jpg");
	CCSize winSize = CCDirector::sharedDirector() -> getWinSize() ;
	play_scene -> setPosition(ccp(winSize.width / 2, winSize.height / 2)) ;
	//play_scene -> setPosition(ccp(384,512));
	this -> addChild(play_scene) ;

	scoreP = CCLabelTTF::create("Score : 0","Thonburi",34,CCSize(300,200),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter);
	scoreP->setColor(ccc3(255,255,255));
	scoreP->setPosition(ccp(200, 900));

	comboP = CCLabelTTF::create("Combo : 0", "Thonburi", 34, CCSize(300, 200), kCCTextAlignmentCenter, kCCVerticalTextAlignmentCenter) ;
	comboP -> setColor(ccc3(255, 255, 255)) ;
	comboP -> setPosition(ccp(200, 950)) ;
	
	this -> addChild(scoreP);
	this -> addChild(comboP) ;
		
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE, false) ;
	CCSprite* maker_sh = CCSprite::create("img/marker_sh(200x200).jpg") ;
	CCAnimation* sh_ani = CCAnimation::create() ;
	sh_ani -> setDelayPerUnit(0.42f) ; // fps setting default 0.42
		
	for(int i = 3 ; i > -1 ; i--)
		for(int j = 0 ; j < 3 ; j++)
		{
			panel[j + (3 - i) * 3] = CCSprite::createWithTexture(maker_sh -> getTexture(), CCRectMake(800, 800, 200, 200)) ;
			panel[j + (3 - i) * 3] -> setPosition(ccp(j * 210 + 160, i * 210 + 120)) ;
			this -> addChild(panel[j + (3 - i) * 3]) ;
		}

	for(int i = 0 ; i < 12 ; i++)
	{	
		positionX[i] = panel[i] -> getPosition().x ;
		positionY[i] = panel[i] -> getPosition().y ;

		if(choiceM == 1 && check == 1)
			CCLog("check") ;		
	}

	loadNote() ;
	

	CCMenuItemFont* close = CCMenuItemFont::create("Back Menu",this,menu_selector(playScene::back)) ;
	close->setColor(ccc3(255,255,255)) ;
	CCMenu* pMenu = CCMenu::create(close,NULL) ;
	pMenu->setPosition(ccp(600, 1000)) ;
	this->addChild(pMenu) ;

	this->setTouchEnabled(true) ;


	return true ;
}

void playScene::loadNote()
{
	string f_name ;	
	CCFileUtils *fileUtils = CCFileUtils::sharedFileUtils() ;
		
	f_name = CCFileUtils::sharedFileUtils() -> fullPathFromRelativePath("test.txt") ;	
	CCLog("%s", f_name.c_str()) ;
	unsigned long fileSize ;
	unsigned char *stream = fileUtils->getFileData(f_name.c_str(), "r", &fileSize) ;
		
	char t_ch[10], w_ch[10], p_ch[10], r_ch[10] ;
	int re_cnt ;
	int cnt ;
	
	while(*stream != '>')
	{
		if(*stream == 't')
		{
			for(int i = 0 ; i < 10 ; i++)
			{
				t_ch[i] = '\0' ;
				p_ch[i] = '\0' ;
				r_ch[i] = '\0' ;
			}

			stream++ ;
			if(*stream == '\n')
				stream++ ;
				
			cnt = 0 ;

			while(*stream != ' ')
			{
				*(t_ch + cnt) += *stream ;
				cnt++ ;
				stream++ ;
			}

			scroll_t(atof(t_ch)) ;
			stream++ ;
			
			if(*stream == ' ')
				stream++ ;
			
			re_cnt = (int)(*stream) - 48 ;
			stream++ ;
			if(*stream == '\n')
				stream++ ;
				
			for(int i = 0 ; i < re_cnt ; i++)
			{
				cnt = 0 ;
	
				while(*stream != ' ')
				{
					*(p_ch + cnt) += *stream ;
					cnt++ ;
					stream++ ;
				}
				
				if(*stream == ' ')
					stream++ ;
	
				cnt = 0 ;
	
				while(*stream != '\n' && *stream != '>')
				{
					*(r_ch + cnt) += *stream ;
					cnt++ ;
					stream++ ;
				}
	
				panel[atoi(p_ch)] -> runAction(rep[atoi(r_ch)]) ;
				//panel[atoi(p_ch)] -> stopAction(action) ;
					
				for(int i = 0 ; i < 10 ; i++)
				{
					p_ch[i] = '\0' ;
					r_ch[i] = '\0' ;
				}

				if(*stream == '\n')
					stream++ ;
			}
			maxCombo++ ;

			if(*stream != '>')
				while(*stream != 't' && *stream != 's')
					stream++ ;
		}
		if(*stream == 's')
		{
 			for(int i = 0 ; i < 10 ; i++)
			{
				t_ch[i] = '\0' ;
				w_ch[i] = '\0' ;
				p_ch[i] = '\0' ;
				r_ch[i] = '\0' ;
			}

			stream++ ;
			if(*stream == '\n')
				stream++ ;
			cnt = 0 ;
	
			while(*stream != ' ')
			{
				*(t_ch + cnt) += *stream ;
				cnt++ ;
				stream++ ;
			}
				
			if(*stream == ' ')
				stream++ ;
			cnt = 0 ;
	
			while(*stream != ' ')
			{
				*(w_ch + cnt) += *stream ;
				cnt++ ;
				stream++ ;
			}
				
			scroll_s(atof(t_ch), atof(w_ch)) ;
			stream++ ;
	
			if(*stream == ' ')
				stream++ ;
	
			re_cnt = (int)(*stream) - 48 ;
			stream++ ;
			if(*stream == '\n')
				stream++ ;
			
			for(int i = 0 ; i < re_cnt ; i++)
			{
				cnt = 0 ;
					
				while(*stream != ' ')
				{
					*(p_ch + cnt) += *stream ;
					cnt++ ;
					stream++ ;
				}		
	
				if(*stream == ' ')
					stream++ ;
				cnt = 0 ;
	
				while(*stream != '\n' && *stream != '>')
				{
					*(r_ch + cnt) += *stream ;
					cnt++ ;
					stream++ ;
				}

				panel[atoi(p_ch)] -> runAction(rep[atoi(r_ch)]) ;
				maxCombo++ ;
				//panel[atoi(p_ch)] -> stopAction(action) ;
				
				for(int i = 0 ; i < 10 ; i++)
				{
					p_ch[i] = '\0' ;
					r_ch[i] = '\0' ;
				}

				if(*stream == '\n')
					stream++ ;
			}
			

			if(*stream != '>')
				while(*stream != 't' && *stream != 's')
					stream++ ;
		}	
	}
}
	
void playScene::scroll_t(float time)
{
	CCSprite* maker_sh = CCSprite::create("img/marker_sh(200x200).jpg") ;
	CCAnimation* sh_ani = CCAnimation::create() ;
	sh_ani -> setDelayPerUnit(0.0345f) ; // fps setting

	for(int i = 3 ; i < 25 ; i++)
	{
		int index = i % 5 ;
		int rowIndex = i / 5 ;

		sh_ani -> addSpriteFrameWithTexture(maker_sh -> getTexture(), CCRectMake(index * 200, rowIndex * 200, 200, 200)) ;
	}
	
	delay = CCDelayTime::create(time) ;

	for(int i = 0 ; i < 12 ; i++)
	{
		animate[i] = CCAnimate::create(sh_ani) ;
		action = CCRepeat::create(animate[i],1) ; // ¹Ýº¹ È½¼ö
		rep[i] = CCSequence::create(delay,action, NULL) ;
	}	

}

void playScene::scroll_s(float time, float weight)
{
	CCSprite* maker_sh = CCSprite::create("img/marker_sh(200x200).jpg") ;
	CCAnimation* sh_ani = CCAnimation::create() ;
	sh_ani -> setDelayPerUnit(0.0345f) ; // fps setting
	
	for(int i = 3 ; i < 25 ; i++)
	{
		int index = i % 5 ;
		int rowIndex = i / 5 ;

		sh_ani -> addSpriteFrameWithTexture(maker_sh -> getTexture(), CCRectMake(index * 200, rowIndex * 200, 200, 200)) ;
	}

	float interval = 0.18f ;//set this value that you need
		
	for(int i = 0 ; i < 12 ; i++)
	{
		delay = CCDelayTime::create(time + i*weight) ;
		animate[i] = CCAnimate::create(sh_ani) ;
		action = CCRepeat::create(animate[i],1) ; // ¹Ýº¹ È½¼ö
		rep[i] = CCSequence::create(delay,action, NULL) ;
	} //end making animation


}

void playScene::back(CCObject* pSender)
{
	score = 0 ;	
	combo = 0 ;
	SimpleAudioEngine::sharedEngine() -> stopBackgroundMusic(true) ;
	CCScene* pscene = choice::scene() ;
	CCDirector::sharedDirector() -> replaceScene(pscene) ;
}

void playScene::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent* event)
{
	CCSetIterator it = pTouches->begin() ;
    CCTouch* touch = (CCTouch*)(*it) ;    
    CCPoint touchPoint = touch -> getLocation() ;

	int t_cnt = 0 ;
    
    CCLog("Touches Began..(%f,%f)",touchPoint.x,touchPoint.y) ;
  
	for(int i = 0 ; i < 12 ; i++)
	{
		if((touchPoint.x < (positionX[i] + 100)) && (touchPoint.x > (positionX[i] - 100)))
			if((touchPoint.y < (positionY[i] + 100)) && (touchPoint.y > (positionY[i] - 100)))
				choiceM = i ;
		
	}
	

	CCSprite* maker_sh = CCSprite::create("img/marker_sh(200x200).jpg") ;
	
	CCRect now = panel[choiceM] -> getTextureRect() ;
	CCRect firstLine[5], secondLine[5], thirdLine[5], fourthLine[5], fifthLine[5] ;

	for(int i = 0 ; i < 5 ; i++)
		firstLine[i] = (maker_sh -> getTextureRect(), CCRectMake(i * 200, 0, 200, 200)) ;
	for(int i = 0 ; i < 5 ; i++)
		secondLine[i] = (maker_sh -> getTextureRect(), CCRectMake(i * 200, 200, 200, 200)) ;
	for(int i = 0 ; i < 5 ; i++)
		thirdLine[i] = (maker_sh -> getTextureRect(), CCRectMake(i * 200, 400, 200, 200)) ;
	for(int i = 0 ; i < 5 ; i++)
		fourthLine[i] = (maker_sh -> getTextureRect(), CCRectMake(i * 200, 600, 200, 200)) ;
	for(int i = 0 ; i < 5 ; i++)
		fifthLine[i] = (maker_sh -> getTextureRect(), CCRectMake(i * 200, 800, 200, 200)) ;
	

	if(now.equals(thirdLine[3])) ok(3) ;
	if(now.equals(thirdLine[4])) ok(3) ;
	if(now.equals(fourthLine[0])) ok(3) ;
	if(now.equals(fourthLine[1])) ok(3) ; // Perfect

	if(now.equals(thirdLine[0])) ok(2) ;
	if(now.equals(thirdLine[1])) ok(2) ;
	if(now.equals(thirdLine[2])) ok(2) ;
	if(now.equals(fourthLine[2])) ok(2) ;
	if(now.equals(fourthLine[3])) ok(2) ;
	if(now.equals(fourthLine[4])) ok(2) ; // Great

	for(int i = 1 ; i < 5 ; i++)
		if(now.equals(firstLine[i])) ok(1) ;
	for(int i = 0 ; i < 5 ; i++)
		if(now.equals(secondLine[i])) ok(1) ;
	for(int i = 0 ; i < 3 ; i++)
		if(now.equals(fifthLine[i])) ok(1) ; // Good

	if(now.equals(firstLine[0])) ok(0) ;
	if(now.equals(fifthLine[3])) ok(0) ;
	if(now.equals(fifthLine[4])) ok(0) ; // Miss


	CCParticleSystem* particleTest = CCParticleSun::create() ;
	particleTest -> retain() ;
	particleTest -> setTexture(CCTextureCache::sharedTextureCache() -> addImage("img/stars.png")) ;
	particleTest -> setScale(3.0) ;
	particleTest -> setDuration(0.1f) ;
	particleTest -> setSpeed(30.0f) ;
	particleTest -> setPosition(ccp(touchPoint.x, touchPoint.y)) ;
	particleTest -> setAutoRemoveOnFinish(true) ;
	this -> addChild(particleTest) ;

	if(!SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
	{
		CCLog("Fuck !!!!!!!") ;
		//for(int i = 0 ; i < 12 ; i++)
			//panel[i] -> stopAllActions() ;
		
		CCScene* pscene = result::scene(score, perfect, great, good, miss, combo, maxCombo);
		CCDirector::sharedDirector() -> replaceScene(pscene) ;
		//this->removeAllChildrenWithCleanup(true) ;
	}
}

void playScene::ok(int value)
{
	/*CCSprite* touchedMarker = CCSprite::create("img/touched (200x200).png") ;
	t_ani = CCAnimation::create() ;
	t_ani -> setDelayPerUnit(0.03f) ; 
	
	for(int i = 0 ; i < 12 ; i++)
	{
		int index = i % 4 ;
		int rowIndex = i / 4 ;

		t_ani -> addSpriteFrameWithTexture(touchedMarker -> getTexture(), CCRectMake(index * 200, rowIndex * 200, 200, 200)) ;
	}
		
	for(int i = 0 ; i < 12 ; i++)
	{
		t_animate[i] = CCAnimate::create(t_ani) ;
		action = CCRepeat::create(t_animate[i],1) ; // ¹Ýº¹ È½¼ö
	}*/
	
	CCLog("%d",value) ;
	this -> removeChild(label, true) ;
	this -> removeChild(scoreP, true) ;
	this -> removeChild(comboP, true) ;

	if(value == 0) 
	{
		label = CCLabelTTF::create("Miss ...","Thonburi",34,CCSize(300,200),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter) ;
		label -> setColor(ccc3(255, 255, 255)) ;
		miss++ ;
		combo = 0 ;
	}
	else if(value == 1)
	{
		label = CCLabelTTF::create("Good !","Thonburi",34,CCSize(300,200),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter) ;
		label -> setColor(ccc3(255, 255, 255)) ;
		//panel[choiceM] -> stopAction(rep[choiceM]) ;
		//panel[choiceM] -> runAction(action) ;
		score += 10 ; 
		good++ ;
		combo++ ;
	}
	else if(value == 2) 
	{
		label = CCLabelTTF::create("Great !","Thonburi",34,CCSize(300,200),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter) ;
		label -> setColor(ccc3(255, 255, 255)) ;
		//panel[choiceM] -> stopAction(rep[choiceM]) ;
		//panel[choiceM] -> runAction(action) ;
		score += 30 ;
		great++ ;
		combo++ ;
	}
	else if(value == 3) 
	{
		label = CCLabelTTF::create("Perfect !","Thonburi",34,CCSize(300,200),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter) ;
		label -> setColor(ccc3(255, 255, 255)) ;
		//panel[choiceM] -> stopAction(rep[choiceM]) ;
		//panel[choiceM] -> runAction(action) ;
		score += 50 ; 
		perfect++ ;
		combo++ ;
	}	

	sprintf(s,"score : %d",score) ;
	scoreP = CCLabelTTF::create(s ,"Thonburi",34,CCSize(300,200),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter) ;
	scoreP->setColor(ccc3(255,255,255)) ;
	scoreP->setPosition(ccp(200, 900)) ;
	this->addChild(scoreP) ;

	sprintf(c, "Combo : %d", combo) ;
	comboP = CCLabelTTF::create(c, "Thonburi", 34, CCSize(300, 200), kCCTextAlignmentCenter, kCCVerticalTextAlignmentCenter) ;
	comboP -> setColor(ccc3(255, 255, 255)) ;
	comboP -> setPosition(ccp(200, 950)) ;
	this -> addChild(comboP) ;

	label->setColor(ccc3(255,255,255)) ;
	label->setPosition(ccp(350, 1000)) ;
	this->addChild(label) ;
		
}
