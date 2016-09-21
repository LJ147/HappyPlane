#include "Buff.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;
//初始化函数
bool Buff::initWithSpriteFrameName(const std::string&  spriteFrameName) {
	if (Sprite::initWithSpriteFrameName(spriteFrameName)) {
		return true;
	}
	return false;
}
//创建buff精灵，外部调用接口
Buff* Buff::createBuff(const std::string&  spriteFrameName) {
	Buff *object = NULL;
	object = new Buff();
	object->initWithSpriteFrameName(spriteFrameName);
	return object;
}
