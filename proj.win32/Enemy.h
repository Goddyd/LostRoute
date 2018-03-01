#ifndef ENEMY_H
#define ENEMY_H
#include "cocos2d.h"
USING_NS_CC;
#define Enemy_Stone "gameplay.stone1.png"
#define Enemy_1 "gameplay.enemy-1.png"
#define Enemy_2 "gameplay.enemy-2.png"
#define Enemy_Planet "gameplay.enemy.planet.png"

//�����������
typedef enum {
	EnemyTypeStone,
	EnemyTypeEnemy1,
	EnemyTypeEnemy2,
	EnemyTypePlanet
}EnemyTypes;

class Enemy :public Sprite {
	CC_SYNTHESIZE(EnemyTypes, enemyType, EnemyType);
	CC_SYNTHESIZE(int, initialHitPoints, InitialHitPoints);//��ʼ����ֵ
	CC_SYNTHESIZE(int, hitPoint, HitPoint);//��ǰ������ֵ
	CC_SYNTHESIZE(cocos2d::Vec2, velocity, Velocity);//�ٶ�
public:
	Enemy(EnemyTypes enemyType);
	void spawn();
	virtual void update(float dt);
	static Enemy* createWithEnemyTypes(EnemyTypes enemyType);
};



#endif
