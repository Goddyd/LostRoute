#ifndef BULLET_H
#define BULLET_H

#include "cocos2d.h"
#include "Fighter.h"
USING_NS_CC;
class  Bullet :public Sprite
{
	CC_SYNTHESIZE(Vec2, velocity, Velocity);
public:
	void shootBulletFromFighter(Fighter* fighter);
	virtual void update(float dt);
	static Bullet* createWithSpriteFrameName(const char* spriteFrameName);
};
#endif 

