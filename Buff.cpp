#include "Buff.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;
//��ʼ������
bool Buff::initWithSpriteFrameName(const std::string&  spriteFrameName) {
	if (Sprite::initWithSpriteFrameName(spriteFrameName)) {
		return true;
	}
	return false;
}
//����buff���飬�ⲿ���ýӿ�
Buff* Buff::createBuff(const std::string&  spriteFrameName) {
	Buff *object = NULL;
	object = new Buff();
	object->initWithSpriteFrameName(spriteFrameName);
	return object;
}
