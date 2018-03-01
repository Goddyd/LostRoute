#ifndef ENEMY_H
#define ENEMY_H
#include "cocos2d.h"
USING_NS_CC;
#define Enemy_Stone "gameplay.stone1.png"
#define Enemy_1 "gameplay.enemy-1.png"
#define Enemy_2 "gameplay.enemy-2.png"
#define Enemy_Planet "gameplay.enemy.planet.png"

//定义敌人类型
typedef enum {
	EnemyTypeStone,
	EnemyTypeEnemy1,
	EnemyTypeEnemy2,
	EnemyTypePlanet
}EnemyTypes;

class Enemy :public Sprite {
	CC_SYNTHESIZE(EnemyTypes, enemyType, EnemyType);
	CC_SYNTHESIZE(int, initialHitPoints, InitialHitPoints);//初始生命值
	CC_SYNTHESIZE(int, hitPoint, HitPoint);//当前的生命值
	CC_SYNTHESIZE(cocos2d::Vec2, velocity, Velocity);//速度
public:
	Enemy(EnemyTypes enemyType);
	void spawn();
	virtual void update(float dt);
	static Enemy* createWithEnemyTypes(EnemyTypes enemyType);
};



#endif
