#ifndef __ControlLayer_H__
#define __ControlLayer_H__

#include "cocos2d.h"
USING_NS_CC;
class ControlLayer :public Layer {
public:
	ControlLayer();
	bool init();
	CREATE_FUNC(ControlLayer);
	//��Ϸ��ͣ��ָ�
	void menuPauseCallback(Ref *object);
		//��������
	void menuMusicCallback(Ref*object);

	MenuItemSprite *pPauseItem;
	MenuItemSprite *pMusicItem;
	Label *m_score;
	Label *Score_label;
};
#endif