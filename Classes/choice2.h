#ifndef __PopupTouchEx__SecondScene__
#define __PopupTouchEx__SecondScene__

#include "cocos2d.h"

class choice2 : public cocos2d::CCLayerColor
{
public:
    virtual bool init();
    
    static cocos2d::CCScene* scene(int s_flag);
    
    CREATE_FUNC(choice2);
    
    
    cocos2d::CCSize winSize;
    CCLayerColor* popLayer;

    void doClose(CCObject* pSender);
	void start(CCObject* pSender);

};

#endif /* defined(__PopupTouchEx__SecondScene__) */