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
	//添加分数的标签

	//游戏声音按钮控制
	/*Sprite *normalMusic = Sprite::create("game_musicPause.png");
	Sprite *pressedMusic = Sprite::create("game_musicPause.png");
	pMusicItem = MenuItemSprite::create(
		normalMusic,
		normalMusic,
		NULL,
		CC_CALLBACK_1(ControlLayer::menuMusicCallback, this));
		*/

	//游戏暂停按钮
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

//游戏暂停
/*void ControlLayer::menuPauseCallback(cocos2d::Ref* pSender)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/button.mp3");
	if (!Director::getInstance()->isPaused())
	{
		// 图标状态设置
		pPauseItem->setNormalImage(Sprite::create("game_pause_nor.png"));
		pPauseItem->setSelectedImage(Sprite::create("game_pause_press.png"));
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic(); // 停止背景音乐
		SimpleAudioEngine::getInstance()->stopAllEffects(); // 停止所有的特效
		Director::getInstance()->pause(); // 停止所有的动作，敌机飞行，子弹前进等
	}
	else
	{
		pPauseItem->setNormalImage(Sprite::create("game_resume_nor.png"));
		pPauseItem->setSelectedImage(Sprite::create("game_resume_pressed.png"));
		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();// 恢复
		Director::getInstance()->resume(); // 恢复
	}
}*/

/*void ControlLayer::menuMusicCallback(cocos2d::Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/button.mp3");
	if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
	{
		// 图标状态设置
		pMusicItem->setNormalImage(Sprite::create("game_music.png"));
		pMusicItem->setSelectedImage(Sprite::create("game_music.png"));
		SimpleAudioEngine::getInstance()->stopBackgroundMusic(); // 停止背景音乐
																				//		CocosDenshion::SimpleAudioEngine::getInstance()->stopAllEffects(); // 停止所有的特效
	}
	else
	{
		pMusicItem->setNormalImage(Sprite::create("game_musicPause.png"));
		pMusicItem->setSelectedImage(Sprite::create("game_musicPause.png"));
		SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/BackgroundMusic.mp3", true);// 恢复
																												//		CocosDenshion::SimpleAudioEngine::getInstance()->resumeAllEffects();
	}
}
*/