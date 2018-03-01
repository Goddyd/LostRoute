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
	addChild(top);

	auto end = Sprite::createWithSpriteFrameName("home-end.png");
	end->setPosition(Vec2(visibleSize.width / 2, end->getContentSize().height / 2));
	addChild(end);
  
	auto startSpriteNormal = Sprite::createWithSpriteFrameName("home.button.start.png");
	auto startSpriteSelected = Sprite::createWithSpriteFrameName("home.button.start-on.png");
	auto startMenuItem = MenuItemSprite::create(
		startSpriteNormal,
		startSpriteSelected,
		CC_CALLBACK_1(HomeScene::menuItemCallback,this));
	startMenuItem->setTag(ActionMenu::MenuItemStart);

	auto settingSpriteNormal = Sprite::createWithSpriteFrameName("home.button.setting.png");
	auto settingSpriteSelected = Sprite::createWithSpriteFrameName("home.button.setting-on.png");
	auto settingMenuItem = MenuItemSprite::create(
		settingSpriteNormal,
		settingSpriteSelected,
		CC_CALLBACK_1(HomeScene::menuItemCallback,this));
	settingMenuItem->setTag(ActionMenu::MenuItemSetting);

	auto helpSpriteNormal = Sprite::createWithSpriteFrameName("home.button.help.png");
	auto helpSpriteSelected = Sprite::createWithSpriteFrameName("home.button.help-on.png");
	auto helpMenuItem = MenuItemSprite::create(
		helpSpriteNormal,
		helpSpriteSelected,
		CC_CALLBACK_1(HomeScene::menuItemCallback, this));
	helpMenuItem->setTag(ActionMenu::MenuItemHelp);

	auto menu = Menu::create(startMenuItem, settingMenuItem, helpMenuItem, NULL);
	menu->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	menu->alignItemsVerticallyWithPadding(12);
	addChild(menu);

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
void HomeScene::menuItemCallback(Ref* sender)
{
	if (UserDefault::getInstance()->getBoolForKey(MUSIC_KEY))
	{
		SimpleAudioEngine::getInstance()->playEffect(sound_1);
	}
	Scene* tsc = nullptr;
	MenuItem* menuItem = (MenuItem*)sender;
	log("MenuItem id = %d", menuItem->getTag());
	switch (menuItem->getTag())
	{
	case ActionMenu::MenuItemStart:
		log("开始按钮");
		break;
	case ActionMenu::MenuItemSetting:
		log("设置按钮");
		tsc = TransitionFade::create(1.0f, SettingLayer::createScene());
		break;
	case ActionMenu::MenuItemHelp:
		log("帮助按钮");
		tsc = TransitionFade::create(1.0f, HelpScene::createScene());
		break;
	}
	if (tsc)
	{
		Director::getInstance()->pushScene(tsc);
	}
}