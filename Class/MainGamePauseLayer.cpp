
#include "MainGamePauseLayer.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio\CocoStudio.h"
#include"MainGame.h"
#include "StartScene.h"
#include "SecondScene.h"
#include "ThirdScene.h"

using namespace cocos2d::ui;
using namespace cocos2d::extension;

USING_NS_CC;
//bool soundOpen = UserDefault::getInstance()->getBoolForKey("isMusicOpen");
bool isRun = false;
Scene* MainGamePauseLayer::createScene(RenderTexture* rt)
{
	Scene* scene = Scene::create();
	MainGamePauseLayer* layer = MainGamePauseLayer::create();



	auto sprite = Sprite::createWithTexture(rt->getSprite()->getTexture());
	sprite->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
	sprite->setFlippedY(true);
	scene->addChild(sprite, 0);

	scene->addChild(layer);

	return scene;
}

bool MainGamePauseLayer::init() {

	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 100)))
	{
		return false;
	}
	this->pause();
	
	visibleSize = Director::getInstance()->getVisibleSize();

	//对话框背景图
	auto layerOut = Sprite::create("pauseBox.png");
	layerOut->setAnchorPoint(Vec2(0.5, 0.5));
	layerOut->setPosition(Vec2(384,512));
	addChild(layerOut, 1, 3);

	volumeSlider = Sprite::create("volumeStripNormal.png");
	volumeSlider->setAnchorPoint(Vec2(0.5, 0.5));
	volumeSlider->setPosition(Vec2(435, 542));
	addChild(volumeSlider, 9);

	int percent = UserDefault::getInstance()->getIntegerForKey("percent");
	if (soundOpen) {
		Sprite*normal4 = Sprite::create("volumeOpenButton.png");
		Sprite*seleted4 = Sprite::create("volumeCloseButton.png");
		setBtn = MenuItemSprite::create(normal4, seleted4, CC_CALLBACK_1(MainGamePauseLayer::controlGameSound, this));
		Menu *btn4 = Menu::create(setBtn, NULL);
		btn4->setAnchorPoint(Vec2(0.5, 0.5));
		btn4->setPosition(Vec2(210, 542));
		addChild(btn4, 9);
	}
	else {
		Sprite*normal4 = Sprite::create("volumeOpenButton.png");
		Sprite*seleted4 = Sprite::create("volumeCloseButton.png");
		setBtn = MenuItemSprite::create(seleted4, normal4, CC_CALLBACK_1(MainGamePauseLayer::controlGameSound, this));
		Menu *btn4 = Menu::create(setBtn, NULL);
		btn4->setAnchorPoint(Vec2(0.5, 0.5));
		btn4->setPosition(Vec2(210, 542));
		addChild(btn4, 9);
	}

	auto slider = Slider::create();
	slider->loadBarTexture("volumeFrame1.png");
	slider->loadSlidBallTextures("volumeMoveDotButtonNormal.png", "volumeMoveDotButtonSelected.png", "volumeMoveDotButtonNormal.png");
	slider->loadProgressBarTexture("volume.png");
	slider->setPercent(percent);

	slider->addTouchEventListener([&](Ref *sender, Slider::TouchEventType type) {

		auto s = dynamic_cast<Slider *>(sender);
		auto volum = 1.0f*s->getPercent() / s->getMaxPercent();//计算音量的平均值，音量的值应为：0~1
		extern int GameMusicID;
		if (GameMusicID != AudioEngine::INVALID_AUDIO_ID) {
			AudioEngine::setVolume(GameMusicID, volum);
			UserDefault::getInstance()->setIntegerForKey("percent", s->getPercent());
			UserDefault::getInstance()->setBoolForKey("isMusicOpen", soundOpen);

		}
	});
	addChild(slider, 9);
	slider->setAnchorPoint(Vec2(0.5, 0.5));
	slider->setPosition(Vec2(426, 542));



	//对话框中得两个菜单按钮，在正常状态、点击状态下的图片
	auto  normalContinueButton = Sprite::create("continueButtonNormal.png");
	auto  normalPlayAgainButton = Sprite::create("restartButtonNormal.png");
	auto  normalMainMenuButton = Sprite::create("menuButtonNormal.png");

	auto selectdContinueButton = Sprite::create("continueButtonSelected.png");
	auto selectdContinueiButton = Sprite::create("restartButtonSelected.png");
	auto selectdMainMenuButton = Sprite::create("menuButtonSelected.png");

	//
	auto itemContinueMenu = MenuItemSprite::create(normalContinueButton, selectdContinueButton, CC_CALLBACK_1(MainGamePauseLayer::continueGame, this));
	itemContinueMenu->setAnchorPoint(Point(0.4, 0));
	itemContinueMenu->setPosition(layerOut->getContentSize().width*0.35, 380);
	itemContinueMenu->setTag(1);
	/*
	auto itemRestartMenu = MenuItemSprite::create(normalPlayAgainButton, selectdContinueiButton, CC_CALLBACK_1(MainGamePauseLayer::reStartGame, this));
	itemRestartMenu->setAnchorPoint(Point(0.5, 0));
	itemRestartMenu->setPosition(layerOut->getContentSize().width*0.5, 360);
	itemRestartMenu->setTag(2);
	*/
	//
	auto itemMainGameMenu = MenuItemSprite::create(normalMainMenuButton, selectdMainMenuButton, CC_CALLBACK_1(MainGamePauseLayer::mainMenu, this));
	itemMainGameMenu->setAnchorPoint(Point(0.5, 0));
	itemMainGameMenu->setPosition(visibleSize.width*0.65, 380);
	itemMainGameMenu->setTag(2);

	auto menu = Menu::create(itemContinueMenu, itemMainGameMenu, nullptr);
	menu->setPosition(Point::ZERO);
	layerOut->addChild(menu);

	return true;
}

