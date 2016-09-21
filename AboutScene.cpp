#include "AboutScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include"AudioEngine.h"

using namespace  experimental;
USING_NS_CC;

using namespace cocostudio::timeline;

Scene* AboutScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = AboutScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool AboutScene::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
	
	bgImg = Sprite::create("aboutUsBgp.png");
	bgImg->setAnchorPoint(Vec2(0.5, 0.5));
	bgImg->setPosition(Vec2(384, 512));
	addChild(bgImg);
	/*
	//չʾ��Ϣ
	//�����ʵ���ʵ������xml�ļ����ص��ʵ���
			auto *chnStrings = Dictionary::createWithContentsOfFile("about.xml");
			//ͨ��xml�ļ��е�key��ȡvalue
			const char *str1 = ((String*)chnStrings->objectForKey("string1"))->getCString();
			//����һ����ǩ��ʾ����
			auto* label1 = Label::create(str1, "Arial", 36);
			label1->setPosition(320, 270);
			addChild(label1);

			const char *str2 = ((String*)chnStrings->objectForKey("string2"))->getCString();
			auto* label2 = Label::create(str2, "Arial", 36);
			label2->setPosition(320, 180);
			addChild(label2);
	
			const char *str3 = ((String*)chnStrings->objectForKey("string3"))->getCString();
			auto* label3 = Label::create(str3, "Arial", 36);
			label3->setPosition(320, 90);
			addChild(label3);
			*/
	
	//�ص�������
	Sprite*normal1 = Sprite::create("aboutUsCloseButtonNormal.png");
	Sprite*seleted1 = Sprite::create("aboutUsCloseButtonSelected.png");
	MenuItemSprite*setBtn1 = MenuItemSprite::create(normal1, seleted1, CC_CALLBACK_1(AboutScene::backToStartScene, this));
	Menu *btn1 = Menu::create(setBtn1, NULL);
	btn1->setAnchorPoint(Vec2(0.5, 0.5));
	btn1->setPosition(Vec2(721.5, 974));
	addChild(btn1);
    return true;
}


void AboutScene::backToStartScene(Ref *object) {
	Director *dir = Director::getInstance();
	dir->replaceScene(StartScene::createScene());
}