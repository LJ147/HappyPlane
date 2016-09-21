#ifndef __Leaderboard_SCENE_H__
#define __Leaderboard_SCENE_H__

#include "cocos2d.h"
#include<stdio.h>
#include"AboutScene.h"
#include"MainGame.h"
#include"GameSetting.h"
#include"FirstScene.h"
using namespace std;
using namespace cocos2d;

class Leaderboard : public cocos2d::Layer
{
public:

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();
	//跳转到设置页面

	virtual bool init();
	Sprite *BgImg;
	Label *Score;
	void BackToStartScene(Ref *object);
	Node *createChart(int rank, int score);
	std::vector<Node*> chartList;
	CREATE_FUNC(Leaderboard);
private:

};

#endif // __Leaderboard_SCENE_H__
