#include "SettingLayer.h"

Scene* SettingLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = SettingLayer::create();
	scene->addChild(layer);

	return scene;
}

bool SettingLayer::init()
{
	if (!BaseLayer::init())
	{
		return false;
	}

	return true;
}
void SettingLayer::menuSoundToggleCallback(Ref* pSender)
{
	
}
void SettingLayer::menuMusicToggleCallback(Ref* pSender)
{

}