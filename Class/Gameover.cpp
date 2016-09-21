#include "Gameover.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio\CocoStudio.h"
#include"MainGame.h"
#include "StartScene.h"
#include"UserDate.h"
#include"SecondScene.h"
#include"ThirdScene.h"

using namespace cocos2d::ui;
using namespace cocos2d::extension;

USING_NS_CC;


Scene* Gameover::createScene(RenderTexture* rt)
{
	Scene* scene = Scene::create();
	Gameover* layer = Gameover::create();



	auto sprite = Sprite::createWithTexture(rt->getSprite()->getTexture());
	sprite->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
	sprite->setFlippedY(true);
	scene->addChild(sprite, 0);

	scene->addChild(layer);

	return scene;
}

bool Gameover::init() {

	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 100)))
	{
		return false;
	}
	this->pause();
	bgImg = Sprite::create("gameOverBox.png");
	bgImg->setAnchorPoint(Vec2(0.5, 0.5));
	bgImg->setPosition(Vec2(384, 512));
	addChild(bgImg);

	//对话框中得两个菜单按钮，在正常状态、点击状态下的图片
	auto  restartButtonNormal = Sprite::create("restartButtonNormal.png");
	auto  restartButtonSelected = Sprite::create("restartButtonSelected.png");
	auto menuButtonNormal = Sprite::create("menuButtonNormal.png");
	auto menuButtonSelected = Sprite::create("menuButtonSelected.png");
	auto itemSureMenu = MenuItemSprite::create(restartButtonNormal, restartButtonSelected, CC_CALLBACK_1(Gameover::reStart, this));
	itemSureMenu->setAnchorPoint(Point(0.5, 0.5));
	itemSureMenu->setPosition(Vec2(270,430));
	itemSureMenu->setTag(1);

	//
	auto itemCancelMenu = MenuItemSprite::create(menuButtonNormal, menuButtonSelected, CC_CALLBACK_1(Gameover::backToStartScene, this));
	itemCancelMenu->setAnchorPoint(Point(0.5, 0.5));
	itemCancelMenu->setPosition(Vec2(510, 430));
	itemCancelMenu->setTag(2);

	auto menu = Menu::create(itemSureMenu, itemCancelMenu, nullptr);
	menu->setPosition(Point::ZERO);
	bgImg->addChild(menu);

	int currentscore = UserDefault::getInstance()->getIntegerForKey(NEW_SCORE);
	score= Label::createWithTTF("Score: 0", "arial.ttf",45);
	score->setAnchorPoint(Vec2(0.5, 0.5));
	score->setPosition(Vec2(400, 512));
	score->setColor(Color3B(225,225, 225));

	char total[20];
	sprintf(total, "Score: %d", currentscore);
	log("Score: %s", total);
	score->setString(total);

	score->setContentSize(Size(200, 80));
	addChild(score, 1);
	return true;
}
void Gameover::reStart(Ref *object) {
	extern int a;
	extern int GameMusicID;
	extern bool isRun;
	if (a == 1) {
		Director*dir = Director::getInstance();
		dir->replaceScene(MainGame::createScene());

		if (soundOpen)
		{
			isRun = false;
			int percent = UserDefault::getInstance()->getIntegerForKey("percent");
			auto volum = 1.0f*percent / 100;
			//AudioEngine::setVolume(GameMusicID, volum);
			GameMusicID = AudioEngine::play2d("sound/Gaming.mp3", true, volum);
		}
		else
		{
			isRun = true;
		}
	}
	else if (a == 2) {
		Director*dir = Director::getInstance();
		dir->replaceScene(SecondScene::createScene());
		if (soundOpen)
		{
			isRun = false;
			int percent = UserDefault::getInstance()->getIntegerForKey("percent");
			auto volum = 1.0f*percent / 100;
			//AudioEngine::setVolume(GameMusicID, volum);
			GameMusicID = AudioEngine::play2d("sound/Gaming.mp3", true, volum);
		}
		else
		{
			isRun = true;
		}
	}else if(a==3){
		Director*dir = Director::getInstance();
		dir->replaceScene(ThirdScene::createScene());
		if (soundOpen)
		{
			isRun = false;
			int percent = UserDefault::getInstance()->getIntegerForKey("percent");
			auto volum = 1.0f*percent / 100;
			//AudioEngine::setVolume(GameMusicID, volum);
			GameMusicID = AudioEngine::play2d("sound/Gaming.mp3", true, volum);
		}
		else
		{
			isRun = true;
		}
	}
	
}
void Gameover::backToStartScene(Ref *object) {
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
	Director *dir = Director::getInstance();
	dir->replaceScene(StartScene::createScene());
}