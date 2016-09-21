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
	//����ͼƬ
	Sprite *bgImg;
	static cocos2d::Scene* createScene();
	void changeToFirst(Ref *object);//ת����һ��
	void changeToSecond(Ref *object);//ת���ڶ���
	void changeToThird(Ref *object);//ת��������
	void backToStartScene(Ref *object);//ת��������
	bool soundOpen = UserDefault::getInstance()->getBoolForKey("isMusicOpen");//����userdefault ����ȡ��ʱ���ֵĿ���
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(ChoseScene);
private:
	
};

#endif // __ChoseScene_SCENE_H__
