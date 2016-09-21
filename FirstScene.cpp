#include "FirstScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include"SimpleAudioEngine.h"
#include"AudioEngine.h"
using namespace experimental;
using namespace CocosDenshion;
USING_NS_CC;
using namespace cocostudio::timeline;
Scene* FirstScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = FirstScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// �жϷɻ��Ƿ�ִ�й�ease����
bool isFly = true;
//�������ֿؼ�
int audioID;
bool FirstScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	AudioEngine::preload("sounnd/BgMusic.mp3");//���ر��������ļ�
	windowSize = getContentSize();
	Logo = Sprite::create("loadingBgp.png");//����LOGO
	Logo->setAnchorPoint(Vec2(0.5, 0.5));
	Logo->setPosition(Vec2(windowSize / 2));
	addChild(Logo);
	//���������溯��
	CallFuncN * fun = CallFuncN::create(CC_CALLBACK_1(FirstScene::goToMainGame,this));
	//˳�򶯻�
	Sequence *list = Sequence::create(DelayTime::create(2),fun, NULL);
	runAction(list);

    return true;
}
//�л���������
bool isExed = false;
void FirstScene::goToMainGame(Ref *object) {
		if (UserDefault::getInstance()->getBoolForKey("isMusicOpen")) {//�ж��ϴ���Ϸ�����������Ƿ�ر�
			audioID = AudioEngine::play2d("BgMusic.mp3", true);//��������
			AudioEngine::setVolume(audioID, 1);
			int percent = UserDefault::getInstance()->getIntegerForKey("percent");//���ݰٷֱ��������
			auto volum = 1.0f*percent/ 100;
			AudioEngine::setVolume(audioID, volum);
			isExed = true;//��
	}
		Director  *dir = Director::getInstance();
		dir->replaceScene(StartScene::createScene());
}