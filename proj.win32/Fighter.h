#ifndef FIGHTER_H
#define FIGHTER_H

#include"cocos2d.h"
USING_NS_CC;

class Fighter :public Sprite {
	CC_SYNTHESIZE(int, hitPoints, HitPoints);
	CC_SYNTHESIZE(Vec2, velocity, Velocity);
public:
	void setPosition(const Vec2& newPosition);
	static Fighter* createWithSpriteFrameName(const char* spriteFrameName);

};
#endif
