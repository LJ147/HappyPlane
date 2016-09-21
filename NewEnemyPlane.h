#ifndef __NewEnemyPlane_SCENE_H__
#define __NewEnemyPlane_SCENE_H__

#include "cocos2d.h"
#include<stdio.h>
using namespace cocos2d;
using namespace std;
typedef enum EnemyPlaneType {
	//Ĭ�Ϸɻ�
	ememy_min,
	//�����ɻ�
	enemy_middle,
	//�з��ɻ�
	enemy_max,
	//Boss1
	enemy_Boss1,

	//��Ϊ6�֣�С�д����ַɻ����Ƿ���Է����ӵ�
	ememy_min_without_bullet,
	ememy_middle_without_bullet,
	ememy_max_without_bullet,

	ememy_min_with_bullet,
	ememy_middle_with_bullet,
	ememy_max_with_bullet
}
EnemyPlane_Type;

class NewEnemyPlane : public Sprite
{
public:
	EnemyPlane_Type type;
	//�����з��ɻ�ʵ��
	bool initWithSpriteFrameName(const std::string& spriteFrameName);
	static NewEnemyPlane* createNewEnemyPlane(const std::string& spriteFrameName);
	//��ǰѪ��
	int currentHp;
	//��������
	void setTypeOfPlane(EnemyPlane_Type type);
	void setTypeOfPlane(int num);

	//�Ƿ�����
	bool IsDead;



	CREATE_FUNC(NewEnemyPlane);



};

#endif // __Bullet_SCENE_H__
