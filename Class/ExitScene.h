
#ifndef __ExitScene__H__
#define __ExitScene__H__
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include"StartScene.h"
using namespace std;
using namespace cocos2d;
USING_NS_CC;
using namespace cocos2d::extension;


class ExitScene : public LayerColor {
public:
	static Scene* createScene(RenderTexture* rt);
	virtual bool init();  //多态
	CREATE_FUNC(ExitScene);

	void exitGame(Ref *object);//判断退出游戏的回调函数
	
};

#endif