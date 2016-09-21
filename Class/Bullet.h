#ifndef __Bullet_SCENE_H__
#define __Bullet_SCENE_H__

#include "cocos2d.h"
#include<stdio.h>
#include "HeroPlane.h"
using namespace cocos2d;
using namespace std;
typedef enum BulletType {
	//Ĭ���ӵ�
	bullet_def,
	//�����ӵ�
	bullet_main,
	//�л��ӵ�
	bullet_enemy
    
}
Bullet_Type;

class Bullet : public Sprite
{
public:
	//�����ӵ�����
	Bullet_Type type;
	//��ʼ������
	bool initWithSpriteFrameName(const std::string& spriteFrameName);
	//�����ӵ����飬�ⲿ���ýӿ�
	static Bullet* createBullet(const std::string& spriteFrameName);
    CREATE_FUNC(Bullet);

};

#endif // __Bullet_SCENE_H__
