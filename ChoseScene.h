#ifndef __ChoseScene_SCENE_H__
#define __ChoseScene_SCENE_H__

#include "cocos2d.h"
#include<stdio.h>
#include"AboutScene.h"
#include"MainGame.h"
#include"GameSetting.h"
#include"FirstScene.h"
using namespace std;
using namespace cocos2d;

class ChoseScene : public cocos2d::Layer
{
public:
	//背景图片
	Sprite *bgImg;
	static cocos2d::Scene* createScene();
	void changeToFirst(Ref *object);//转到第一关
	void changeToSecond(Ref *object);//转到第二关
	void changeToThird(Ref *object);//转到第三关
	void backToStartScene(Ref *object);//转到主界面
	bool soundOpen = UserDefault::getInstance()->getBoolForKey("isMusicOpen");//利用userdefault 来获取当时音乐的开关
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(ChoseScene);
private:
	
};

#endif // __ChoseScene_SCENE_H__
