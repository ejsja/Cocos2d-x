#ifndef _SceneTrans_playScene_
#define _SceneTrans_playScene_

#include "cocos2d.h"
static cocos2d::CCDictionary s_dic ;
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
	//void loadNote(string noteName) ;
	void loadNote() ;
	
	virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent* event);

	/*virtual void ccTouchesBegan(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent) ;
	virtual void ccTouchesMoved(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent) ;
	virtual void ccTouchesEnded(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent) ;
	virtual void ccTouchesCancelled(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent) ;*/


};

#endif /* defined(_SceneTrans_playScene_) */