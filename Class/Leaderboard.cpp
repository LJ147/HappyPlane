#include "Leaderboard.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "PauseLayer.h"
#include "ExitScene.h"
#include "SimpleAudioEngine.h"
#include"UserDate.h"
USING_NS_CC;
using namespace CocosDenshion;
using namespace cocostudio::timeline;

Scene* Leaderboard::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Leaderboard::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Leaderboard::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto viewSize = Director::getInstance()->getVisibleSize();
	//加载背景
	BgImg = Sprite::create("rankingListBgp.png");
	BgImg->setAnchorPoint(Vec2(0.5, 0.5));
	BgImg->setPosition(Vec2(384, 512));
	addChild(BgImg);
	//返回按钮
	Sprite*normal = Sprite::create("aboutUsCloseButtonNormal.png");
	Sprite*seleted = Sprite::create("aboutUsCloseButtonSelected.png");
	MenuItemSprite*setBtn = MenuItemSprite::create(normal, seleted, CC_CALLBACK_1(Leaderboard::BackToStartScene, this));
	Menu *btn = Menu::create(setBtn, NULL);
	btn->setAnchorPoint(Vec2(0.5, 0.5));
	btn->setPosition(Vec2(720, 976.5));
	addChild(btn);
	Score = Label::createWithTTF("0", "YouYuan.ttf", 50);
	Score->setPosition(Vec2(384, 512));
	for (int i = 0; i < 3; i++) {
		int score = UserDefault::getInstance()->getIntegerForKey(StringUtils::format("%s%d",RANK_SCORE,i).c_str(),0);

		auto row = createChart(i, score);
		row->setPosition(Vec2(384, 512 + 220 - 140 * i));
		addChild(row);
	}
	return true;
}
//回到开始菜单
Node *Leaderboard::createChart(int rank, int score) {
	auto viewSize = Director::getInstance()->getVisibleSize();
	auto row = Node::create();
	auto s = Label::createWithTTF("0", "YouYuan.ttf", 50);
	s->setColor(Color3B::WHITE);
	char scoreFormat[20];
	sprintf(scoreFormat, "%d", score);
	s->setString(scoreFormat);
	s->setAnchorPoint(Vec2(0.5, 0.5));
	s->setPosition(Vec2(row->getContentSize().width + 400, 0));
	row->addChild(s);
	row->setContentSize(Size(viewSize.width, 100));
	row->setAnchorPoint(Vec2(0.5, 0.5));
	return row;
}
void Leaderboard::BackToStartScene(Ref *object) {
	Director *dir = Director::getInstance();
	dir->replaceScene(StartScene::createScene());
}