#ifndef __Buff_SCENE_H__
#define __Buff_SCENE_H__

#include "cocos2d.h"
#include<stdio.h>
#include "HeroPlane.h"
using namespace cocos2d;
using namespace std;


class Buff : public Sprite
{
public:
	//
	bool initWithSpriteFrameName(const std::string& spriteFrameName);
	static Buff* createBuff(const std::string& spriteFrameName);

	CREATE_FUNC(Buff);

};

#endif // __Buff_SCENE_H__
