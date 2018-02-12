#ifndef SETTINGLAYER_H
#define SETTINGLAYER_H

#include "BaseLayer.h"
#include "cocos2d.h"
#include "MyUtility.h"
#include "SystemHeader.h"
USING_NS_CC;
class SettingLayer :public BaseLayer
{
public:
	static Scene* createScene();

	virtual bool init();

	void menuSoundToggleCallback(cocos2d::Ref* pSender);
	void menuMusicToggleCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(SettingLayer);
};

#endif