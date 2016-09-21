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
	//��ȡӢ�۷ɻ�
	void getHero(Node* hero);
	//·��1��7
	void runPath1();
	void runPath2();
	void runPath3();
	void runPath4();
	void runPath5();
	void runPath6();
	void runPath7();

	//�����ӵ�
	void manageEnemyBullet(float time);
	//�����ӵ��ƶ�
	void EnemyBulletMove(float time);
	//�Ƴ��ӵ�
	void removeBullet(Ref *object);
	//��������body
	void setPlaneBody(float time);

	CREATE_FUNC(EnemyPath);

public:
	//�ɻ��ڵ�
	Node* plane;
	//�Ƴ��ڵ�
	void enemyRemove(Node* pNode);
	//s��·��
	void SPath(float time);
	//���зɻ�
	void TwicePath(float time);
	//ˮƽ���зɻ�
	void TwicePath2(float time);
	//����ɻ�
	void RandomPath(float time);
	//�����ɻ�
	void RandomPath2(float time);
	//ˮƽ�ƶ������߷ɻ�
	void TransversePath1(float time);
	void TransversePath2(float time);
	void TransversePath3(float time);
	void TransversePath4(float time);
	//��Բ�ɻ�
	void modelOfEnemy1(float time);
	//���ȷɻ�
	void modelOfEnemy2(float time);
	//�����ηɻ�
	void modelOfEnemy3(float time);
	//�����ɻ�
	void modelOfEnemy4(float time);
	//�ཻ��ɻ�
	void modelOfEnemy5(float time);
		//���ַɻ�
	void modelOfEnemy6(float time);
	//�ཻ��ɻ�
	void modelOfEnemy7(float time);
	//����ʶ��ɻ�
	void AIPath1(float time);
	void AIPath2(float time);
	//boss�ƶ�
	void BossMove(float time);
	//����boss
	void MangerBoss();
	//�ؿ�һ
	void chapter1();
	//boss
	NewEnemyPlane*boss;
	//boss�ƶ�
	void runBoss();
	//����boss�ӵ�
	void mangerBossBullet();

	//boss�ӵ���·��
	void BossBullet2(float rad,int tag);


	void BossBullet6(float time);
	void BossBullet7(float time);

	void BossBullet26(float time);
	void BossBullet27(float time);

	const double PI = 3.1415926535898;
	void RunBullet1(float time);
	void RunBullet2(float time);
	//�����ӵ�����body
	void setBulletBody(float time);
	//�ؿ���
	void chapter2();
	//�ؿ���
	void chapter3();
};


#endif