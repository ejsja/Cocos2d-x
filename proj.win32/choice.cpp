#include "choice.h"
#include "playScene.h"
using namespace cocos2d ;

CCSprite* test[12] ;

CCScene* choice::scene()
{
	CCScene* scene = CCScene::create() ;

	choice* layer = choice::create() ;

	scene -> addChild(layer) ;

	return scene ;
}

bool choice::init(){
	if(!CCLayerColor::initWithColor(ccc4(100,100,100,100))){
		return false;
	}
	CCMenuItemFont* close = CCMenuItemFont::create("Exit",this,menu_selector(choice::close));
	close->setColor(ccc3(255,255,255));
	CCMenu* pMenu = CCMenu::create(close,NULL);
	pMenu->setPosition(ccp(420,780));
	this->addChild(pMenu);

	CCSprite* maker_sh = CCSprite::create("box(200x200).jpg") ;
	int cnt = 0 ;
	

	maker_sh->setContentSize(CCSize(50, 50));

	for(int i = 3 ; i > -1 ; i--)
		for(int j = 0 ; j < 3 ; j++)
		{
			cnt++ ;
			test[j + (3 - i) * 3] = CCSprite::createWithTexture(maker_sh -> getTexture(), CCRectMake(0, 0, 200, 200)) ;
			test[j + (3 - i) * 3] -> setPosition(ccp(j * 210 + 160, i * 210 + 120)) ;
			this -> addChild(test[j + (3 - i) * 3]) ;
		}
		
		this->setTouchEnabled(true);//터치 받긔

	return true ;
}
	/*
	CCSprite* maker_sh = CCSprite::create("marker_sh.jpg") ;
	
	CCSprite* test[12] ;
	for(int i = 3 ; i > -1 ; i--)
		for(int j = 0 ; j < 3 ; j++)
		{
			
			//cnt++ ;
			test[j + (3 - i) * 3] = CCSprite::createWithTexture(maker_sh -> getTexture(), CCRectMake(0, 0, 120, 120)) ;
			test[j + (3 - i) * 3] -> setPosition(ccp(j * 125 + 120, i*125 + 75)) ;
			this -> addChild(test[j + (3 - i) * 3]) ;
			//test[j + (3 - i) * 3] -> runAction(rep[j + (3 - i) * 3]) ;
			//CCLog("%d", cnt) ;
		}
	CCMenuItemFont* click1 = CCMenuItemFont::create("노래1 재생",this,menu_selector(choice::click1));
	click1->setColor(ccc3(255,255,255));
	CCMenu* click_1 = CCMenu::create(click1,NULL);
	click_1->setPosition(210,400);
	this->addChild(click_1,1);

	//close->setTag(1);
	//click1->setTag(2);

	//readFile();
}*/

/*void choice::click1(CCObject* pSender){
	CCMenuItem * select = (CCMenuItem*)pSender;

	int i=select->getTag();

	if(i==2){
	CCScene * pscene = Playscene::scene();
	CCDirector::sharedDirector()->replaceScene(pscene);}

	else{
		CCDirector::sharedDirector()->end();}
}*/

void choice::close(CCObject* pSender){
	CCDirector::sharedDirector()->end();
}

void choice::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent* event)
{
	int choiceM=0;
    CCSetIterator it = pTouches->begin();
    CCTouch* touch = (CCTouch*)(*it);    
    CCPoint touchPoint = touch->getLocation();
    
    CCLog("Touches Began..(%f,%f)",touchPoint.x,touchPoint.y);
    float halfWidth[12];
	float halfHeight[12];

	for(int i=0; i<12; i++){
    halfWidth[i] = test[i]->getTexture()->getContentSize().width / 2.0;
    halfHeight[i] = test[i]->getTexture()->getContentSize().height / 2.0;

    if (touchPoint.x > (test[i]->getPosition().x + halfWidth[i]) ||
        touchPoint.x < (test[i]->getPosition().x - halfWidth[i]) ||
        touchPoint.y < (test[i]->getPosition().y - halfHeight[i]) ||
        touchPoint.y > (test[i]->getPosition().y + halfHeight[i]) )
    {
        
    } else {
        CCLog("%d Touch...",i);
		choiceM = i;
    }
	if(choiceM==1){
		CCScene * pscene = playScene::scene();
		CCDirector::sharedDirector()->replaceScene(pscene);
	}
	}
}