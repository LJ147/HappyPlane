#ifndef __StartScene_SCENE_H__
#define __StartScene_SCENE_H__

#include "cocos2d.h"
#include<stdio.h>
#include"AboutScene.h"
#include"MainGame.h"
#include"GameSetting.h"
#include"FirstScene.h"
using namespace std;
using namespace cocos2d;

class StartScene : public cocos2d::Layer
{
public:
	//����ͼƬ
	Sprite *bgImg;
	//��ȡ��Ļ��С
	Size  visibleSize; 
	//�Ƿ񲥷�����
	bool isPlayBgMusic;
	//
	Sprite *soundControl;
	Layer *layer;
	//�ɻ�
	Sprite *planeImg;
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	//��ת������ҳ��
	void changeToSetScene(Ref *object);
	//��ת����ʼ��Ϸ����
	void changeToGameScene(Ref *object);
	//��ת�����а�
	void changeToRankListScene(Ref *object);
	//��ת����������
	void changeToAboutScene(Ref *object);
	//�˳�ȷ�ϵ�����
	void confirmExitWhetherOrNot(Ref* object);
	void screenShoot();
	//�˳���Ϸ
	void exitGame(Ref *object);
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);
private:
	RenderTexture* render;
	RenderTexture* renderResult;
};

#endif // __StartScene_SCENE_H__
