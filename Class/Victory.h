
#ifndef __Victory__H__
#define __Victory__H__
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include"Victory.h"
#include "StartScene.h"
#include"AudioEngine.h"
using namespace experimental;

using namespace std;
using namespace cocos2d;
USING_NS_CC;
using namespace cocos2d::extension;


class Victory : public LayerColor {
public:
	static Scene* createScene(RenderTexture* rt);
	virtual bool init();  //��̬
	CREATE_FUNC(Victory);
	//�ж��Ƿ���Ч
	Sprite*bgImg;//����
	void nextLevel(Ref *object);
	void backToStartScene(Ref *object);
	Label *score;




};

#endif