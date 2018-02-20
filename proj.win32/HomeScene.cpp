#include"HomeScene.h"
Scene* HomeScene::createScene() 
{
	auto scene = Scene::create();
	auto layer = HomeScene::create();
	scene->addChild(layer);

	return scene;
}

bool HomeScene::init()
{
	if (!Layer::init()) {
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto bg = TMXTiledMap::create("map/red_bg.tmx");
	this->addChild(bg);

	auto top = Sprite::createWithSpriteFrameName("home-top.png");
	top->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - top->getContentSize().height / 2));

	auto end = Sprite::createWithSpriteFrameName("home-end.png");
	end->setPosition(Vec2(visibleSize.width / 2, visibleSize.height + end->getContentSize().height / 2));

	return true;
}
void HomeScene::onEnterTransitionDidFinish()
{ 
	Layer::onEnterTransitionDidFinish();
	UserDefault *defaults = UserDefault::getInstance();
	
	if (defaults->getBoolForKey(MUSIC_KEY))
	{
		SimpleAudioEngine::getInstance()->playBackgroundMusic(bg_music_1,true);
		log("music has played");
	}
}