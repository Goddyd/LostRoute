#ifndef BASELAYER_H
#define BASELAYER_H

#include "cocos2d.h"
#include "SystemHeader.h"

class BaseLayer : public cocos2d::Layer
{
public:
	virtual bool init();
	virtual void onEnterTransitionDidFinish();
	void menuBackCallback(cocos2d::Ref* pSender);
};
#endif