void MainGamePauseLayer::continueGame(Ref * object)
{
	resume();
	Director::getInstance()->popScene();
}

void MainGamePauseLayer::reStartGame(Ref * object)
{

	extern int GameMusicID;
	AudioEngine::stop(GameMusicID);
	if (soundOpen) {
		isRun = false;
		int percent = UserDefault::getInstance()->getIntegerForKey("percent");
		auto volum = 1.0f*percent / 100;
		//AudioEngine::setVolume(GameMusicID, volum);
		GameMusicID = AudioEngine::play2d("sound/Gaming.mp3", true, volum);
	}
	else {
		isRun = true;
	}
	extern int a;
	if (a == 1) {
		Director::getInstance()->replaceScene(MainGame::createScene());
	}
	else if (a == 2) {
		Director::getInstance()->replaceScene(SecondScene::createScene());
	}
	else if (a == 3) {
		Director::getInstance()->replaceScene(ThirdScene::createScene());
	}


	Director::getInstance()->replaceScene(MainGame::createScene());
}

void MainGamePauseLayer::mainMenu(Ref * object)
{
	extern int GameMusicID;
	AudioEngine::stop(GameMusicID);
	if (soundOpen) {
		extern int audioID;
		int percent1 = UserDefault::getInstance()->getIntegerForKey("percent");
		log(percent1);
		auto volum = 1.0f*percent1 / 100;

		AudioEngine::setVolume(audioID, volum);

		log(volum);
		audioID = AudioEngine::play2d("sound/BgMusic.mp3", true, volum);

		//AudioEngine::setVolume(audioID, volum);
		log(volum);
	}

	Director::getInstance()->replaceScene(StartScene::createScene());//回到主菜单
}
void MainGamePauseLayer::onEnter() {
		Layer::onEnter();
		AudioEngine::lazyInit();
		AudioEngine::preload("sound/Gaming.mp3");
}

void MainGamePauseLayer::controlGameSound(Ref *object) {
	extern int GameMusicID;
	MenuItemSprite *btn = (MenuItemSprite *)object;
	if (soundOpen) {
		soundOpen = false;
		AudioEngine::pause(GameMusicID);
		btn->setNormalImage(Sprite::create("volumeCloseButton.png"));
	}
	else {
		soundOpen = true;
		extern bool isExed;
		if (!isExed) {
			GameMusicID = AudioEngine::play2d("sound/Gaming.mp3", true);
			AudioEngine::setVolume(GameMusicID, 1);
			int percent = UserDefault::getInstance()->getIntegerForKey("percent");
			auto volum = 1.0f*percent / 100;
		}else if(isRun)
		{
			GameMusicID = AudioEngine::play2d("sound/Gaming.mp3", true);
			AudioEngine::setVolume(GameMusicID, 1);
			int percent = UserDefault::getInstance()->getIntegerForKey("percent");
			auto volum = 1.0f*percent / 100;
		}
		else {
			AudioEngine::resume(GameMusicID);
		}
		
			
		
		
		AudioEngine::resume(GameMusicID);
		btn->setNormalImage(Sprite::create("volumeOpenButton.png"));
	}
	UserDefault::getInstance()->setBoolForKey("isMusicOpen", soundOpen);
}
