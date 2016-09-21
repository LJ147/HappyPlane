#pragma once
#include"cocos2d.h"
#include"MainGame.h"
#include"HeroPlane.h"
#include"NewEnemyPlane.h"
#include<stdio.h>
using namespace std;
using namespace cocos2d;

USING_NS_CC;
#ifndef __EnemyPath__H__
#define __EnemyPath__H__


class EnemyPath : public Layer
{

public:
	//获取英雄飞机
	void getHero(Node* hero);
	//路径1到7
	void runPath1();
	void runPath2();
	void runPath3();
	void runPath4();
	void runPath5();
	void runPath6();
	void runPath7();

	//发射子弹
	void manageEnemyBullet(float time);
	//管理子弹移动
	void EnemyBulletMove(float time);
	//移除子弹
	void removeBullet(Ref *object);
	//设置物理body
	void setPlaneBody(float time);

	CREATE_FUNC(EnemyPath);

public:
	//飞机节点
	Node* plane;
	//移除节点
	void enemyRemove(Node* pNode);
	//s型路径
	void SPath(float time);
	//两行飞机
	void TwicePath(float time);
	//水平两行飞机
	void TwicePath2(float time);
	//随机飞机
	void RandomPath(float time);
	//随机大飞机
	void RandomPath2(float time);
	//水平移动四条线飞机
	void TransversePath1(float time);
	void TransversePath2(float time);
	void TransversePath3(float time);
	void TransversePath4(float time);
	//半圆飞机
	void modelOfEnemy1(float time);
	//弧度飞机
	void modelOfEnemy2(float time);
	//三角形飞机
	void modelOfEnemy3(float time);
	//抖动飞机
	void modelOfEnemy4(float time);
	//多交叉飞机
	void modelOfEnemy5(float time);
		//火字飞机
	void modelOfEnemy6(float time);
	//多交叉飞机
	void modelOfEnemy7(float time);
	//智能识别飞机
	void AIPath1(float time);
	void AIPath2(float time);
	//boss移动
	void BossMove(float time);
	//管理boss
	void MangerBoss();
	//关卡一
	void chapter1();
	//boss
	NewEnemyPlane*boss;
	//boss移动
	void runBoss();
	//管理boss子弹
	void mangerBossBullet();

	//boss子弹的路径
	void BossBullet2(float rad,int tag);


	void BossBullet6(float time);
	void BossBullet7(float time);

	void BossBullet26(float time);
	void BossBullet27(float time);

	const double PI = 3.1415926535898;
	void RunBullet1(float time);
	void RunBullet2(float time);
	//设置子弹物理body
	void setBulletBody(float time);
	//关卡二
	void chapter2();
	//关卡三
	void chapter3();
};


#endif