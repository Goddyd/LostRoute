#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SystemHeader.h"
#include <thread>
using namespace std;
USING_NS_CC;
class HelloWorld : public Layer
{
private:
	thread* _loadingAudioThread;
	void loadingAudio();
	int m_nNumberOfLoaded;
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void loadingTextureCallBack(Texture2D* texture);
	void delayCall(float dt);
public:
    static Scene* createScene();
    virtual bool init();
	virtual void onExit();
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
