#include "cocos2d.h"
#include "choice.h"
#include "selectt.h"
#include "playScene.h"
#include "SimpleAudioEngine.h"
#include <fstream>
//#include <stdlib.h>



#define MUSIC_FILE "KAISER PHOENIX.mp3"

using namespace cocos2d ;
using namespace CocosDenshion ;
using namespace std ;

CCSprite* panel[12] ;
int check = 0 ;
CCLabelTTF* label ;
CCLabelTTF* scoreP ;
int score = 0 ;
char s[100] = {0} ;

CCAnimate* animate[12] ;
CCAnimate* animate1[12] ;
CCAction* rep[12] ;
CCDelayTime* delay ;
CCAction* action ;

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

	scoreP = CCLabelTTF::create("Score : 0","Thonburi",34,CCSize(300,200),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter);
	scoreP->setColor(ccc3(0,0,0));
	scoreP->setPosition(ccp(200, 900));
	this->addChild(scoreP);

	label = CCLabelTTF::create("µÎµÎµÕ","Thonburi",34,CCSize(300,200),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter);
	label->setColor(ccc3(0,0,0));
	label->setPosition(ccp(350, 950));
	this->addChild(label);
	
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE, true) ;
	CCSprite* maker_sh = CCSprite::create("img/marker_sh(200x200).jpg") ;
	CCAnimation* sh_ani = CCAnimation::create() ;
	sh_ani -> setDelayPerUnit(0.42f) ; // fps setting default 0.42

	for(int i = 0 ; i < 25 ; i++)
	{
		int index = i % 5 ;
		int rowIndex = i / 5 ;

		sh_ani -> addSpriteFrameWithTexture(maker_sh -> getTexture(), CCRectMake(index * 200, rowIndex * 200, 200, 200)) ;
	}
	
	for(int i = 3 ; i > -1 ; i--)
		for(int j = 0 ; j < 3 ; j++)
		{
			panel[j + (3 - i) * 3] = CCSprite::createWithTexture(maker_sh -> getTexture(), CCRectMake(0, 0, 200, 200)) ;
			panel[j + (3 - i) * 3] -> setPosition(ccp(j * 210 + 160, i * 210 + 120)) ;
			this -> addChild(panel[j + (3 - i) * 3]) ;
		}

	
	
	//FILE* fp ;
	//fp = fopen("test.txt", "r") ;
	
	loadNote() ;
	/*
	scroll_t(0.0f) ;
	panel[0] -> runAction(rep[0]) ;
	panel[1] -> runAction(rep[1]) ;
	panel[2] -> runAction(rep[2]) ;

	scroll_s(1.48f, 0.18f) ;
	panel[0] -> runAction(rep[0]) ;
	panel[3] -> runAction(rep[1]) ;
	panel[6] -> runAction(rep[2]) ;
	panel[2] -> runAction(rep[3]) ;
	panel[5] -> runAction(rep[4]) ;
	panel[8] -> runAction(rep[5]) ;
	panel[11] -> runAction(rep[6]) ;

	scroll_t(2.8f) ;
	panel[0] -> runAction(rep[0]) ;
	panel[1] -> runAction(rep[1]) ;
	panel[2] -> runAction(rep[2]) ;

	scroll_t(4.0f) ;
	panel[6] -> runAction(rep[0]) ;
	panel[7] -> runAction(rep[1]) ;
	panel[8] -> runAction(rep[2]) ;
		
	scroll_t(4.1f) ;
	panel[0] -> runAction(rep[0]) ;
	panel[1] -> runAction(rep[1]) ;

	panel[2] -> runAction(rep[2]) ;

	scroll_t(5.3f) ;
	panel[0] -> runAction(rep[0]) ;
	panel[1] -> runAction(rep[1]) ;
	panel[2] -> runAction(rep[2]) ;

	scroll_s(6.98f, 0.18f) ;
	panel[0] -> runAction(rep[0]) ;
	panel[3] -> runAction(rep[1]) ;
	panel[6] -> runAction(rep[2]) ;
	panel[2] -> runAction(rep[3]) ;
	panel[5] -> runAction(rep[4]) ;
	panel[8] -> runAction(rep[5]) ;
	panel[11] -> runAction(rep[6]) ;

	scroll_t(8.3f) ;
	panel[0] -> runAction(rep[0]) ;
	panel[1] -> runAction(rep[1]) ;
	panel[2] -> runAction(rep[2]) ;

	scroll_s(9.6f, 0.18f) ;
	panel[9] -> runAction(rep[0]) ;
	panel[10] -> runAction(rep[1]) ;
	panel[8] -> runAction(rep[2]) ;
	panel[7] -> runAction(rep[3]) ;
	panel[3] -> runAction(rep[4]) ;
	panel[4] -> runAction(rep[5]) ;
	panel[2] -> runAction(rep[6]) ;
	panel[1] -> runAction(rep[7]) ;
	
	scroll_t(11.2f) ;
	panel[9] -> runAction(rep[0]) ;
	panel[10] -> runAction(rep[1]) ;
	
	scroll_t(11.55f) ;
	panel[7] -> runAction(rep[0]) ;
	panel[8] -> runAction(rep[1]) ;

	scroll_t(11.9f) ;
	panel[3] -> runAction(rep[0]) ;
	panel[4] -> runAction(rep[1]) ;

	scroll_t(12.25f) ;
	panel[1] -> runAction(rep[0]) ;
	panel[2] -> runAction(rep[1]) ;

	scroll_t(12.6f) ;
	panel[10] -> runAction(rep[0]) ;
	panel[11] -> runAction(rep[1]) ;

	scroll_t(12.95f) ;
	panel[6] -> runAction(rep[0]) ;
	panel[7] -> runAction(rep[1]) ;

	scroll_t(13.3f) ;
	panel[4] -> runAction(rep[0]) ;
	panel[5] -> runAction(rep[1]) ;

	scroll_t(13.65f) ;
	panel[0] -> runAction(rep[0]) ;
	panel[1] -> runAction(rep[1]) ;

	scroll_t(14.0f) ;
	panel[9] -> runAction(rep[0]) ;
	panel[10] -> runAction(rep[1]) ;

	scroll_t(14.35f) ;
	panel[7] -> runAction(rep[0]) ;
	panel[8] -> runAction(rep[1]) ;

	scroll_t(14.7f) ;
	panel[3] -> runAction(rep[0]) ;
	panel[4] -> runAction(rep[1]) ;

	scroll_t(15.05f) ;
	panel[1] -> runAction(rep[0]) ;
	panel[2] -> runAction(rep[1]) ;

	scroll_t(15.4f) ;
	panel[10] -> runAction(rep[0]) ;
	panel[11] -> runAction(rep[1]) ;

	scroll_t(15.75f) ;
	panel[6] -> runAction(rep[0]) ;
	panel[7] -> runAction(rep[1]) ;

	scroll_t(16.1f) ;
	panel[4] -> runAction(rep[0]) ;
	panel[5] -> runAction(rep[1]) ;

	scroll_t(16.45f) ;
	panel[0] -> runAction(rep[0]) ;
	panel[1] -> runAction(rep[1]) ;

	scroll_t(16.8f) ;
	panel[6] -> runAction(rep[0]) ;
	panel[10] -> runAction(rep[1]) ;

	scroll_t(17.15f) ;
	panel[3] -> runAction(rep[0]) ;
	panel[7] -> runAction(rep[1]) ;

	scroll_t(17.5f) ;
	panel[8] -> runAction(rep[0]) ;
	panel[10] -> runAction(rep[1]) ;

	scroll_t(17.85f) ;
	panel[5] -> runAction(rep[0]) ;
	panel[7] -> runAction(rep[1]) ;

	scroll_t(18.2f) ;
	panel[1] -> runAction(rep[0]) ;
	panel[6] -> runAction(rep[1]) ;

	scroll_t(18.55f) ;
	panel[4] -> runAction(rep[0]) ;
	panel[9] -> runAction(rep[1]) ;

	scroll_t(18.9f) ;
	panel[1] -> runAction(rep[0]) ;
	panel[8] -> runAction(rep[1]) ;

	scroll_t(19.25f) ;
	panel[4] -> runAction(rep[0]) ;
	panel[11] -> runAction(rep[1]) ;

	scroll_t(19.6f) ;
	panel[9] -> runAction(rep[0]) ;
	panel[11] -> runAction(rep[1]) ;

	scroll_t(19.95f) ;
	panel[6] -> runAction(rep[0]) ;
	panel[8] -> runAction(rep[1]) ;

	scroll_t(20.3f) ;
	panel[3] -> runAction(rep[0]) ;
	panel[5] -> runAction(rep[1]) ;

	scroll_t(20.65f) ;
	panel[1] -> runAction(rep[0]) ;
	
	scroll_t(20.75f) ;
	panel[9] -> runAction(rep[0]) ;
	panel[11] -> runAction(rep[1]) ;

	scroll_s(21.1f, 0.07f) ;
	panel[0] -> runAction(rep[0]) ;
	panel[1] -> runAction(rep[1]) ;
	panel[3] -> runAction(rep[2]) ;
	panel[4] -> runAction(rep[3]) ;
	panel[6] -> runAction(rep[4]) ;
	panel[7] -> runAction(rep[5]) ;
	panel[9] -> runAction(rep[6]) ;
	panel[10] -> runAction(rep[7]) ;

	scroll_s(21.82f, 0.07f) ;
	panel[1] -> runAction(rep[0]) ;
	panel[2] -> runAction(rep[1]) ;
	panel[4] -> runAction(rep[2]) ;
	panel[5] -> runAction(rep[3]) ;
	panel[7] -> runAction(rep[4]) ;
	panel[8] -> runAction(rep[5]) ;
	panel[10] -> runAction(rep[6]) ;
	panel[11] -> runAction(rep[7]) ;*/

	CCMenuItemFont* close = CCMenuItemFont::create("µÚ·Î°¡±â",this,menu_selector(playScene::back)) ;
	close->setColor(ccc3(0,0,0)) ;
	CCMenu* pMenu = CCMenu::create(close,NULL) ;
	pMenu->setPosition(ccp(700, 1000)) ;
	this->addChild(pMenu) ;

	this->setTouchEnabled(true) ;


	return true ;
}

