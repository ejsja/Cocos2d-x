#include "selectt.h"

using namespace cocos2d ;

CCScene* selectt::scene()
{
	CCScene* scene = CCScene::create() ;

	selectt* layer = selectt::create() ;

	scene -> addChild(layer) ;

	return scene ;
}

void selectt::close(CCObject* pSender){
	CCDirector::sharedDirector()->end();
}

bool selectt::init()
{
	if(!CCLayerColor::initWithColor(ccc4(255, 255, 255, 255)))
	{
		return false ;
	}
	CCMenuItemFont* close = CCMenuItemFont::create("Exit",this,menu_selector(selectt::close));
	close->setColor(ccc3(0,0,0));
	CCMenu* pMenu = CCMenu::create(close,NULL);
	pMenu->setPosition(ccp(420,780));
	this->addChild(pMenu);
}

	/*CCMenuItemFont* item1 = CCMenuItemFont::create(
		"Close Scene 2",
		this,
		menu_selector(playScene::doClose)) ;

	item1->setColor(ccc3(0, 0, 0)) ;

	CCMenu* pMenu = CCMenu::create(item1, NULL) ;

	pMenu->setPosition(ccp(240, 50)) ;

	this->addChild(pMenu) ;

	CCSprite* maker_sh = CCSprite::create("marker_sh.jpg") ;

	int cnt = 0 ;
	CCSprite* test[12] ;
	for(int i = 3 ; i > -1 ; i--)
		for(int j = 0 ; j < 3 ; j++)
		{
			
			cnt++ ;
			test[j + (3 - i) * 3] = CCSprite::createWithTexture(maker_sh -> getTexture(), CCRectMake(0, 0, 120, 120)) ;
			test[j + (3 - i) * 3] -> setPosition(ccp(j * 125 + 120, i*125 + 75)) ;
			this -> addChild(test[j + (3 - i) * 3]) ;
			CCLog("%d", cnt) ;
		}

	return true ;
}*/

/*void Playscene::doClose(CCObject* pSender)
{
	CCDirector::sharedDirector() -> popScene() ;
}*/