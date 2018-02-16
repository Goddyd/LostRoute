#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SystemHeader.h"
USING_NS_CC;
class HelloWorld : public Layer
{
public:
    static Scene* createScene();

    virtual bool init();
	int m_nNumberOfLoaded;
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void loadingTextureCallBack(Texture2D* texture);
	void delayCall(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
