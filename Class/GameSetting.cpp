#include "GameSetting.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameSetting::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameSetting::create();

	layer->setOpacity(50);
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameSetting::init()
{
  
    if ( !Layer::init() )
    {
        return false;
    }
	soundControl = Sprite::create("volumeFrame.png");
	soundControl->setAnchorPoint(Vec2(0.5, 0.5));
	soundControl->setPosition(Vec2(544.50,875));
	addChild(soundControl); 

	auto slider = Slider::create();
	slider->loadBarTexture("volumeFrame.png");
	slider->loadSlidBallTextures("volumeMoveDotButtonNormal.png", "volumeMoveDotButtonSelected.png", "volumeMoveDotButtonNormal.png");
	slider->loadProgressBarTexture("volumeStripNormal.png");
	slider->addTouchEventListener([&](Ref *sender, Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			break;
		default:
			break;
		}
	});
	addChild(slider,9);
	slider->setAnchorPoint(Vec2(0.5, 0.5));
	slider->setPosition(Vec2(544.50, 875));
    return true;
}
