#ifndef _RESULT_
#define _RESULT_

#include "cocos2d.h"

class result : public cocos2d::CCLayerColor
{
public:
	virtual bool init() ;

	static cocos2d::CCScene* scene(int score, int perfect, int great, int good, int miss, int combo, int maxCombo) ;

	CREATE_FUNC(result) ;

	void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent* event);

};

#endif