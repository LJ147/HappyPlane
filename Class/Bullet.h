#ifndef __Bullet_SCENE_H__
#define __Bullet_SCENE_H__

#include "cocos2d.h"
#include<stdio.h>
#include "HeroPlane.h"
using namespace cocos2d;
using namespace std;
typedef enum BulletType {
	//默认子弹
	bullet_def,
	//本机子弹
	bullet_main,
	//敌机子弹
	bullet_enemy
    
}
Bullet_Type;

class Bullet : public Sprite
{
public:
	//定义子弹类型
	Bullet_Type type;
	//初始化函数
	bool initWithSpriteFrameName(const std::string& spriteFrameName);
	//创建子弹精灵，外部调用接口
	static Bullet* createBullet(const std::string& spriteFrameName);
    CREATE_FUNC(Bullet);

};

#endif // __Bullet_SCENE_H__
