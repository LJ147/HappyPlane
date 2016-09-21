#ifndef __AboutScene_SCENE_H__
#define __AboutScene_SCENE_H__

#include "cocos2d.h"
#include<stdio.h>
#include"ui/CocosGUI.h"
#include"StartScene.h"

using namespace std;
using namespace cocos2d;

class AboutScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	//背景
	Sprite *bgImg;
	//信息展示
	//LabelTTF * infor;
	//跳转到设置页面
	void backToStartScene(Ref *object);
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(AboutScene);
};

#endif // __AboutScene_SCENE_H__
