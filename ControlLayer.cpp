#include"ControlLayer.h"
#include"SimpleAudioEngine.h"
using namespace CocosDenshion;
ControlLayer::ControlLayer() : pPauseItem(NULL), pMusicItem(NULL), m_score(NULL), Score_label(NULL)
{

}

bool ControlLayer::init() {
	if (!Layer::init()) {
		return false;
	}
	//��ӷ����ı�ǩ

	//��Ϸ������ť����
	/*Sprite *normalMusic = Sprite::create("game_musicPause.png");
	Sprite *pressedMusic = Sprite::create("game_musicPause.png");
	pMusicItem = MenuItemSprite::create(
		normalMusic,
		normalMusic,
		NULL,
		CC_CALLBACK_1(ControlLayer::menuMusicCallback, this));
		*/

	//��Ϸ��ͣ��ť
/*	Sprite *normalPause = Sprite::create("game_resume_nor.png");
	Sprite *pressedPause = Sprite::create("game_resume_pressed.png");
	pPauseItem = MenuItemSprite::create(
		normalPause,
		pressedPause,
		NULL,
		CC_CALLBACK_1(ControlLayer::menuPauseCallback, this));
		*/
	/*Menu *menuPause = Menu::create(pMusicItem, pPauseItem, NULL);
	menuPause->alignItemsHorizontallyWithPadding(pPauseItem->getContentSize().width / 2);
	menuPause->setPosition(
		Point(winSize.width - pPauseItem->getContentSize().width * 2, winSize.height - normalPause->getContentSize().height));
	this->addChild(menuPause);*/
	return true;
}

//��Ϸ��ͣ
/*void ControlLayer::menuPauseCallback(cocos2d::Ref* pSender)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/button.mp3");
	if (!Director::getInstance()->isPaused())
	{
		// ͼ��״̬����
		pPauseItem->setNormalImage(Sprite::create("game_pause_nor.png"));
		pPauseItem->setSelectedImage(Sprite::create("game_pause_press.png"));
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic(); // ֹͣ��������
		SimpleAudioEngine::getInstance()->stopAllEffects(); // ֹͣ���е���Ч
		Director::getInstance()->pause(); // ֹͣ���еĶ������л����У��ӵ�ǰ����
	}
	else
	{
		pPauseItem->setNormalImage(Sprite::create("game_resume_nor.png"));
		pPauseItem->setSelectedImage(Sprite::create("game_resume_pressed.png"));
		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();// �ָ�
		Director::getInstance()->resume(); // �ָ�
	}
}*/

/*void ControlLayer::menuMusicCallback(cocos2d::Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button.mp3");
	if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
	{
		// ͼ��״̬����
		pMusicItem->setNormalImage(Sprite::create("game_music.png"));
		pMusicItem->setSelectedImage(Sprite::create("game_music.png"));
		SimpleAudioEngine::getInstance()->stopBackgroundMusic(); // ֹͣ��������
																				//		CocosDenshion::SimpleAudioEngine::getInstance()->stopAllEffects(); // ֹͣ���е���Ч
	}
	else
	{
		pMusicItem->setNormalImage(Sprite::create("game_musicPause.png"));
		pMusicItem->setSelectedImage(Sprite::create("game_musicPause.png"));
		SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/BackgroundMusic.mp3", true);// �ָ�
																												//		CocosDenshion::SimpleAudioEngine::getInstance()->resumeAllEffects();
	}
}
*/