#ifndef _HOMESCENE_
#define _HOMESCENE_

#include"cocos2d.h"
#include"SystemHeader.h"
#include "SettingLayer.h"
#include "HelpScene.h"

typedef enum {
	MenuItemStart,
	MenuItemSetting,
	MenuItemHelp
}ActionMenu;

class HomeScene:Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	virtual void onEnterTransitionDidFinish();
	void menuItemCallback(Ref* sender);
	CREATE_FUNC(HomeScene);

};
#endif
