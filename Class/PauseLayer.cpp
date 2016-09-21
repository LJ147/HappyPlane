
#include "PauseLayer.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "StartScene.h"
#include "ui/CocosGUI.h"
#include "cocostudio\CocoStudio.h"
#include"FirstScene.h"
using namespace cocos2d::ui;

USING_NS_CC;
using namespace cocos2d::extension;


Scene* PauseLayer::createScene(RenderTexture* rt)
{
	Scene* scene = Scene::create();
	PauseLayer* layer = PauseLayer::create();



	auto sprite = Sprite::createWithTexture(rt->getSprite()->getTexture());
	sprite->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
	sprite->setFlippedY(true);
	scene->addChild(sprite, 0);

	scene->addChild(layer);

	return scene;
}

bool PauseLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 100)))
	{
		return false;
	}
	
	
	// 背景图片
	volumeSlider = Sprite::create("volumeStripNormal.png");
	volumeSlider->setAnchorPoint(Vec2(0.5, 0.5));
	volumeSlider->setPosition(Vec2(580, 868));
	addChild(volumeSlider);
	volumeBackground = Sprite::create("volumeFrame.png");
	volumeBackground->setPosition(Vec2(544.5, 875));
	this->addChild(volumeBackground);

	//静音开关
	int percent = UserDefault::getInstance()->getIntegerForKey("percent");
	if (soundOpen) {
		Sprite*normal4 = Sprite::create("volumeOpenButton.png");
		Sprite*seleted4 = Sprite::create("volumeCloseButton.png");
		setBtn= MenuItemSprite::create(normal4, seleted4, CC_CALLBACK_1(PauseLayer::controlGameSound, this));
		Menu *btn4 = Menu::create(setBtn, NULL);
		btn4->setAnchorPoint(Vec2(0.5, 0.5));
		btn4->setPosition(Vec2(385, 868));
		addChild(btn4);
	}
	else {
		Sprite*normal4 = Sprite::create("volumeOpenButton.png");
		Sprite*seleted4 = Sprite::create("volumeCloseButton.png");
		setBtn = MenuItemSprite::create(seleted4, normal4, CC_CALLBACK_1(PauseLayer::controlGameSound, this));
		Menu *btn4 = Menu::create(setBtn, NULL);
		btn4->setAnchorPoint(Vec2(0.5, 0.5));
		btn4->setPosition(Vec2(385, 868));
		addChild(btn4);
	}
	auto slider = Slider::create();
	slider->loadBarTexture("volumeFrame1.png");
	slider->loadSlidBallTextures("volumeMoveDotButtonNormal.png", "volumeMoveDotButtonSelected.png", "volumeMoveDotButtonNormal.png");
	slider->loadProgressBarTexture("volume.png");
	slider->setPercent(percent);

	slider->addTouchEventListener([&](Ref *sender, Slider::TouchEventType type) {
	
			auto s = dynamic_cast<Slider *>(sender);
			auto volum = 1.0f*s->getPercent() / s->getMaxPercent();//计算音量的平均值，音量的值应为：0~1
			extern int audioID;
			if (audioID != AudioEngine::INVALID_AUDIO_ID) {
				AudioEngine::setVolume(audioID, volum);
				UserDefault::getInstance()->setIntegerForKey("percent", s->getPercent());
				UserDefault::getInstance()->setBoolForKey("isMusicOpen", soundOpen);
			
		}
	});
	addChild(slider, 9);
	slider->setAnchorPoint(Vec2(0.5, 0.5));
	slider->setPosition(Vec2(580, 868));
	
	

	

	auto volumeSettingItem = MenuItemSprite::create(
		Sprite::create("setButtonNormal.png"),
		Sprite::create("setButtonSelected.png"),
		[&](Ref * ref) {

	
		Director *dir = Director::getInstance();
		dir->replaceScene(StartScene::createScene());

	});
	volumeSettingItem->setPosition(Vec2(721.5, 974));

	auto menu = Menu::create(volumeSettingItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);
	return true;

}
	
void PauseLayer::onEnter() {
	Layer::onEnter();
	AudioEngine::lazyInit();
	AudioEngine::preload("sound/BgMusic.mp3");
}
void PauseLayer::onExit() {

	extern int audioID;
		if (audioID != AudioEngine::INVALID_AUDIO_ID) {
			AudioEngine::uncache("sound/BgMusic.mp3");//清除音乐文件的缓存
		}
		Layer::onExit();
}
	void PauseLayer::controlGameSound(Ref *object) {
		extern int audioID;
		MenuItemSprite *btn = (MenuItemSprite *)object;
		if (soundOpen) {
			soundOpen = false;
			AudioEngine::pause(audioID);
			btn->setNormalImage(Sprite::create("volumeCloseButton.png"));
		}
		else {
			soundOpen = true;
			extern bool isExed;
			if (!isExed) {
				audioID = AudioEngine::play2d("BgMusic.mp3", true);
				AudioEngine::setVolume(audioID, 1);
				int percent = UserDefault::getInstance()->getIntegerForKey("percent");
				auto volum = 1.0f*percent / 100;
				AudioEngine::setVolume(audioID, volum);
			}
			AudioEngine::resume(audioID);
			btn->setNormalImage(Sprite::create("volumeOpenButton.png"));
		}
		UserDefault::getInstance()->setBoolForKey("isMusicOpen", soundOpen);
	}
	
	void PauseLayer::changeClosePicture(Ref *object) {
		MenuItemSprite *btn = (MenuItemSprite *)object;
		btn->setNormalImage(Sprite::create("volumeCloseButton.png"));
	}

	void PauseLayer::changeOpenPicture(Ref *object) {
		MenuItemSprite *btn = (MenuItemSprite *)object;
		btn->setNormalImage(Sprite::create("volumeOpenButton.png"));
	}