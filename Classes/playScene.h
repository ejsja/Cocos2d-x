#ifndef _SceneTrans_playScene_
#define _SceneTrans_playScene_

#include "cocos2d.h"
static cocos2d::CCDictionary s_dic ;
using namespace cocos2d ;
class playScene : public cocos2d::CCLayerColor
{
public:
	virtual bool init() ;

	static cocos2d::CCScene* scene() ;

	CREATE_FUNC(playScene) ;

	void doClose(CCObject* pSender) ;
	void back(CCObject* pSender) ;
	void ok(int value) ;
	void scroll_t(float time) ;
	void scroll_s(float time, float weight) ;
	void loadNote() ;
	virtual void ccTouchesBegan(CCSet* pTouches, CCEvent* event);
		


};

#endif /* defined(_SceneTrans_playScene_) */