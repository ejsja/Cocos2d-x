#ifndef _selectt_
#define _selectt_

#include "cocos2d.h"

class selectt : public cocos2d::CCLayerColor
{
public:
	virtual bool init() ;

	static cocos2d::CCScene* scene() ;

	CREATE_FUNC(selectt) ;

	void close(CCObject* pSender);
};

#endif /* defined(_SceneTrans_playScene_) */