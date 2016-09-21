#include "HeroPlane.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

bool HeroPlane::initWithSpriteFrameName(const std::string&  spriteFrameName) {


	if (Sprite::initWithSpriteFrameName(spriteFrameName)) {
		minusHp = 0;
		currentHp = 100;
		totalHp = 100;
		IsDoubleShooting = false;
		IsRocketLoading = false;

		IsDead = false;


		return true;
	}
	return false;
}

HeroPlane* HeroPlane::createHeroPlane(const std::string&  spriteFrameName) {
	HeroPlane *object = NULL;
	object = new HeroPlane();
	object->initWithSpriteFrameName(spriteFrameName);
	//object->autorelease();

	return object;
}

void HeroPlane::LoseHP(float reducedHP)
{
	currentHp -= reducedHP;
}

void HeroPlane::addHP(float addedHP)
{
	currentHp = 100;
}

void HeroPlane::getADoubleShootingTool()
{
	IsDoubleShooting = true;
}

void HeroPlane::getARocketTool()
{
	IsRocketLoading = true;
}





