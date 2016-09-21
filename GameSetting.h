#ifndef __GameSetting_SCENE_H__
#define __GameSetting_SCENE_H__

#include "cocos2d.h"
#include<stdio.h>
#include"ui\CocosGUI.h"

using namespace std;
using namespace cocos2d;
using namespace cocos2d::ui;

class GameSetting : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	Sprite *soundControl;

	//

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(GameSetting);
};

#endif // __GameSetting_SCENE_H__
