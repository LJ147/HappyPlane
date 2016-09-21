#ifndef __HeroPlane_SCENE_H__
#define __HeroPlane_SCENE_H__

#include "cocos2d.h"
#include<stdio.h>
using namespace cocos2d;
using namespace std;


class HeroPlane : public Sprite
{
public:

	bool initWithSpriteFrameName(const std::string& spriteFrameName);//初始化
	static HeroPlane* createHeroPlane(const std::string& spriteFrameName);//创建函数

	int currentHp;
	int totalHp;
	int minusHp;

	int m_score; //游戏分数


	int level; //飞机当前等级

	bool IsDoubleShooting; // 是否能够双发子弹 道具
	bool IsRocketLoading; // 能否发射导弹
	bool IsThreeShooting;
	bool IsDead;
	bool IsAddBlood;
	bool IsReduceBlood;

	void LoseHP(float reducedHP);// 
	void addHP(float addedHP);   //
	void getADoubleShootingTool();
	void getARocketTool();


	CREATE_FUNC(HeroPlane);
private:
	char *Hero_name;
};

#endif // __Bullet_SCENE_H__
