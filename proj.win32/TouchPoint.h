#ifndef _TouchEx5_TouchPoint_
#define _TouchEx5_TouchPoint_

#include "cocos2d.h"

using namespace cocos2d ;

static ccColor3B s_TouchColors[CC_MAX_TOUCHES] = {
	ccYELLOW,
	ccBLUE,
	ccGREEN,
	ccRED,
	ccMAGENTA
} ;

class TouchPoint : public CCNode
{
public:
	TouchPoint()
	{
		setShaderProgram(CCShaderCache::sharedShaderCache() -> programForKey(kCCShader_PositionTextureColor)) ;
	}

	virtual void draw()
	{
		ccDrawColor4B(m_TouchColor.r, m_TouchColor.g, m_TouchColor.b, 255) ;
		glLineWidth(10) ;
		ccDrawLine(ccp(0, m_pTouchPoint.y), ccp(getContentSize().width, m_pTouchPoint.y)) ;
		ccDrawLine(ccp(m_pTouchPoint.x, 0), ccp(m_pTouchPoint.x, getContentSize().height)) ;
		glLineWidth(1) ;
		ccPointSize(30) ;
		ccDrawPoint(m_pTouchPoint) ;
	}

	void setTouchPos(const CCPoint& pt)
	{
		m_pTouchPoint = pt ;
	}

	void setTouchColor(ccColor3B color)
	{
		m_TouchColor = color ;
	}

	static TouchPoint* touchPointWithParent(CCNode* pParent)
	{
		TouchPoint* pRet = new TouchPoint() ;
		pRet -> setContentSize(pParent -> getContentSize()) ;
		pRet -> setAnchorPoint(ccp(0.0f, 0.0f)) ;
		pRet -> autorelease() ;
		return pRet ;
	}

private:
	CCPoint m_pTouchPoint ;
	ccColor3B m_TouchColor ;
} ;

#endif /* defined(_TouchEx5_TouchPoint_) */
