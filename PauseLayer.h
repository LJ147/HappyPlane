
#ifndef __PauseLayer__H__
#define __PauseLayer__H__
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include"AudioEngine.h"

USING_NS_CC;
using namespace cocos2d::extension;
using namespace experimental;

class PauseLayer : public LayerColor {
public:
	static Scene* createScene(RenderTexture* rt);
	void musicSet(Ref * pSender);
	virtual bool init();  //多态
	CREATE_FUNC(PauseLayer);
	//判断是否开音效
	MenuItemSprite*setBtn;
	bool soundOpen = UserDefault::getInstance()->getBoolForKey("isMusicOpen");
	Size visibleSize;
	Sprite* volumeSetting;
	Sprite* volumeBackground;
	Sprite* volumeSlider;
	Sprite* volumeBar;
	virtual void onEnter();
	virtual void onExit();
	void changeClosePicture(Ref *object);
	void changeOpenPicture(Ref*object);
	void controlGameSound(Ref *object);
	//int _audioID;
//	bool _loop;
private:
	
};

#endif