#ifndef HELPSCENE_H
#define HELPSCENE_H

#include "MyUtility.h"
#include "cocos2d.h"
#include "BaseLayer.h"
#include "SystemHeader.h"

class HelpScene :public BaseLayer
{
public:
	static Scene* createScene();
	virtual bool init();

	CREATE_FUNC(HelpScene);
};
#endif
