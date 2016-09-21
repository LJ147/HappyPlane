#include "Bullet.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;
//初始化函数
bool Bullet::initWithSpriteFrameName(const std::string&  spriteFrameName) {
	if (Sprite::initWithSpriteFrameName(spriteFrameName)) {
		type = bullet_def;
		return true;
	}
	return false;
}
//创建子弹精灵，外部调用接口
Bullet* Bullet::createBullet(const std::string&  spriteFrameName) {
	Bullet *object = NULL;
	object = new Bullet();
	object->initWithSpriteFrameName(spriteFrameName);
	//object->autorelease();

	return object;
}
