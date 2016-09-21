#include "StartScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "PauseLayer.h"
#include "ExitScene.h"
#include"Leaderboard.h"
#include "ChoseScene.h"
USING_NS_CC;
using namespace cocostudio::timeline;

Scene* StartScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = StartScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
int GameMusicID;
// on "init" you need to initialize your instance
bool StartScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	//��ȡ��Ļ��С
	visibleSize = Director::getInstance()->getVisibleSize();

	//����
	bgImg = Sprite::create("mainBgp.png");
	bgImg->setAnchorPoint(Vec2(0, 0));
	bgImg->setPosition(Vec2(0,0));
	addChild(bgImg);


	//�ɻ�����Ч��
	extern bool isFly;

	if (isFly) {
		planeImg = Sprite::create("plane.png");
		planeImg->setAnchorPoint(Vec2(0.5, 0.5));
		planeImg->setPosition(Vec2(-171.5, -50));
		MoveTo *to = MoveTo::create(3, Vec2(360, 640));
		auto  moveEaseIn = EaseExponentialInOut::create(to->clone());
		planeImg->runAction(moveEaseIn);
		addChild(planeImg, 1);
	}
	else {
		planeImg = Sprite::create("plane.png");
		planeImg->setAnchorPoint(Vec2(0.5, 0.5));
		planeImg->setPosition(Vec2(360, 640));
		addChild(planeImg, 1);
	}

	//������ʼ��ť
	Sprite*normal0 = Sprite::create("startGameButtonNormal.png");
	Sprite*seleted0 = Sprite::create("startGameButtonSelected.png");
	MenuItemSprite*setBtn0 = MenuItemSprite::create(normal0, seleted0, CC_CALLBACK_1(StartScene::changeToGameScene, this));
	Menu *btn0 = Menu::create(setBtn0, NULL);
	btn0->setAnchorPoint(Vec2(0.5, 0.5));
	btn0->setPosition(Vec2(226, 442.23));
	addChild(btn0);

	//�������ð�ť
	Sprite*normal1 = Sprite::create("setButtonNormal.png");
	Sprite*seleted1 = Sprite::create("setButtonSelected.png");
	MenuItemSprite*setBtn1 = MenuItemSprite::create(normal1, seleted1, CC_CALLBACK_1(StartScene::changeToSetScene,this));
	Menu *btn1= Menu::create(setBtn1, NULL);

	btn1->setAnchorPoint(Vec2(0.5, 0.5));
	btn1->setPosition(Vec2(721.5,974));
	addChild(btn1);
	//�����������ǰ�ť
	Sprite*normal2 = Sprite::create("aboutUsButtonNormal.png");
	Sprite*seleted2 = Sprite::create("aboutUsButtonSelected.png");
	MenuItemSprite*setBtn2 = MenuItemSprite::create(normal2, seleted2, CC_CALLBACK_1(StartScene::changeToAboutScene, this));
	Menu *btn2 = Menu::create(setBtn2, NULL);
	btn2->setAnchorPoint(Vec2(0.5, 0.5));
	btn2->setPosition(Vec2(225.50, 192.72));
	addChild(btn2);
	//�����˳�����
	Sprite*normal3 = Sprite::create("exitGameButtonNormal.png");
	Sprite*seleted3 = Sprite::create("exitGameButtonSelected.png");
	MenuItemSprite*setBtn3 = MenuItemSprite::create(normal3, seleted3, CC_CALLBACK_1(StartScene::confirmExitWhetherOrNot, this));
	Menu *btn3 = Menu::create(setBtn3, NULL);
	btn3->setAnchorPoint(Vec2(0.5, 0.5));
	btn3->setPosition(Vec2(541, 68.08));
	addChild(btn3);
	//���а�
	Sprite*normal4 = Sprite::create("rankingListButtonNormal.png");
	Sprite*seleted4 = Sprite::create("rankingListButtonSelected.png");
	MenuItemSprite*setBtn4 = MenuItemSprite::create(normal4, seleted4, CC_CALLBACK_1(StartScene::changeToRankListScene, this));
	Menu *btn4 = Menu::create(setBtn4, NULL);
	btn4->setAnchorPoint(Vec2(0.5, 0.5));
	btn4->setPosition(Vec2(541, 317.07));
	addChild(btn4);

    return true;
}

