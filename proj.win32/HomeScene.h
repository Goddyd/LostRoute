#ifndef _HOMESCENE_
#define _HOMESCENE_

#include"cocos2d.h"
#include"SystemHeader.h"

typedef enum {
	MenuItemStart,
	MenuItemSetting,
	MenuItemHelp
}ActionType;

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
