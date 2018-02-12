#include "BaseLayer.h"

bool BaseLayer::init() 
{
	if (!Layer::init()) 
	{
		return false;
	}

	return true;
}

void BaseLayer::menuBackCallback(Ref* pSender)
{

}
void BaseLayer::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
}