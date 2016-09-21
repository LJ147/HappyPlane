#include "Bullet.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;
//��ʼ������
bool Bullet::initWithSpriteFrameName(const std::string&  spriteFrameName) {
	if (Sprite::initWithSpriteFrameName(spriteFrameName)) {
		type = bullet_def;
		return true;
	}
	return false;
}
//�����ӵ����飬�ⲿ���ýӿ�
Bullet* Bullet::createBullet(const std::string&  spriteFrameName) {
	Bullet *object = NULL;
	object = new Bullet();
	object->initWithSpriteFrameName(spriteFrameName);
	//object->autorelease();

	return object;
}
