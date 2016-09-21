#ifndef __HeroPlane_SCENE_H__
#define __HeroPlane_SCENE_H__

#include "cocos2d.h"
#include<stdio.h>
using namespace cocos2d;
using namespace std;


class HeroPlane : public Sprite
{
public:

	bool initWithSpriteFrameName(const std::string& spriteFrameName);//��ʼ��
	static HeroPlane* createHeroPlane(const std::string& spriteFrameName);//��������

	int currentHp;
	int totalHp;
	int minusHp;

	int m_score; //��Ϸ����


	int level; //�ɻ���ǰ�ȼ�

	bool IsDoubleShooting; // �Ƿ��ܹ�˫���ӵ� ����
	bool IsRocketLoading; // �ܷ��䵼��
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
