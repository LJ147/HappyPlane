
#ifndef __Gameover__H__
#define __Gameover__H__
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include"Gameover.h"
#include "StartScene.h"
#include"AudioEngine.h"
using namespace experimental;

using namespace std;
using namespace cocos2d;
USING_NS_CC;
using namespace cocos2d::extension;


class Gameover : public LayerColor {
public:
	static Scene* createScene(RenderTexture* rt);
	virtual bool init();  //��̬
	CREATE_FUNC(Gameover);
	//�ж��Ƿ���Ч
	Label *score;
	Sprite*bgImg;//����
	void reStart(Ref *object);
	void backToStartScene(Ref *object);
	bool soundOpen = UserDefault::getInstance()->getBoolForKey("isMusicOpen");


};

#endif