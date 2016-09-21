
#ifndef __MainGamePauseLayer__H__
#define __MainGamePauseLayer__H__
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include"MainGamePauseLayer.h"
#include "StartScene.h"
#include"AudioEngine.h"
using namespace experimental;

using namespace std;
using namespace cocos2d;
USING_NS_CC;
using namespace cocos2d::extension;


class MainGamePauseLayer : public LayerColor {
public:
	static Scene* createScene(RenderTexture* rt);
	virtual bool init();  //多态
	CREATE_FUNC(MainGamePauseLayer);
	//判断是否开音效
	MenuItemSprite*setBtn;
	Size visibleSize;
	Sprite *volumeSlider;
	Sprite *volumeBackground;

	void continueGame(Ref *object);
	void reStartGame(Ref *object);
	void mainMenu(Ref *object);
	bool soundOpen = UserDefault::getInstance()->getBoolForKey("isMusicOpen");
	void controlGameSound(Ref *object);
	virtual void onEnter();



};

#endif