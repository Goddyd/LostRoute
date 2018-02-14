#include "HelpScene.h"

Scene* HelpScene::createScene()
{
	auto scene = Scene::create();
	auto layer = HelpScene::create();

	scene->addChild(layer);
	return scene;
}

bool HelpScene::init()
{
	if (!BaseLayer::init())
	{
		return false;
	}

	return true;
}