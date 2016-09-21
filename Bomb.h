 #pragma once

#ifndef __BOMB_H__
#define __BOMB_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"


#define EXPLOSION_TIME 0.6f

#define NUM_HOLE_MAX	2

USING_NS_CC;

class Bomb :public Layer
{
public:
	virtual bool init();
	//��ը��������Ч���ú���
	void PostExplosion();
	void PlayExplosion(CCPoint vPos);
	CREATE_FUNC(Bomb);

protected:
	CCSprite* m_pBg;
	CCSprite* m_pExplosion;
	CCSprite* m_pLight;

	int m_nHoleIndex;

	CCTexture2D* m_pTextureFrame;
	//������Чϵͳ
	CCParticleSystem* m_SmallParticle;
	CCParticleSystem* m_SmallParticle2;
	CCParticleSystem* m_Smoke;

};

#endif