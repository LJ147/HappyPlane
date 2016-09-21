#ifndef __MainGame_SCENE_H__
#define __MainGame_SCENE_H__

#include "cocos2d.h"
#include <stdio.h>
#include"StartScene.h"

class EnemyPath;
class Bullet;
class NewEnemyPlane;
class HeroPlane;

using namespace cocos2d;
using namespace std;

class MainGame : public cocos2d::Layer
{
public:
	//��������ʼ������
    static cocos2d::Scene* createScene();
	//����  ע�������¼�
	~MainGame();
	//������ײ������
	EventListenerPhysicsContact *m_event;
	//�����ҷ������ӵ�
	void mangerMainBullet(float time);
	//�Ƴ��ӵ�
	void removeBullet(Ref *object);
	//�Ƴ�����
	void removeBuff(Ref * object);
	//�Ƴ��ҷ��ɻ�
	void removeHeroPlane(Ref *object);
	//�ҷ��ɻ�����
	void heroPlaneDie(Ref *object);
	//��������
	void updateBgImg(float time);
	//�����ֲ�
	void changeBgImgPosition(Sprite *brImage_m);
	//��ת������ҳ��
	void changeToSetScene(Ref *object);
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	// �µĵл�������
	void managerEnemyPlanes(float time);
	//�ı����
	void changeTheScore();
	//ˢ�·���
	void refreshTheScore();
	//�ı�HP
	void changeTheHP();
	//ˢ��HP
	void refreshTheHP();
	//����ȫ���ڵ��ƶ��ӵ�
	void moveBullet(float time);
	///���Ƶл�����
	int enemyNumber;
	//���ӷ���
	int addtionalScore;
	//ʵ�ʵ÷�
	int scoreNum;

	///ͳһʵ�����ǵ���Ϸ������ʼ��
	void initAllParamters();
	//��ʱ����buff
	void manageBuff(float time);
	//�ƶ��ɻ�
	void removePlane(Node* pSender);
	//��ը����
	void planeBlowup(Sprite* plane);
	//�ж������Ƿ�����
	void judgeWhetherGameIsOver(float time);
	//��ת����Ϸʧ�ܳ���
	void gameOver(float delay);
	//��ת����Ϸ�ɹ�����
	void victory(float delay);
	//��ʼ�������˸����˸����
	void twinkle();

	bool soundOpen = UserDefault::getInstance()->getBoolForKey("isMusicOpen");
	CREATE_FUNC(MainGame);

private:
	//
	bool IsBossDead;
	//��Ļ��С
	Size visibleSize;
	//�ҷ��ӵ�
	Bullet* blt1;
	Bullet* blt2;
	Bullet* blt3;
	//������ǩ
	Label* score;
	//HP��ǩ
	Label *healthPoint;
	//����ͼ
	Sprite *bgImg;
	Sprite *bgTop;
	//�ҷ�Ӣ��
	HeroPlane* heroPlaneG;

	Vector<Sprite*> mBullets;
	Vector<Sprite*> mPlanes;
	//������ֵ
	RenderTexture* render;
	RenderTexture* renderResult;
};

#endif // __MainGame_SCENE_H__
