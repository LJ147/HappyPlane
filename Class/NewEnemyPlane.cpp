#include "NewEnemyPlane.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

bool NewEnemyPlane::initWithSpriteFrameName(const std::string&  spriteFrameName) {
	if (Sprite::initWithSpriteFrameName(spriteFrameName)) {
		
		currentHp = 0;
		return true;
	}
	return false;
}

NewEnemyPlane* NewEnemyPlane::createNewEnemyPlane(const std::string&  spriteFrameName) {
	NewEnemyPlane *object = NULL;
	object = new NewEnemyPlane();
	object->initWithSpriteFrameName(spriteFrameName);
	object->autorelease();

	return object;
}
//设定敌方飞机类型 不同类型对应不同血量
void NewEnemyPlane::setTypeOfPlane(EnemyPlane_Type  type)
{
	switch (type)
	{
	case enemy_max:
		this->currentHp = 6;
		this->setTag(3);

	case ememy_min_without_bullet:
		this->currentHp = 1;
		this->setTag(1);
	case ememy_middle_without_bullet:
		this->currentHp = 2;
		this->setTag(2);

	case enemy_middle:
		this->currentHp = 4;
		this->setTag(2);
	case ememy_min:
		this->currentHp = 1;
		this->setTag(1);
	case 	enemy_Boss1:
		this->currentHp = 40;
		this->setTag(5);
	default:
		break;
	}
}

//设定敌方飞机类型 类型对应血量
void NewEnemyPlane::setTypeOfPlane(int num)
{
	switch (num)
	{
	case 1:
		this->currentHp = 1;
	case 2:
		this->currentHp = 2;
	case 3:
		this->currentHp = 4;
	case 	5:
		this->currentHp = 40;
	default:
		this->currentHp = 1;
		break;
	}
}
