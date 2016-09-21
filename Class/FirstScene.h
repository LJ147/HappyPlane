#ifndef __FIRSTSCENCE_SCENE_H__
#define __FIRSTSCENCE_SCENE_H__
#include"StartScene.h"
#include "cocos2d.h"
#include<stdio.h>
using namespace std;
using namespace cocos2d;

class FirstScene : public cocos2d::Layer
{
public:
  
    static cocos2d::Scene* createScene();
	//Logo界面
	Sprite *Logo;
	//获取屏幕的大小
	Size windowSize;
	//
	void goToMainGame(Ref *object);
    virtual bool init();
	
    // implement the "static create()" method manually
    CREATE_FUNC(FirstScene);
};

#endif // __FIRSTSCENCE_SCENE_H__