// �����������ý���
void StartScene::changeToSetScene(Ref* pSender)
{
	//�趨���������
	extern bool isFly;
	isFly = false;
	//Director::getInstance()->pause();

	/*��ȡ��ǰ������ͼƬ������*/

	auto size = Director::getInstance()->getWinSize();
	//RenderTexture��һ��������Ⱦ�࣬������Ҫ��Ҫ��Ⱦ�ĵ�ǰ�����Ž�ȥ�����ǳ�ʼ�����Ĵ�С
	render = RenderTexture::create(size.width, size.height);
	//��ʼ��ȡ����
	render->begin();
	//���ýڵ��visit�������뵽��Ⱦ��
	Director::getInstance()->getRunningScene()->visit();
	//����
	render->end();
	render->retain();

	//3.0 ������Ҫ�ڽ���������һ֡���ܴ���RenderTexture
	auto _schedule = this->getScheduler();
	auto replaceScene = [&](float tm)
	{
		//����л�����
		Director::getInstance()->pushScene(PauseLayer::createScene(render));
	};
	_schedule->schedule(replaceScene, this, 0.0f, 0, 0.0f, false, "screenshot");
}

//��ת����ʼ��Ϸ����
void StartScene::changeToGameScene(Ref *object) {
	//�趨���������
	extern int audioID;
	AudioEngine::pause(audioID);
	extern bool isFly;
	extern bool isExed;
	isFly = false;
	if (UserDefault::getInstance()->getBoolForKey("isMusicOpen")) {
		GameMusicID = AudioEngine::play2d("sound/Gaming.mp3", true);
		int percent = UserDefault::getInstance()->getIntegerForKey("percent");
		auto volum = 1.0f*percent / 100;
		AudioEngine::setVolume(GameMusicID, volum);
		isExed = true;
	}
	Director *dir = Director::getInstance();
	dir->replaceScene(ChoseScene::createScene());
}
//��ת�����а�
void StartScene::changeToRankListScene(Ref *object) {
	//�趨���������
	extern bool isFly;
	isFly = false;
	Director *dir = Director::getInstance();
	dir->replaceScene(Leaderboard::createScene());
	

}
//��ת����������
void StartScene::changeToAboutScene(Ref *object) {

	//�趨���������
	extern bool isFly;
	isFly = false;
	Director *dir = Director::getInstance();
	dir->replaceScene(AboutScene::createScene());
}
// �Ƴ�ȷ�ϵ���
void StartScene::confirmExitWhetherOrNot(Ref* pSender)
{
	//�趨���������
	extern bool isFly;
	isFly = false;
	//Director::getInstance()->pause();

	/*��ȡ��ǰ������ͼƬ������*/

	auto size = Director::getInstance()->getWinSize();
	//RenderTexture��һ��������Ⱦ�࣬������Ҫ��Ҫ��Ⱦ�ĵ�ǰ�����Ž�ȥ�����ǳ�ʼ�����Ĵ�С
	render = RenderTexture::create(size.width, size.height);
	//��ʼ��ȡ����
	render->begin();
	//���ýڵ��visit�������뵽��Ⱦ��
	Director::getInstance()->getRunningScene()->visit();
	//����
	render->end();
	render->retain();

	//3.0 ������Ҫ�ڽ���������һ֡���ܴ���RenderTexture
	auto _schedule = this->getScheduler();
	auto replaceScene = [&](float tm)
	{
		//����л�����
		Director::getInstance()->pushScene(ExitScene::createScene(render));
	};
	_schedule->schedule(replaceScene, this, 0.0f, 0, 0.0f, false, "screenshot1");
}

//�˳���Ϸ
void StartScene::exitGame(Ref *object) {
	
	auto menuItem = (MenuItem*)(object);
	switch (menuItem->getTag()) {
	case 1:
		log("repleaceScene");//ȷ���˳���Ϸ
		exit(0);
		break;
	case 2:
		(this->getChildByTag(3))->removeFromParent();//��������ʧ
		break;
	default:
		break;
	}
}