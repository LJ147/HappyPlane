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
	//创建、初始化函数
    static cocos2d::Scene* createScene();
	//析构  注销监听事件
	~MainGame();
	//物理碰撞监听器
	EventListenerPhysicsContact *m_event;
	//创建我方主机子弹
	void mangerMainBullet(float time);
	//移除子弹
	void removeBullet(Ref *object);
	//移除道具
	void removeBuff(Ref * object);
	//移除我方飞机
	void removeHeroPlane(Ref *object);
	//我方飞机死亡
	void heroPlaneDie(Ref *object);
	//背景更新
	void updateBgImg(float time);
	//背景轮播
	void changeBgImgPosition(Sprite *brImage_m);
	//跳转到设置页面
	void changeToSetScene(Ref *object);
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	// 新的敌机产生器
	void managerEnemyPlanes(float time);
	//改变分数
	void changeTheScore();
	//刷新分数
	void refreshTheScore();
	//改变HP
	void changeTheHP();
	//刷新HP
	void refreshTheHP();
	//遍历全部节点移动子弹
	void moveBullet(float time);
	///控制敌机数量
	int enemyNumber;
	//增加分数
	int addtionalScore;
	//实际得分
	int scoreNum;

	///统一实现我们的游戏变量初始化
	void initAllParamters();
	//定时管理buff
	void manageBuff(float time);
	//移动飞机
	void removePlane(Node* pSender);
	//爆炸函数
	void planeBlowup(Sprite* plane);
	//判断主机是否死亡
	void judgeWhetherGameIsOver(float time);
	//跳转到游戏失败场景
	void gameOver(float delay);
	//跳转到游戏成功场景
	void victory(float delay);
	//开始界面的闪烁的闪烁动画
	void twinkle();

	bool soundOpen = UserDefault::getInstance()->getBoolForKey("isMusicOpen");
	CREATE_FUNC(MainGame);

private:
	//
	bool IsBossDead;
	//屏幕大小
	Size visibleSize;
	//我方子弹
	Bullet* blt1;
	Bullet* blt2;
	Bullet* blt3;
	//分数标签
	Label* score;
	//HP标签
	Label *healthPoint;
	//背景图
	Sprite *bgImg;
	Sprite *bgTop;
	//我方英雄
	HeroPlane* heroPlaneG;

	Vector<Sprite*> mBullets;
	Vector<Sprite*> mPlanes;
	//截屏传值
	RenderTexture* render;
	RenderTexture* renderResult;
};

#endif // __MainGame_SCENE_H__