void playScene::loadNote()
{
	string f_name ;	
	CCFileUtils *fileUtils = CCFileUtils::sharedFileUtils() ;
		
	//f_name = CCFileUtils::sharedFileUtils() -> fullPathFromRelativePath("test.txt") ;	
	f_name = CCFileUtils::sharedFileUtils() -> getWriteablePath() ;
	CCLog("%s", f_name) ;
	f_name.append("test.txt") ;
	CCLog("%s", f_name) ;
	unsigned long fileSize ;
	unsigned char *stream = fileUtils->getFileData(f_name.c_str(), "r", &fileSize) ;
	/*CCLog("%s", f_name.c_str()) ;
	CCLog("%c", *stream) ;
	stream++ ;
	CCLog("%c", *stream) ;*/
	
	

	//ifstream note(f_name.c_str()) ;
	
	char t_ch[10], w_ch[10], p_ch[10], r_ch[10] ;
	//char ch ;
	int re_cnt ;
	int cnt ;

	//ch = *stream ;
	//ch = CCFileUtils::getFileData(f_name.c_str()) ;
	//if(note.is_open() == false)
	//	CCLog("Fuck !!!") ;
	//note.get(ch) ;
	//ch = fgetc(fp) ;
	//CCLog("%c", ch) ;

	while(*stream != '>')
	//while(!note.eof())
	//while(!feof(fp))
	{
		if(*stream == 't')
		//if(ch == 't')
		{
			for(int i = 0 ; i < 10 ; i++)
			{
				t_ch[i] = '\0' ;
				p_ch[i] = '\0' ;
				r_ch[i] = '\0' ;
			}

			stream++ ;
			//note.get(ch) ;
			//ch = fgetc(fp) ;
			if(*stream == '\n')
			//if(ch == '\n')
				stream++ ;
				//note.get(ch) ;
				//ch = fgetc(fp) ;
			cnt = 0 ;

			while(*stream != ' ')
			//while(ch != ' ')
			{
				*(t_ch + cnt) += *stream ;
				//*(t_ch + cnt) += ch ;
				cnt++ ;
				stream++ ;
				//note.get(ch) ;
				//ch = fgetc(fp) ;
			}

			scroll_t(atof(t_ch)) ;
			stream++ ;
			//note.get(ch) ;
			//ch = fgetc(fp) ;
			
			if(*stream == ' ')
			//if(ch == ' ')
				stream++ ;
				//note.get(ch) ;
				//ch = fgetc(fp) ;
			
			re_cnt = (int)(*stream) - 48 ;
			//re_cnt = (int)ch - 48 ;
	
			stream++ ;
			//note.get(ch) ;
			//ch = fgetc(fp) ;
			if(*stream == '\n')
			//if(ch == '\n')
				stream++ ;
				//note.get(ch) ;
				//ch = fgetc(fp) ;
				
			for(int i = 0 ; i < re_cnt ; i++)
			{
				cnt = 0 ;
	
				while(*stream != ' ')
				//while(ch != ' ')
				{
					*(p_ch + cnt) += *stream ;
					//*(p_ch + cnt) += ch ;
					cnt++ ;
					stream++ ;
					//note.get(ch) ;
					//ch = fgetc(fp) ;
				}
				
				if(*stream == ' ')
				//if(ch == ' ')
					stream++ ;
					//note.get(ch) ;
					//ch = fgetc(fp) ;
	
				cnt = 0 ;
	
				while(*stream != '\n' && *stream != '>')
				//while(ch != '\n' && !note.eof())
				//while(ch != '\n' && !feof(fp))
				{
					*(r_ch + cnt) += *stream ;
					//*(r_ch + cnt) += ch ;
					cnt++ ;
					stream++ ;
					//note.get(ch) ;
					//ch = fgetc(fp) ;
				}
	
				panel[atoi(p_ch)] -> runAction(rep[atoi(r_ch)]) ;
	
				for(int i = 0 ; i < 10 ; i++)
				{
					p_ch[i] = '\0' ;
					r_ch[i] = '\0' ;
				}

				if(*stream == '\n')
				//if(ch == '\n')
					stream++ ;
					//note.get(ch) ;
					//ch = fgetc(fp) ;
			}
			
			if(*stream != '>')
			//if(note.eof() == false)
			//if(feof(fp) == false)
				while(*stream != 't' && *stream != 's')
				//while(ch != 't' && ch != 's')
					stream++ ;
					//note.get(ch) ;
					//ch = fgetc(fp) ;
		}
		if(*stream == 's')
		//if(ch == 's')
		{
 			for(int i = 0 ; i < 10 ; i++)
			{
				t_ch[i] = '\0' ;
				w_ch[i] = '\0' ;
				p_ch[i] = '\0' ;
				r_ch[i] = '\0' ;
			}

			stream++ ;
			//note.get(ch) ;
			//ch = fgetc(fp) ;
			if(*stream == '\n')
			//if(ch == '\n')
				stream++ ;
				//note.get(ch) ;
				//ch = fgetc(fp) ;
			cnt = 0 ;
	
			while(*stream != ' ')
			//while(ch != ' ')
			{
				*(t_ch + cnt) += *stream ;
				//*(t_ch + cnt) += ch ;
				cnt++ ;
				stream++ ;
				//note.get(ch) ;
				//ch = fgetc(fp) ;
			}
				
			if(*stream == ' ')
			//if(ch == ' ')
				stream++ ;
				//note.get(ch) ;
			//	ch = fgetc(fp) ;
			cnt = 0 ;
	
			while(*stream != ' ')
			//while(ch != ' ')
			{
				*(w_ch + cnt) += *stream ;
				//*(w_ch + cnt) += ch ;
				cnt++ ;
				stream++ ;
				//note.get(ch) ;
				//ch = fgetc(fp) ;
			}
				
			scroll_s(atof(t_ch), atof(w_ch)) ;
			stream++ ;
			//note.get(ch) ;
			//ch = fgetc(fp) ;
	
			if(*stream == ' ')
			//if(ch == ' ')
				stream++ ;
				//note.get(ch) ;
			//	ch = fgetc(fp) ;
	
			re_cnt = (int)(*stream) - 48 ;
			//re_cnt = (int)ch - 48 ;
			stream++ ;
			//note.get(ch) ;
			//ch = fgetc(fp) ;
			if(*stream == '\n')
			//if(ch == '\n')
				stream++ ;
				//note.get(ch) ;
			//	ch = fgetc(fp) ;
	
			for(int i = 0 ; i < re_cnt ; i++)
			{
				cnt = 0 ;
					
				while(*stream != ' ')
				//while(ch != ' ')
				{
					*(p_ch + cnt) += *stream ;
					//*(p_ch + cnt) += ch ;
					cnt++ ;
					stream++ ;
					//note.get(ch) ;
					//ch = fgetc(fp) ;
				}		
	
				if(*stream == ' ')
				//if(ch == ' ')
					stream++ ;
					//note.get(ch) ;
				//	ch = fgetc(fp) ;
				cnt = 0 ;
	
				while(*stream != '\n' && *stream != '>')
				//while(ch != '\n' && !note.eof())
				//while(ch != '\n' && !feof(fp))
				{
					*(r_ch + cnt) += *stream ;
					//*(r_ch + cnt) += ch ;
					cnt++ ;
					stream++ ;
					//note.get(ch) ;
					//ch = fgetc(fp) ;
				}

				panel[atoi(p_ch)] -> runAction(rep[atoi(r_ch)]) ;
	
				for(int i = 0 ; i < 10 ; i++)
				{
					p_ch[i] = '\0' ;
					r_ch[i] = '\0' ;
				}

				if(*stream == '\n')
				//if(ch == '\n')
					stream++ ;
					//note.get(ch) ;
				//	ch = fgetc(fp) ;
			}
			
			if(*stream != '>')
			//if(note.eof() == false)
			//if(feof(fp) == false)
				while(*stream != 't' && *stream != 's')
				//while(ch != 't' && ch != 's')
					stream++ ;
					//note.get(ch) ;
				//	ch = fgetc(fp) ;
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
	SimpleAudioEngine::sharedEngine() -> stopBackgroundMusic(true) ;
	CCScene* pscene = choice::scene() ;
	CCDirector::sharedDirector() -> replaceScene(pscene) ;
}

void playScene::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent* event)
{
	int choiceM = 0 ;
    CCSetIterator it = pTouches->begin() ;
    CCTouch* touch = (CCTouch*)(*it) ;    
    CCPoint touchPoint = touch -> getLocation() ;
    
    CCLog("Touches Began..(%f,%f)",touchPoint.x,touchPoint.y) ;
  
	for(int i = 0 ; i < 12 ; i++)
	{	
		if((touchPoint.x < (panel[i] -> getPosition().x + 100)) && (touchPoint.x > (panel[i] -> getPosition().x - 100)))
			if((touchPoint.y < (panel[i] -> getPosition().y + 100)) && (touchPoint.y > (panel[i] -> getPosition().y - 100)))
				choiceM = i ;
		
		if(choiceM == 1 && check == 1)
			CCLog("check") ;		
	}

	CCSprite* maker_sh = CCSprite::create("img/marker_sh(200x200).jpg") ;
	
	CCRect now = panel[choiceM] -> getTextureRect() ;
	CCRect line1_1 = (maker_sh->getTextureRect(), CCRectMake(0, 0, 200, 200)) ;
	CCRect line1_2 = (maker_sh->getTextureRect(), CCRectMake(200, 0, 200, 200)) ;
	CCRect line1_3 = (maker_sh->getTextureRect(), CCRectMake(400, 0, 200, 200)) ;
	CCRect line1_4 = (maker_sh->getTextureRect(), CCRectMake(600, 0, 200, 200)) ;
	CCRect line1_5 = (maker_sh->getTextureRect(), CCRectMake(800, 0, 200, 200)) ;

	CCRect line2_1 = (maker_sh->getTextureRect(), CCRectMake(0, 200, 200, 200)) ;
	CCRect line2_2 = (maker_sh->getTextureRect(), CCRectMake(200, 200, 200, 200)) ;
	CCRect line2_3 = (maker_sh->getTextureRect(), CCRectMake(400, 200, 200, 200)) ;
	CCRect line2_4 = (maker_sh->getTextureRect(), CCRectMake(600, 200, 200, 200)) ;
	CCRect line2_5 = (maker_sh->getTextureRect(), CCRectMake(800, 200, 200, 200)) ;

	CCRect line3_1 = (maker_sh->getTextureRect(), CCRectMake(0, 400, 200, 200)) ;
	CCRect line3_2 = (maker_sh->getTextureRect(), CCRectMake(200, 400, 200, 200)) ;
	CCRect line3_3 = (maker_sh->getTextureRect(), CCRectMake(400, 400, 200, 200)) ;
	CCRect line3_4 = (maker_sh->getTextureRect(), CCRectMake(600, 400, 200, 200)) ;
	CCRect line3_5 = (maker_sh->getTextureRect(), CCRectMake(800, 400, 200, 200)) ;

	CCRect line4_1 = (maker_sh->getTextureRect(), CCRectMake(0, 600, 200, 200)) ;
	CCRect line4_2 = (maker_sh->getTextureRect(), CCRectMake(200, 600, 200, 200)) ;
	CCRect line4_3 = (maker_sh->getTextureRect(), CCRectMake(400, 600, 200, 200)) ;
	CCRect line4_4 = (maker_sh->getTextureRect(), CCRectMake(600, 600, 200, 200)) ;
	CCRect line4_5 = (maker_sh->getTextureRect(), CCRectMake(800, 600, 200, 200)) ;

	CCRect line5_1 = (maker_sh->getTextureRect(), CCRectMake(0, 800, 200, 200)) ;
	CCRect line5_2 = (maker_sh->getTextureRect(), CCRectMake(200, 800, 200, 200)) ;
	CCRect line5_3 = (maker_sh->getTextureRect(), CCRectMake(400, 800, 200, 200)) ;
	CCRect line5_4 = (maker_sh->getTextureRect(), CCRectMake(600, 800, 200, 200)) ;
	CCRect line5_5 = (maker_sh->getTextureRect(), CCRectMake(800, 800, 200, 200)) ;

	if(now.equals(line1_1)) ok(1) ;
	if(now.equals(line1_2)) ok(1) ;
	if(now.equals(line1_3)) ok(1) ;
	if(now.equals(line1_4)) ok(1) ;
	if(now.equals(line1_5)) ok(1) ;

	if(now.equals(line2_1)) ok(1) ;
	if(now.equals(line2_2)) ok(0) ;
	if(now.equals(line2_3)) ok(0) ;
	if(now.equals(line2_4)) ok(0) ;
	if(now.equals(line2_5)) ok(0) ;

	if(now.equals(line3_1)) ok(2) ;
	if(now.equals(line3_2)) ok(2) ;
	if(now.equals(line3_3)) ok(2) ;

	if(now.equals(line3_4)) ok(3) ;
	if(now.equals(line3_5)) ok(3) ;	
	if(now.equals(line4_1)) ok(3) ;
	if(now.equals(line4_2)) ok(3) ;

	if(now.equals(line4_3)) ok(2) ;
	if(now.equals(line4_4)) ok(2) ;
	if(now.equals(line4_5)) ok(0) ;

	if(now.equals(line5_1)) ok(0) ;
	if(now.equals(line5_2)) ok(0) ;
	if(now.equals(line5_3)) ok(0) ;
	if(now.equals(line5_4)) ok(1) ;
	if(now.equals(line5_5)) ok(1) ;
}

void playScene::ok(int value)
{
	CCLog("%d",value) ;
	this->removeChild(label, true) ;
	this->removeChild(scoreP, true) ;
	
	if(value == 1) 
		label = CCLabelTTF::create("Miss ...","Thonburi",34,CCSize(300,200),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter) ;
	else if(value == 2) 
	{
		label = CCLabelTTF::create("Good !","Thonburi",34,CCSize(300,200),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter) ;
		score += 30 ;	
	}
	else if(value == 3) 
	{
		label = CCLabelTTF::create("Perfect !","Thonburi",34,CCSize(300,200),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter) ;
		score += 50 ; 
	}
	else if(value == 0)
	{
		label = CCLabelTTF::create("soso...","Thonburi",34,CCSize(300,200),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter) ;
		score += 10 ; 
	}

	sprintf(s,"score : %d",score) ;
	scoreP = CCLabelTTF::create(s ,"Thonburi",34,CCSize(300,200),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter) ;
	scoreP->setColor(ccc3(0,0,0)) ;
	scoreP->setPosition(ccp(200, 900)) ;
	this->addChild(scoreP) ;

	label->setColor(ccc3(0,0,0)) ;
	label->setPosition(ccp(350, 950)) ;
	this->addChild(label) ;
}