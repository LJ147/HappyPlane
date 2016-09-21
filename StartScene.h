#ifndef __StartScene_SCENE_H__
#define __StartScene_SCENE_H__

#include "cocos2d.h"
#include<stdio.h>
#include"AboutScene.h"
#include"MainGame.h"
#include"GameSetting.h"
#include"FirstScene.h"
using namespace std;
using namespace cocos2d;

class StartScene : public cocos2d::Layer
{
public:
	//背景图片
	Sprite *bgImg;
	//获取屏幕大小
	Size  visibleSize; 
	//是否播放音乐
	bool isPlayBgMusic;
	//
	Sprite *soundControl;
	Layer *layer;
	//飞机
	Sprite *planeImg;
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	//跳转到设置页面
	void changeToSetScene(Ref *object);
	//跳转到开始游戏界面
	void changeToGameScene(Ref *object);
	//跳转到排行榜
	void changeToRankListScene(Ref *object);
	//跳转到关于我们
	void changeToAboutScene(Ref *object);
	//退出确认弹框函数
	void confirmExitWhetherOrNot(Ref* object);
	void screenShoot();
	//退出游戏
	void exitGame(Ref *object);
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);
private:
	RenderTexture* render;
	RenderTexture* renderResult;
};

#endif // __StartScene_SCENE_H__
