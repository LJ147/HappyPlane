
#include "Victory.h"
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


Scene* Victory::createScene(RenderTexture* rt)
{
	Scene* scene = Scene::create();
	Victory* layer = Victory::create();



	auto sprite = Sprite::createWithTexture(rt->getSprite()->getTexture());
	sprite->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
	sprite->setFlippedY(true);
	scene->addChild(sprite, 0);

	scene->addChild(layer);

	return scene;
}

bool Victory::init() {

	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 100)))
	{
		return false;
	}
	this->pause();
	
	bgImg = Sprite::create("gameWinBox.png");
	bgImg->setAnchorPoint(Vec2(0.5, 0.5));
	bgImg->setPosition(Vec2(384, 512));
	addChild(bgImg);

	//对话框中得两个菜单按钮，在正常状态、点击状态下的图片
	auto  winNextLevelButtonNormal = Sprite::create("winNextLevelButtonNormal.png");
	auto  winNextLevelButtonSelected = Sprite::create("winNextLevelButtonSelected.png");
	auto menuButtonNormal = Sprite::create("menuButtonNormal.png");
	auto menuButtonSelected = Sprite::create("menuButtonSelected.png");
	auto itemSureMenu = MenuItemSprite::create(winNextLevelButtonNormal, winNextLevelButtonSelected, CC_CALLBACK_1(Victory::nextLevel, this));
	itemSureMenu->setAnchorPoint(Point(0.5, 0.5));
	itemSureMenu->setPosition(Vec2(290,430));
	itemSureMenu->setTag(1);

	//
	auto itemCancelMenu = MenuItemSprite::create(menuButtonNormal, menuButtonSelected, CC_CALLBACK_1(Victory::backToStartScene, this));
	itemCancelMenu->setAnchorPoint(Point(0.5, 0.5));
	itemCancelMenu->setPosition(Vec2(520,430));
	itemCancelMenu->setTag(2);

	auto menu = Menu::create(itemSureMenu, itemCancelMenu, nullptr);
	menu->setPosition(Point::ZERO);
	bgImg->addChild(menu);

	int currentscore = UserDefault::getInstance()->getIntegerForKey(NEW_SCORE);
	score = Label::createWithTTF("Score  : 0", "arial.ttf", 45);
	score->setAnchorPoint(Vec2(0.5, 0.5));
	score->setPosition(Vec2(400, 512));
	score->setColor(Color3B(225, 225, 225));
	char total[20];
	sprintf(total, "Score : %d", currentscore);
	score->setString(total);
	score->setContentSize(Size(200, 80));
	addChild(score, 1);
	return true;
}
void Victory::nextLevel(Ref *object) {
	extern int a;
	if (a == 1) {
		Director*dir = Director::getInstance();
		dir->replaceScene(SecondScene::createScene());
	}
	else if (a == 2) {
		Director*dir = Director::getInstance();
		dir->replaceScene(ThirdScene::createScene());
	}else if(a==3){
		Director*dir = Director::getInstance();
		dir->replaceScene(StartScene::createScene());
	}
	
}
void Victory::backToStartScene(Ref *object) {
	Director *dir = Director::getInstance();
	dir->replaceScene(StartScene::createScene());
}


