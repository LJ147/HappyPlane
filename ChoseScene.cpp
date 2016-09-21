#include "ChoseScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "PauseLayer.h"
#include "ExitScene.h"
#include"Leaderboard.h"
#include"SecondScene.h"
#include"ThirdScene.h"
USING_NS_CC;
using namespace cocostudio::timeline;
//����ȫ�ֱ���������ת���ؿ���������Ϸ����
int a;

Scene* ChoseScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ChoseScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
bool ChoseScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	//���ر���ͼƬ
	bgImg = Sprite::create("selectLevelBgp.png");
	bgImg->setAnchorPoint(Vec2(0.5, 0.5));
	bgImg->setPosition(Vec2(384, 512));
	addChild(bgImg);
	//������һ�صİ�ť
	Sprite*normal0 = Sprite::create("firstLevelButtonNormal.png");
	Sprite*seleted0 = Sprite::create("firstLevelButtonSelected.png");
	MenuItemSprite*setBtn0 = MenuItemSprite::create(normal0, seleted0, CC_CALLBACK_1(ChoseScene::changeToFirst, this));
	Menu *btn0 = Menu::create(setBtn0, NULL);
	btn0->setAnchorPoint(Vec2(0.5, 0.5));
	btn0->setPosition(Vec2(384, 675.55));
	addChild(btn0);
	//�����ڶ��صİ�ť
	Sprite*normal1 = Sprite::create("secondLevelButtonNormal.png");
	Sprite*seleted1 = Sprite::create("secondLevelButtonSelected.png");
	MenuItemSprite*setBtn1 = MenuItemSprite::create(normal1, seleted1, CC_CALLBACK_1(ChoseScene::changeToSecond, this));
	Menu *btn1 = Menu::create(setBtn1, NULL);
	btn1->setAnchorPoint(Vec2(0.5, 0.5));
	btn1->setPosition(Vec2(384, 535.09));
	addChild(btn1);
	//���������صİ�ť
	Sprite*normal2 = Sprite::create("thirdLevelButtonNormal.png");
	Sprite*seleted2 = Sprite::create("thirdLevelButtonSelected.png");
	MenuItemSprite*setBtn2 = MenuItemSprite::create(normal2, seleted2, CC_CALLBACK_1(ChoseScene::changeToThird, this));
	Menu *btn2 = Menu::create(setBtn2, NULL);
	btn2->setAnchorPoint(Vec2(0.5, 0.5));
	btn2->setPosition(Vec2(384, 388.53));
	addChild(btn2);

	//�������ð�ť
	Sprite*normal3 = Sprite::create("aboutUsCloseButtonNormal.png");
	Sprite*seleted3 = Sprite::create("aboutUsCloseButtonSelected.png");
	MenuItemSprite*setBtn3 = MenuItemSprite::create(normal3, seleted3, CC_CALLBACK_1(ChoseScene::backToStartScene, this));
	Menu *btn3 = Menu::create(setBtn3, NULL);
	btn3->setAnchorPoint(Vec2(0.5, 0.5));
	btn3->setPosition(Vec2(720, 976.50));
	addChild(btn3);
    return true;
}
//�ص����� ��ת����һ�أ���ʹȫ�ֱ���a��ֵΪ1
void ChoseScene::changeToFirst(Ref *object) {
	a = 1;
	Director *dir = Director::getInstance();
	dir->replaceScene(MainGame::createScene());
}
//�ص�������ת���ڶ��أ���ʹȫ�ֱ���a��ֵΪ2
void ChoseScene::changeToSecond(Ref *object) {
	a = 2;
	Director *dir = Director::getInstance();
	dir->replaceScene(SecondScene::createScene());
}
//�ص�������ת�������أ���ʹȫ�ֱ���a��ֵΪ3
void ChoseScene::changeToThird(Ref *object) {
	a = 3;
	Director *dir = Director::getInstance();
	dir->replaceScene(ThirdScene::createScene());
}
//�ص����������ص������� ������ȫ�ֱ������Ʊ������ֵĿ���
void ChoseScene::backToStartScene(Ref *object) {
	extern int GameMusicID;
	AudioEngine::stop(GameMusicID);//ֹͣ��ǰ����
	if (soundOpen) {
		extern int audioID;
		int percent1 = UserDefault::getInstance()->getIntegerForKey("percent");//����slide�İٷֱ����������Ĵ�С
		log(percent1);
		auto volum = 1.0f*percent1 / 100;
		AudioEngine::setVolume(audioID, volum);
		audioID = AudioEngine::play2d("sound/BgMusic.mp3", true, volum);//������һ�ױ�������
	}
	Director *dir = Director::getInstance();
	dir->replaceScene(StartScene::createScene());//��ת��������
}