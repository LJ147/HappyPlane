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

// 判断飞机是否执行过ease动画
bool isFly = true;
//播放音乐控件
int audioID;
bool FirstScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	AudioEngine::preload("sounnd/BgMusic.mp3");//加载背景音乐文件
	windowSize = getContentSize();
	Logo = Sprite::create("loadingBgp.png");//加载LOGO
	Logo->setAnchorPoint(Vec2(0.5, 0.5));
	Logo->setPosition(Vec2(windowSize / 2));
	addChild(Logo);
	//返回主界面函数
	CallFuncN * fun = CallFuncN::create(CC_CALLBACK_1(FirstScene::goToMainGame,this));
	//顺序动画
	Sequence *list = Sequence::create(DelayTime::create(2),fun, NULL);
	runAction(list);

    return true;
}
//切换场景函数
bool isExed = false;
void FirstScene::goToMainGame(Ref *object) {
		if (UserDefault::getInstance()->getBoolForKey("isMusicOpen")) {//判断上次游戏结束后音乐是否关闭
			audioID = AudioEngine::play2d("BgMusic.mp3", true);//播放音乐
			AudioEngine::setVolume(audioID, 1);
			int percent = UserDefault::getInstance()->getIntegerForKey("percent");//根据百分比设计音量
			auto volum = 1.0f*percent/ 100;
			AudioEngine::setVolume(audioID, volum);
			isExed = true;//是
	}
		Director  *dir = Director::getInstance();
		dir->replaceScene(StartScene::createScene());
}