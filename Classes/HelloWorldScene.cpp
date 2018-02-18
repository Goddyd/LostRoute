#include "HelloWorldScene.h"

Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();
	auto layer = HelloWorld::create();
	scene->addChild(layer);
    return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//使用精灵帧缓存加载
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/loading_texture.plist");
	
	//加载背景
	auto bg = TMXTiledMap::create("map/red_bg.tmx");
	this->addChild(bg);

	auto logo = Sprite::createWithSpriteFrameName("logo.png");
	this->addChild(logo);
	logo->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	auto sprite = Sprite::createWithSpriteFrameName("loding4.png");
	this->addChild(sprite);
	sprite->setPosition(logo->getPosition() - Vec2(0, logo->getContentSize().height/2 + 30));
    //创建动画
	Animation* animation = Animation::create();
	for ( int i = 1; i <= 4; i++)
	{
		__String* frameName = __String::createWithFormat("loding%d.png", i);
		SpriteFrame* spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}
	animation->setDelayPerUnit(0.5f);
	animation->setRestoreOriginalFrame(true);//动画结束还原出事状态

	Animate* action = Animate::create(animation);
	sprite->runAction(RepeatForever::create(action));
	/////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
	//异步添加纹理缓存
	m_nNumberOfLoaded = 0;
	Director::getInstance()->getTextureCache()->addImageAsync(
		"texture/home_texture.png",CC_CALLBACK_1(HelloWorld::loadingTextureCallBack,this));
	Director::getInstance()->getTextureCache()->addImageAsync(
		"texture/setting_texture.png",CC_CALLBACK_1(HelloWorld::loadingTextureCallBack,this));
	Director::getInstance()->getTextureCache()->addImageAsync(
		"texture/gameplay_texture.png", CC_CALLBACK_1(HelloWorld::loadingTextureCallBack, this));

	// add a "close" icon to exit the progress. it's an autorelease object 
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
	//多线程预处理声音
	_loadingAudioThread = new thread(&HelloWorld::loadingAudio,this);
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

void HelloWorld::loadingTextureCallBack(Texture2D* texture)
{
	switch (m_nNumberOfLoaded++)
	{
	case 0:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/home_texture.plist", texture);
		break;
	case 1:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/setting_texture.plist", texture);
		break;
	case 2:
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/gameplay_texture.plist", texture);
		this->schedule(schedule_selector(HelloWorld::delayCall), 1, 1, 3);
		break;
	}
}
void HelloWorld::delayCall(float dt) 
{

}
void HelloWorld::loadingAudio() 
{
	log("Audio has been loaded");
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(bg_music_1);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(bg_music_2);
}
void HelloWorld::onExit()
{
	Layer::onExit();
	_loadingAudioThread->join();
	CC_SAFE_DELETE(_loadingAudioThread);//delete _loadingAudioThread _loadingAudioThread = nullptr;
	SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("texture/loading_texture.plist");
	Director::getInstance()->getTextureCache()->removeTextureForKey("texture/loading_texture.png");
	this->unschedule(schedule_selector(HelloWorld::delayCall));
}