
#include "ExitScene.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio\CocoStudio.h"
#include"FirstScene.h"
using namespace cocos2d::ui;
USING_NS_CC;
using namespace cocos2d::extension;
//������Ⱦ��
Scene* ExitScene::createScene(RenderTexture* rt)
{
	Scene* scene = Scene::create();
	ExitScene* layer = ExitScene::create();
	auto sprite = Sprite::createWithTexture(rt->getSprite()->getTexture());
	sprite->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
	sprite->setFlippedY(true);
	scene->addChild(sprite, 0);

	scene->addChild(layer);

	return scene;
}

bool ExitScene::init() {

	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 100)))
	{
		return false;
	}
	auto layerOut = Sprite::create("exitGameBox.png");
	layerOut->setAnchorPoint(Vec2(0.5, 0.5));
	layerOut->setPosition(Vec2(384, 512));
	addChild(layerOut, 1, 3);

	//�Ի����е������˵���ť��������״̬�����״̬�µ�ͼƬ
	auto  normalLeftButton = Sprite::create("exitGameSureButtonNormal.png");
	auto  normalRightButton = Sprite::create("exitGameCancelButtonNormal.png");
	auto selectLeftButton = Sprite::create("exitGameSureButtonSelected.png");
	auto selectRightButton = Sprite::create("exitGameCancelButtonSelected.png");

	//ȷ���˳���ť
	auto itemSureMenu = MenuItemSprite::create(normalLeftButton, selectLeftButton, CC_CALLBACK_1(ExitScene::exitGame, this));
	itemSureMenu->setAnchorPoint(Point(0.5, 0));
	itemSureMenu->setPosition(layerOut->getContentSize().width*0.25, 60);
	itemSureMenu->setTag(1);

	//ȡ���˳���ť
	auto itemCancelMenu = MenuItemSprite::create(normalRightButton, selectRightButton, CC_CALLBACK_1(ExitScene::exitGame, this));
	itemCancelMenu->setAnchorPoint(Point(0.5, 0));
	itemCancelMenu->setPosition(layerOut->getContentSize().width*0.75, 60);
	itemCancelMenu->setTag(2);

	auto menu = Menu::create(itemSureMenu, itemCancelMenu, nullptr);
	menu->setPosition(Point::ZERO);
	layerOut->addChild(menu);

	return true;
}
//�˳���Ϸ
void ExitScene::exitGame(Ref *object) {

	auto menuItem = (MenuItem*)(object);
	switch (menuItem->getTag()) {
	case 1:
		log("repleaceScene");//ȷ���˳���Ϸ
		exit(0);
		break;
	case 2:
		Director::getInstance()->replaceScene(StartScene::createScene());//��������ʧ
		break;
	default:
		break;
	}
}
		