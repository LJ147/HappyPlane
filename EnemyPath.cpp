#include"EnemyPath.h"
#include "Bullet.h"



//删除飞出场景的敌机
void EnemyPath::enemyRemove(Node* pNode) {
	if (NULL == pNode) {
		return;
	}
	HeroPlane* plane = (HeroPlane*)pNode;
	this->removeChild(plane, true);
}
void EnemyPath::SPath(float time) {
	//获取屏幕长宽

	Size winSize = Director::getInstance()->getWinSize();
	//建立敌机
	NewEnemyPlane* enemy = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy->setTag(1);
	enemy->setTypeOfPlane(1);

	enemy->type = ememy_min_without_bullet;
	enemy->setRotation(270);
	enemy->setPosition(Vec2(winSize.width, winSize.height));
	this->addChild(enemy);
	
	
	/******************************************************************
	************************设置"S"型飞行路径****************************
	******************************************************************/
	//设置贝塞尔曲线参数  
	ccBezierConfig tr0;
	tr0.endPosition = Vec2(0, 0);//终点  
	tr0.controlPoint_1 = Vec2(0, winSize.height);//控制点1  
	tr0.controlPoint_2 = Vec2(winSize.width, 0);//控制点2  
	


	ActionInterval* bezierForward = BezierTo::create(3.f, tr0);//创建运行的贝塞尔曲线  
	ActionInterval *forwardBy = RotateBy::create(3.f, 180);     // 第二个参数：如果是正数则是顺时针，否则逆时针   
	Spawn* spawn = Spawn::create(bezierForward, forwardBy, NULL);//创建合成动作  

																 //飞机执行完动作后进行函数回调，调用移除飞机函数  
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyPath::enemyRemove, this));

	//连续动作  
	Sequence* sequence = Sequence::create(spawn, actionDone, NULL);
	enemy->runAction(sequence);
}

void EnemyPath::TwicePath(float time) {
	Size winSize = Director::getInstance()->getWinSize();
	//建立两个敌机
	NewEnemyPlane* enemy1 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	NewEnemyPlane* enemy2 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy1->setTag(1);
	enemy1->setTypeOfPlane(1);

	enemy2->setTag(1);
	enemy2->setTypeOfPlane(1);

	enemy1->type = ememy_min_without_bullet;
	enemy2->type = ememy_min_without_bullet;
	enemy1->setPosition(plane->getPosition().x+50, winSize.height);
	enemy2->setPosition(plane->getPosition().x - 50, winSize.height);
	this->addChild(enemy1);
	this->addChild(enemy2);
	//动作
	MoveTo *move1 = MoveTo::create(3, Vec2(enemy1->getPosition().x , 0));
	CallFuncN *fun1 = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));
	Sequence *seq1 = Sequence::create(move1, fun1, NULL);

	MoveTo *move2 = MoveTo::create(3, Vec2(enemy2->getPosition().x,0));
	CallFuncN *fun2 = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));
	Sequence *seq2 = Sequence::create(move2, fun2, NULL);

	enemy1->runAction(seq1);
	enemy2->runAction(seq2);

}

void EnemyPath::TwicePath2(float time) {
	Size winSize = Director::getInstance()->getWinSize();
	//建立两个敌机
	NewEnemyPlane* enemy1 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	NewEnemyPlane* enemy2 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy1->setTag(1);
	enemy1->setTypeOfPlane(1);

	enemy2->setTag(1);
	enemy2->setTypeOfPlane(1);

	enemy1->type = ememy_min_without_bullet;
	enemy2->type = ememy_min_without_bullet;
	enemy1->setPosition(winSize.width, plane->getPosition().y + 80);
	enemy2->setPosition(0, plane->getPosition().y - 80);
	enemy1->setRotation(90);
	enemy2->setRotation(270);
	this->addChild(enemy1);
	this->addChild(enemy2);
	//动作
	MoveTo *move1 = MoveTo::create(3, Vec2(0, plane->getPosition().y + 50));
	CallFuncN *fun1 = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));
	Sequence *seq1 = Sequence::create(move1, fun1, NULL);

	MoveTo *move2 = MoveTo::create(3, Vec2(winSize.width, plane->getPosition().y - 50));
	CallFuncN *fun2 = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));
	Sequence *seq2 = Sequence::create(move2, fun2, NULL);

	enemy1->runAction(seq1);
	enemy2->runAction(seq2);

}

void EnemyPath::RandomPath(float time)
{
	//获取屏幕长宽

	Size winSize = Director::getInstance()->getWinSize();

	//设置随机数
	float ran = random(80,700);

	//建立敌机
	NewEnemyPlane* enemy = NewEnemyPlane::createNewEnemyPlane("enemyPlane3.png");
	enemy->setTag(3);
	enemy->setTypeOfPlane(3);

	enemy->type = ememy_max_with_bullet;
	enemy->setPosition(Vec2(ran, winSize.height));
	this->addChild(enemy);

	MoveTo * to = MoveTo::create(5, Vec2(ran, 0));
	CallFuncN *fun = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));
	Sequence *seq = Sequence::create(to, fun, NULL);
	enemy->runAction(seq);
}
void EnemyPath::RandomPath2(float time)
{
	//获取屏幕长宽

	Size winSize = Director::getInstance()->getWinSize();

	//设置随机数
	float ran = random(80, 700);

	//建立敌机
	NewEnemyPlane* enemy = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy->setTag(1);
	enemy->setTypeOfPlane(1);

	enemy->type = ememy_min_with_bullet;
	enemy->setPosition(Vec2(ran, winSize.height));
	this->addChild(enemy);

	MoveTo * to = MoveTo::create(5, Vec2(ran, 0));
	CallFuncN *fun = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));
	Sequence *seq = Sequence::create(to, fun, NULL);
	enemy->runAction(seq);
}

void EnemyPath::TransversePath1(float time) {

	Size winSize = Director::getInstance()->getWinSize();

	NewEnemyPlane* enemy1 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy1->setTag(1);
	enemy1->setTypeOfPlane(1);

	enemy1->type = ememy_min_without_bullet;
	enemy1->setRotation(270);


	this->addChild(enemy1);

	
	enemy1->setPosition(Vec2(0, 3*winSize.height / 4 + 90));

	MoveTo *move1 = MoveTo::create(3, Vec2(winSize.width, enemy1->getPosition().y));
	CallFuncN *fun1 = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));
	Sequence *seq1 = Sequence::create(move1, fun1, NULL);
	enemy1->runAction(seq1);
}
void EnemyPath::TransversePath2(float time) {

	Size winSize = Director::getInstance()->getWinSize();

	NewEnemyPlane* enemy1 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy1->setTag(1);
	enemy1->setTypeOfPlane(1);

	enemy1->type = ememy_min_without_bullet;
	enemy1->setRotation(90);


	this->addChild(enemy1);


	enemy1->setPosition(Vec2(winSize.width, 3 * winSize.height / 4 + 30));

	MoveTo *move1 = MoveTo::create(3, Vec2(0, enemy1->getPosition().y));
	CallFuncN *fun1 = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));
	Sequence *seq1 = Sequence::create(move1, fun1, NULL);
	enemy1->runAction(seq1);
}
void EnemyPath::TransversePath3(float time) {

	Size winSize = Director::getInstance()->getWinSize();

	NewEnemyPlane* enemy1 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy1->setTag(1);
	enemy1->setTypeOfPlane(1);

	enemy1->type = ememy_min_without_bullet;
	enemy1->setRotation(270);


	this->addChild(enemy1);


	enemy1->setPosition(Vec2(0, 3 * winSize.height / 4 - 30));

	MoveTo *move1 = MoveTo::create(3, Vec2(winSize.width , enemy1->getPosition().y));
	CallFuncN *fun1 = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));
	Sequence *seq1 = Sequence::create(move1, fun1, NULL);
	enemy1->runAction(seq1);
}
void EnemyPath::TransversePath4(float time) {

	Size winSize = Director::getInstance()->getWinSize();

	NewEnemyPlane* enemy1 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy1->setTag(1);
	enemy1->type = ememy_min_without_bullet;
	enemy1->setRotation(90);


	this->addChild(enemy1);


	enemy1->setPosition(Vec2(winSize.width, 3 * winSize.height / 4 - 90));

	MoveTo *move1 = MoveTo::create(3, Vec2(0, enemy1->getPosition().y));
	CallFuncN *fun1 = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));
	Sequence *seq1 = Sequence::create(move1, fun1, NULL);
	enemy1->runAction(seq1);
}

void EnemyPath::getHero(Node* hero) {
	plane = hero;

}

void EnemyPath::AIPath1(float time) {

	Size winSize = Director::getInstance()->getWinSize();

	NewEnemyPlane* enemy1 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy1->setTag(1);
	//设置位置
	enemy1->type = ememy_min_without_bullet;
	enemy1->setPosition(Vec2(0, winSize.height));

	this->addChild(enemy1);
	/*
	*
	*
	设计路径
	*
	*
	*/
	//计算英雄飞机和对角点连起的线与边界的角度
	float x = plane->getPosition().x;
	float y = plane->getPosition().y;
	float a = enemy1->getPosition().x - x;
	float b = enemy1->getPosition().y - y;
	// 弧度转角度  
	float radians = atanf(a / b);
	float mDegree = CC_RADIANS_TO_DEGREES(radians);
	enemy1->setRotation(mDegree);
	//计算敌机的最终位置  
	float endX = enemy1->getPosition().x - (a / b)*enemy1->getPosition().y;
	float endY = 0;
	//计算飞行时间  
	float flyVelocity = 200;//运行速度，可以自己控制，每秒所走的像素  
	float flyLen = sqrt((enemy1->getPosition().x - endX)*(enemy1->getPosition().x - endX) + (enemy1->getPosition().y - endY)*(enemy1->getPosition().y - endY));
	float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  
												 //子弹运行的距离和时间，从飞机处开始运行到屏幕底部  
	auto actionMove = MoveTo::create(realFlyDuration, Point(endX, endY));
	//子弹执行完动作后进行函数回调，调用移除子弹函数  
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyPath::enemyRemove, this));
	//连续动作  
	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	//飞机开始跑动  
	enemy1->runAction(sequence);
}
void EnemyPath::AIPath2(float time) {

	Size winSize = Director::getInstance()->getWinSize();

	NewEnemyPlane* enemy1 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy1->setTag(1);
	//设置位置
	enemy1->type = ememy_min_without_bullet;
	enemy1->setPosition(Vec2(winSize.width , winSize.height));

	this->addChild(enemy1);

	//计算英雄飞机和对角点连起的线与边界的角度
	float x = plane->getPosition().x;
	float y = plane->getPosition().y;
	float a = enemy1->getPosition().x - x;
	float b = enemy1->getPosition().y - y;
	// 弧度转角度  
	float radians = atanf(a / b);
	float mDegree = CC_RADIANS_TO_DEGREES(radians);
	enemy1->setRotation(mDegree);
	//计算敌机的最终位置  
	float endX = enemy1->getPosition().x - (a / b)*enemy1->getPosition().y;
	float endY = 0;
	//计算飞行时间  
	float flyVelocity = 200;//运行速度，可以自己控制，每秒所走的像素  
	float flyLen = sqrt((enemy1->getPosition().x - endX)*(enemy1->getPosition().x - endX) + (enemy1->getPosition().y - endY)*(enemy1->getPosition().y - endY));
	float realFlyDuration = flyLen / flyVelocity;//实际飞行的时间  
												 //子弹运行的距离和时间，从飞机处开始运行到屏幕底部  
	auto actionMove = MoveTo::create(realFlyDuration, Point(endX, endY));
	//子弹执行完动作后进行函数回调，调用移除子弹函数  
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyPath::enemyRemove, this));
	//连续动作  
	Sequence* sequence = Sequence::create(actionMove, actionDone, NULL);
	//飞机开始跑动  
	enemy1->runAction(sequence);
}

//暴露给其他类运行，建造敌机的接口
void EnemyPath::runPath1() {
	//schedule(schedule_selector(EnemyPath::RandomPath), 1);//一直运行，知道游戏结束
	schedule(schedule_selector(EnemyPath::setPlaneBody), 0);
	schedule(schedule_selector(EnemyPath::manageEnemyBullet), 2);
	schedule(schedule_selector(EnemyPath::EnemyBulletMove), 0.005);
	schedule(schedule_selector(EnemyPath::RandomPath), 10,1, 5);
	schedule(schedule_selector(EnemyPath::SPath), 0.2, 5, 0);//第一个运行
	schedule(schedule_selector(EnemyPath::AIPath1), 1, 5, 3);//第二个
	schedule(schedule_selector(EnemyPath::AIPath2), 1, 5, 3);//第二个
	schedule(schedule_selector(EnemyPath::TwicePath), 1, 5, 9);//第二个
	schedule(schedule_selector(EnemyPath::TransversePath1), 1, 5, 14);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath2), 1, 5, 14);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath3), 1, 5, 14);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath4), 1, 5, 14);//第三个
	schedule(schedule_selector(EnemyPath::modelOfEnemy3), 1, 0, 23);//第三
	schedule(schedule_selector(EnemyPath::modelOfEnemy2), 0.5, 5, 23);//第三
	//设置随机数


		
	
}
void EnemyPath::runPath2() {
	schedule(schedule_selector(EnemyPath::setPlaneBody), 0);
	schedule(schedule_selector(EnemyPath::manageEnemyBullet), 2);
	schedule(schedule_selector(EnemyPath::EnemyBulletMove), 0.008);
	schedule(schedule_selector(EnemyPath::TransversePath1), 1, 5, 0);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath2), 1, 5, 0);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath3), 1, 5, 0);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath4), 1, 5, 0);//第三个
	schedule(schedule_selector(EnemyPath::modelOfEnemy1), 0.5, 6, 7);//第三
	schedule(schedule_selector(EnemyPath::modelOfEnemy5), 0.5, 5, 11);//第三
	schedule(schedule_selector(EnemyPath::TwicePath), 1, 5, 15);//第二个
	schedule(schedule_selector(EnemyPath::modelOfEnemy4), 0.5, 5, 21);//第三
	schedule(schedule_selector(EnemyPath::RandomPath),5, 2, 5);//
}
void EnemyPath::runPath3() {
	schedule(schedule_selector(EnemyPath::setPlaneBody), 0);
	schedule(schedule_selector(EnemyPath::manageEnemyBullet), 2);
	schedule(schedule_selector(EnemyPath::EnemyBulletMove), 0.008);
	schedule(schedule_selector(EnemyPath::modelOfEnemy3), 1, 0, 0);//第三
	schedule(schedule_selector(EnemyPath::AIPath1), 1, 5, 3);
	schedule(schedule_selector(EnemyPath::AIPath2), 1, 5, 3);//第二个
	schedule(schedule_selector(EnemyPath::SPath), 0.2, 5, 10);//第一个运行
	schedule(schedule_selector(EnemyPath::TransversePath1), 1, 5, 13);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath2), 1, 5, 13);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath3), 1, 5, 13);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath4), 1, 5, 13);//第三个
	schedule(schedule_selector(EnemyPath::TwicePath), 1, 5, 21);//第二个
	schedule(schedule_selector(EnemyPath::modelOfEnemy7), 1, 6, 27);//第三
	schedule(schedule_selector(EnemyPath::RandomPath), 5, 2, 5);//
}
void EnemyPath::runPath4() {
	schedule(schedule_selector(EnemyPath::setPlaneBody), 0);
	schedule(schedule_selector(EnemyPath::manageEnemyBullet), 2);
	schedule(schedule_selector(EnemyPath::EnemyBulletMove), 0.008);
	schedule(schedule_selector(EnemyPath::modelOfEnemy1), 0.5, 6, 1);//第三
	schedule(schedule_selector(EnemyPath::RandomPath), 5, 2, 5);//
	schedule(schedule_selector(EnemyPath::modelOfEnemy7), 1, 6, 4);//第三
	schedule(schedule_selector(EnemyPath::AIPath1), 1, 5, 13);
	schedule(schedule_selector(EnemyPath::AIPath2), 1, 5, 13);//第二个
	schedule(schedule_selector(EnemyPath::TransversePath1), 1, 5, 19);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath2), 1, 5,19);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath3), 1, 5, 19);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath4), 1, 5, 19);//第三个

}
void EnemyPath::runPath5() {
	schedule(schedule_selector(EnemyPath::RandomPath), 5, 2, 0);//
	schedule(schedule_selector(EnemyPath::setPlaneBody), 0);
	schedule(schedule_selector(EnemyPath::manageEnemyBullet), 2);
	schedule(schedule_selector(EnemyPath::EnemyBulletMove), 0.008);
	schedule(schedule_selector(EnemyPath::modelOfEnemy4), 0.5, 5, 0);//第三
	schedule(schedule_selector(EnemyPath::modelOfEnemy5), 0.5, 5, 4);//第三
	schedule(schedule_selector(EnemyPath::modelOfEnemy3), 1, 0, 7);//第三
	schedule(schedule_selector(EnemyPath::modelOfEnemy1), 0.5, 6, 10);//第三
	schedule(schedule_selector(EnemyPath::TransversePath1), 1, 5, 13);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath2), 1, 5, 13);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath3), 1, 5, 13);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath4), 1, 5, 13);//第三个


}
void EnemyPath::runPath6() {
	schedule(schedule_selector(EnemyPath::RandomPath), 5, 2, 5);//
	schedule(schedule_selector(EnemyPath::setPlaneBody), 0);
	schedule(schedule_selector(EnemyPath::manageEnemyBullet), 2);
	schedule(schedule_selector(EnemyPath::EnemyBulletMove), 0.008);
	schedule(schedule_selector(EnemyPath::AIPath1), 1, 5, 0);
	schedule(schedule_selector(EnemyPath::AIPath2), 1, 5, 0);//第二个
	schedule(schedule_selector(EnemyPath::TwicePath), 1, 5, 7);//第二个
	schedule(schedule_selector(EnemyPath::TransversePath1), 1, 5, 15);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath2), 1, 5, 15);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath3), 1, 5, 15);//第三个
	schedule(schedule_selector(EnemyPath::TransversePath4), 1, 5, 15);//第三个
	schedule(schedule_selector(EnemyPath::modelOfEnemy3), 1, 0, 23);//第三
	schedule(schedule_selector(EnemyPath::modelOfEnemy7), 1, 6, 27);//第三

}

void EnemyPath::modelOfEnemy1(float time)
{
	NewEnemyPlane * enemy = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy->setTag(1);
	enemy->type = ememy_min;
	enemy->setAnchorPoint(Vec2(0, 0.5));
	// Point location = hero->getPosition();
	enemy->setPosition(Vec2(0, 900));
	addChild(enemy);
	// MoveTo * move = MoveTo::create(3, Vec2(location.x, 0));
	CallFuncN * fun = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));

	//设置贝塞尔曲线参数
	ccBezierConfig tr0;
	tr0.endPosition = Vec2(0, 300);//终点
	tr0.controlPoint_1 = Vec2(500, 900);//控制点1
	tr0.controlPoint_2 = Vec2(100, 300);//控制点2
	auto bezierForward = BezierTo::create(2.0f, tr0);//创建运行的贝塞尔曲线
	auto seq = Sequence::create(bezierForward, fun, nullptr);
	enemy->runAction(seq);

	NewEnemyPlane * enemy1 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy1->setTag(1);
	enemy1->type = ememy_min_without_bullet;
	enemy1->setAnchorPoint(Vec2(1, 0.5));
	// Point location = hero->getPosition();
	enemy1->setPosition(Vec2(768, 900));
	addChild(enemy1);
	// MoveTo * move = MoveTo::create(3, Vec2(location.x, 0));
	CallFuncN * fun1 = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));

	//设置贝塞尔曲线参数
	ccBezierConfig tr01;
	tr01.endPosition = Vec2(768, 300);//终点
	tr01.controlPoint_1 = Vec2(268, 900);//控制点1
	tr01.controlPoint_2 = Vec2(668, 300);//控制点2
	auto bezierForward1 = BezierTo::create(2.0f, tr01);//创建运行的贝塞尔曲线
	auto seq1 = Sequence::create(bezierForward1, fun1, nullptr);
	enemy1->runAction(seq1);


}



//第二种模式，从右侧逆时针弧形进入
void EnemyPath::modelOfEnemy2(float time)
{
	NewEnemyPlane * enemy = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy->setTag(1);
	enemy->type = ememy_min_without_bullet;
	enemy->setAnchorPoint(Vec2(0, 0.5));

	enemy->setPosition(Vec2(0, 900));
	addChild(enemy);
	// MoveTo * move = MoveTo::create(3, Vec2(location.x, 0));
	CallFuncN * fun = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));

	//设置贝塞尔曲线参数
	ccBezierConfig tr0;
	tr0.endPosition = Vec2(768, 300);//终点
	tr0.controlPoint_1 = Vec2(268, 900);//控制点1
	tr0.controlPoint_2 = Vec2(668, 300);//控制点2
	auto bezierForward = BezierTo::create(2.0f, tr0);//创建运行的贝塞尔曲线
	auto seq = Sequence::create(bezierForward, fun, nullptr);
	enemy->runAction(seq);


}

//第三种模式，六架飞机倒三角式入场

void EnemyPath::modelOfEnemy3(float time)
{
	MoveBy *moveby = MoveBy::create(5, Vec2(0, -1024));
	CallFuncN * fun = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));

	auto * seq = Sequence::create(moveby, fun, nullptr);
	//第一架飞机
	NewEnemyPlane * enemy1 = NewEnemyPlane::createNewEnemyPlane("enemyPlane2.png");
	enemy1->setTag(2);
	enemy1->type = ememy_middle_without_bullet;
	enemy1->setAnchorPoint(Vec2(0.5, 0.5));

	enemy1->setPosition(Vec2(384, 800));
	addChild(enemy1);
	enemy1->runAction(seq);
	//第二架飞机
	NewEnemyPlane * enemy2 = NewEnemyPlane::createNewEnemyPlane("enemyPlane2.png");
	enemy2->setTag(2);
	enemy2->type = ememy_middle_without_bullet;
	enemy2->setAnchorPoint(Vec2(0.5, 0.5));

	enemy2->setPosition(Vec2(309, 900));
	addChild(enemy2);
	enemy2->runAction(seq->clone());
	//第三架飞机
	NewEnemyPlane * enemy3 = NewEnemyPlane::createNewEnemyPlane("enemyPlane2.png");
	enemy3->setTag(2);
	enemy3->type = ememy_middle_without_bullet;
	enemy3->setAnchorPoint(Vec2(0.5, 0.5));

	enemy3->setPosition(Vec2(459, 900));
	addChild(enemy3);
	enemy3->runAction(seq->clone());
	//第四架飞机
	NewEnemyPlane * enemy4 = NewEnemyPlane::createNewEnemyPlane("enemyPlane2.png");
	enemy4->setTag(2);
	enemy4->type = ememy_middle_without_bullet;

	enemy4->setAnchorPoint(Vec2(0.5, 0.5));

	enemy4->setPosition(Vec2(384, 1000));
	addChild(enemy4);
	enemy4->runAction(seq->clone());
	//第五架飞机
	NewEnemyPlane * enemy5 = NewEnemyPlane::createNewEnemyPlane("enemyPlane2.png");
	enemy5->setTag(2);
	enemy5->type = ememy_middle_without_bullet;
	enemy5->setAnchorPoint(Vec2(0.5, 0.5));

	enemy5->setPosition(Vec2(234, 1000));

	addChild(enemy5);
	enemy5->runAction(seq->clone());
	//第六架飞机
	NewEnemyPlane * enemy6 = NewEnemyPlane::createNewEnemyPlane("enemyPlane2.png");
	enemy6->setTag(2);
	enemy6->type = ememy_middle_without_bullet;
	enemy6->setAnchorPoint(Vec2(0.5, 0.5));
	enemy6->setPosition(Vec2(534, 1000));
	addChild(enemy6);
	enemy6->runAction(seq->clone());





}
//第四种模式，左右抖动垂直向下入场                                                                                                                                                                                                    
//第四种模式，抖动入场
void EnemyPath::modelOfEnemy4(float time)
{
	CallFuncN * fun = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));
	NewEnemyPlane * enemy = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy->setTag(1);
	enemy->type = ememy_min_without_bullet;
	enemy->setAnchorPoint(Vec2(0.5, 0.5));

	enemy->setPosition(Vec2(384, 1000));
	addChild(enemy);
	MoveTo* MoveTo1 = MoveTo::create(0.5, Vec2(684, 800));
	MoveTo* MoveTo2 = MoveTo::create(0.5, Vec2(384, 600));
	MoveTo* MoveTo3 = MoveTo::create(0.5, Vec2(84, 400));
	MoveTo* MoveTo4 = MoveTo::create(0.5, Vec2(384, 200));
	MoveTo* MoveTo5 = MoveTo::create(0.5, Vec2(684, -20));


	// MoveTo* MoveTo5 = MoveTo::create(0.5, Vec2(584, 150));
	// MoveTo* MoveTo6 = MoveTo::create(0.5, Vec2(384, 0));

	Sequence *seq = Sequence::create(MoveTo1, MoveTo2, MoveTo3, MoveTo4, MoveTo5, fun, nullptr);
	enemy->runAction(seq);
}
void EnemyPath::modelOfEnemy5(float time)
{
	CallFuncN * fun = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));
	//第一架飞机
	NewEnemyPlane * enemy1 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy1->setTag(1);
	enemy1->type = ememy_min_without_bullet;
	enemy1->setAnchorPoint(Vec2(0.5, 0.5));

	enemy1->setPosition(Vec2(80, 1000));
	addChild(enemy1);

	//第二架飞机
	NewEnemyPlane * enemy2 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy2->setTag(1);
	enemy2->type = ememy_min;
	enemy2->setAnchorPoint(Vec2(0.5, 0.5));

	enemy2->setPosition(Vec2(668, 1000));
	addChild(enemy2);


	MoveTo* MoveTo1 = MoveTo::create(1, Vec2(668, 500));
	MoveTo* MoveTo2 = MoveTo::create(1, Vec2(80, 500));
	MoveTo* MoveTo3 = MoveTo::create(1, Vec2(668, -50));
	MoveTo* MoveTo4 = MoveTo::create(1, Vec2(80, -50));
	auto delay1 = DelayTime::create(0.2);
	auto delay2 = DelayTime::create(0.2);
	auto *seq1 = Sequence::create(MoveTo1, delay1, MoveTo4, fun, nullptr);
	auto *seq2 = Sequence::create(MoveTo2, delay2, MoveTo3, fun, nullptr);
	enemy1->runAction(seq1);
	enemy2->runAction(seq2);

}
//第六种模式，"火"字入场
void EnemyPath::modelOfEnemy6(float time)
{  //第一个元素

	NewEnemyPlane* plane1 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	plane1->setTag(1);
	plane1->type = ememy_min_without_bullet;
	plane1->setAnchorPoint(Vec2(0.5, 0.5));
	plane1->setPosition(Vec2(384, 900));
	addChild(plane1);
	//第二个元素
	NewEnemyPlane* plane2 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	plane2->setTag(1);
	plane2->type = ememy_min_without_bullet;
	plane2->setAnchorPoint(Vec2(0.5, 0.5));
	plane2->setPosition(Vec2(384, 840));
	addChild(plane2);
	//第三个元素
	NewEnemyPlane* plane3 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	plane3->setTag(1);
	plane3->type = ememy_min_without_bullet;
	plane3->setAnchorPoint(Vec2(0.5, 0.5));
	plane3->setPosition(Vec2(384, 780));
	addChild(plane3);
	//第四个元素
	NewEnemyPlane* plane4 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	plane4->setTag(1);
	plane4->type = ememy_min_without_bullet;
	plane4->setAnchorPoint(Vec2(0.5, 0.5));
	plane4->setPosition(Vec2(384, 720));
	addChild(plane4);
	//第五个元素
	NewEnemyPlane* plane5 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	plane5->setTag(1);
	plane5->type = ememy_min_without_bullet;
	plane5->setAnchorPoint(Vec2(0.5, 0.5));
	plane5->setRotation(-45);
	plane5->setPosition(Vec2(324, 680));
	addChild(plane5);
	//第六个元素
	NewEnemyPlane* plane6 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	plane5->setTag(1);
	plane6->type = ememy_min_without_bullet;
	plane6->setAnchorPoint(Vec2(0.5, 0.5));
	plane6->setRotation(-45);
	plane6->setPosition(Vec2(264, 640));
	addChild(plane6);
	//第七个元素
	NewEnemyPlane* plane7 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	plane7->type = ememy_min_without_bullet;
	plane7->setAnchorPoint(Vec2(0.5, 0.5));
	plane7->setRotation(45);
	plane7->setPosition(Vec2(444, 680));
	addChild(plane7);
	//第八个元素
	NewEnemyPlane* plane8 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	plane8->type = ememy_min_without_bullet;
	plane8->setAnchorPoint(Vec2(0.5, 0.5));
	plane8->setRotation(45);
	plane8->setPosition(Vec2(504, 640));
	addChild(plane8);
	//第九个元素
	NewEnemyPlane* plane9 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	plane9->type = ememy_min_without_bullet;
	plane9->setAnchorPoint(Vec2(0.5, 0.5));
	plane9->setRotation(-45);
	plane9->setPosition(Vec2(304, 780));
	addChild(plane9);
	//第十个元素
	NewEnemyPlane* plane10 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	plane10->type = ememy_min;
	plane10->setAnchorPoint(Vec2(0.5, 0.5));
	plane10->setRotation(-45);
	plane10->setPosition(Vec2(274, 820));
	addChild(plane10);
	//第十一个元素
	NewEnemyPlane* plane11 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	plane11->type = ememy_min;
	plane11->setAnchorPoint(Vec2(0.5, 0.5));
	plane11->setRotation(45);
	plane11->setPosition(Vec2(464, 780));
	addChild(plane11);
	//第十一个元素
	NewEnemyPlane* plane12 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	plane12->type = ememy_min;
	plane12->setAnchorPoint(Vec2(0.5, 0.5));
	plane12->setRotation(45);
	plane12->setPosition(Vec2(494, 820));
	addChild(plane12);

	CallFuncN * fun = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));
	MoveBy *moveby = MoveBy::create(10, Vec2(0, -1024));
	auto seq = Sequence::create(moveby, fun, nullptr);
	plane1->runAction(seq);
	plane2->runAction(seq->clone());
	plane3->runAction(seq->clone());
	plane4->runAction(seq->clone());
	plane5->runAction(seq->clone());
	plane6->runAction(seq->clone());
	plane7->runAction(seq->clone());
	plane8->runAction(seq->clone());
	plane9->runAction(seq->clone());
	plane10->runAction(seq->clone());
	plane11->runAction(seq->clone());
	plane12->runAction(seq->clone());

}
//第七种模式，多架飞机交叉进入
void EnemyPath::modelOfEnemy7(float time)
{
	CallFuncN * fun = CallFuncN::create(CC_CALLBACK_1(EnemyPath::enemyRemove, this));
	//第一架飞机，第三架飞机，第五架飞机，初始出现在左侧
	NewEnemyPlane * enemy1 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy1->setTag(1);
	enemy1->type = ememy_min_without_bullet;
	enemy1->setAnchorPoint(Vec2(0.5, 0.5));

	enemy1->setPosition(Vec2(80, 900));
	addChild(enemy1);
	NewEnemyPlane * enemy3 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy3->setTag(1);
	enemy3->type = ememy_min_without_bullet;
	enemy3->setAnchorPoint(Vec2(0.5, 0.5));

	enemy3->setPosition(Vec2(50, 950));
	addChild(enemy3);
	NewEnemyPlane * enemy5 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy5->setTag(1);
	enemy5->type = ememy_min_without_bullet;
	enemy5->setAnchorPoint(Vec2(0.5, 0.5));

	enemy5->setPosition(Vec2(110, 950));
	addChild(enemy5);

	//第二架飞机，第四架飞机，第五架飞机，初始出现在右侧
	NewEnemyPlane * enemy2 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy2->setTag(1);
	enemy2->type = ememy_min_without_bullet;
	enemy2->setAnchorPoint(Vec2(0.5, 0.5));

	enemy2->setPosition(Vec2(668, 900));
	addChild(enemy2);
	NewEnemyPlane * enemy4 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy4->setTag(1);
	enemy4->type = ememy_min_without_bullet;
	enemy4->setAnchorPoint(Vec2(0.5, 0.5));

	enemy4->setPosition(Vec2(638, 950));
	addChild(enemy4);
	NewEnemyPlane * enemy6 = NewEnemyPlane::createNewEnemyPlane("enemyPlane1.png");
	enemy6->setTag(1);
	enemy6->type = ememy_min_without_bullet;
	enemy6->setAnchorPoint(Vec2(0.5, 0.5));

	enemy6->setPosition(Vec2(698, 950));
	addChild(enemy6);

	MoveBy* MoveTo1 = MoveBy::create(1, Vec2(588, -400));
	MoveBy* MoveTo2 = MoveBy::create(1, Vec2(-588, -400));
	MoveBy* MoveTo3 = MoveBy::create(1, Vec2(588, -400));
	MoveBy* MoveTo4 = MoveBy::create(1, Vec2(-588, -400));
	auto delay1 = DelayTime::create(0.2);
	auto delay2 = DelayTime::create(0.2);
	auto *seq1 = Sequence::create(MoveTo1, delay1, MoveTo4, fun, nullptr);
	auto *seq2 = Sequence::create(MoveTo2, delay2, MoveTo3, fun, nullptr);
	enemy1->runAction(seq1);
	enemy3->runAction(seq1->clone());
	enemy5->runAction(seq1->clone());
	enemy2->runAction(seq2);
	enemy4->runAction(seq2->clone());
	enemy6->runAction(seq2->clone());


}
void EnemyPath::manageEnemyBullet(float time) {
	Vector<Node*>allnodes = getChildren();
	for (int i = int(allnodes.size() - 1); i >= 0; i--) {
		auto node = allnodes.at(i);
		log("1");
		if (strcmp(typeid(*node).name(), typeid(NewEnemyPlane).name()) == 0) {
			NewEnemyPlane *Plane = (NewEnemyPlane*)node;
			log("2");
			if (Plane->type == ememy_max_with_bullet) {
				/*{
					auto body = PhysicsBody::createBox(Plane->getContentSize());
					body->setCategoryBitmask(0x08);
					body->setContactTestBitmask(0x02);
					body->setCollisionBitmask(0x01);
					//body->setContactTestBitmask(0xFFFFFFFF);
					Plane->setPhysicsBody(body);
					Plane->setTag(1);
				}*/
				auto yy = Plane->getPosition();
				Bullet *blt = Bullet::createBullet("enemyBullet.png");
				blt->type = bullet_enemy;
				auto body = PhysicsBody::createBox(blt->getContentSize());
				//body->setContactTestBitmask(0x08);
				body->setCollisionBitmask(0x0);
				body->setContactTestBitmask(0xFFFFFFFF);
				body->setCategoryBitmask(0xFFFFFFFF);
				blt->setPhysicsBody(body);
				blt->setPosition(yy.x, yy.y - 80);
				blt->setTag(9);
				addChild(blt, 9);
			}
			else if (Plane->type == ememy_min_with_bullet) {
				auto yy = Plane->getPosition();
				Bullet *blt = Bullet::createBullet("enemyBullet.png");
				blt->type = bullet_enemy;
				{
					auto body = PhysicsBody::createBox(blt->getContentSize());
					//body->setContactTestBitmask(0x08);
					body->setCollisionBitmask(0x0);
					body->setContactTestBitmask(0xFFFFFFFF);
					body->setCategoryBitmask(0xFFFFFFFF);
					blt->setPhysicsBody(body);
					blt->setTag(9);





				}
				blt->setPosition(yy.x, yy.y - 3);

				addChild(blt, 9);
			}
			else if (Plane->type == enemy_max) {

			}
		}
	}
}

void EnemyPath::setBulletBody(float time) {
	Vector<Node*>allNodes = getChildren();
	for (int i = int(allNodes.size() - 1); i >= 0; i--) {
		auto node = allNodes.at(i);
		if (strcmp(typeid(*node).name(), typeid(Bullet).name()) == 0) {
			Bullet *Bullet_m = (Bullet*)node;
			if (Bullet_m->type == bullet_def || Bullet_m->type == bullet_enemy) {
				auto body = PhysicsBody::createBox(Bullet_m->getContentSize());
				//body->setContactTestBitmask(0x08);
				body->setCollisionBitmask(0x0);
				body->setContactTestBitmask(0xFFFFFFFF);
				body->setCategoryBitmask(0xFFFFFFFF);
				Bullet_m->setPhysicsBody(body);
				Bullet_m->setTag(9);
			}
		}
	}
}
void EnemyPath::EnemyBulletMove(float time) {
	Vector<Node*>allNodes = getChildren();
	for (int i = int(allNodes.size() - 1); i >= 0; i--) {
		auto node = allNodes.at(i);
		log("5");
		if (strcmp(typeid(*node).name(), typeid(Bullet).name()) == 0) {
			Bullet *Bullet_m = (Bullet*)node;
			if (Bullet_m->type == bullet_enemy) {
				
				auto yy = Bullet_m->getPosition().y;
				auto xx = Bullet_m->getPosition().x;
				if (yy >= 0){
					log("6");
					Bullet_m->setPositionY(yy - 3);
				}
				else
				{
					Bullet_m->stopAllActions();
					removeBullet(Bullet_m);
				}
			}
			else if (Bullet_m->type == ememy_min_with_bullet) {
				auto yy = Bullet_m->getPosition().y;
				auto xx = Bullet_m->getPosition().x;
				if (yy >= 0) {
					log("6");
					Bullet_m->setPositionY(yy - 5);
				}
				else
				{
					Bullet_m->stopAllActions();
					removeBullet(Bullet_m);
				}
			}
		}
	}
}
//移除子弹
void EnemyPath::removeBullet(Ref *object) {
	Bullet *blt = (Bullet *)object;
	blt->stopAllActions();
	removeChild(blt);
}

void EnemyPath::setPlaneBody(float time) {
	Vector<Node*>allnodes = getChildren();
	for (int i = int(allnodes.size() - 1); i >= 0; i--) {
		auto node = allnodes.at(i);
		
		if (strcmp(typeid(*node).name(), typeid(NewEnemyPlane).name()) == 0) {
			NewEnemyPlane *Plane = (NewEnemyPlane*)node;
			auto body = PhysicsBody::createBox(Plane->getContentSize());
			//body->setContactTestBitmask(0x08);
			body->setCollisionBitmask(0x0);
			body->setContactTestBitmask(0xFFFFFFFF);
			body->setCategoryBitmask(0xFFFFFFFF);
			Plane->setPhysicsBody(body);
				
		}
	}
}

void EnemyPath::chapter1() {
	schedule(schedule_selector(EnemyPath::setBulletBody), 0);
	schedule(schedule_selector(EnemyPath::setPlaneBody), 0);
	CallFuncN *fun1 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath1, this));
	CallFuncN *fun2 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath2, this));
	CallFuncN *fun3 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath3, this));
	CallFuncN *fun4 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath4, this));
	CallFuncN *fun5 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath5, this));
	CallFuncN *fun6 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath6, this));
	CallFuncN *fun0 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath7, this));
	CallFuncN *fun8 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runBoss, this));
	CallFuncN *fun7 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::MangerBoss, this));
	Sequence* seq = Sequence::create( fun0,fun1, 
		DelayTime::create(24),
		fun2,
		DelayTime::create(29),
		fun3, 
		DelayTime::create(31),
		fun4,
		DelayTime::create(24),
		fun5,
		DelayTime::create(15),
		fun6,
		DelayTime::create(32),
		fun7,
		fun8,
		NULL);
	this->runAction(seq);
}

void EnemyPath::runPath7() {
	schedule(schedule_selector(EnemyPath::RandomPath2), 3,40,0);
	
	schedule(schedule_selector(EnemyPath::TwicePath2), 5,30,0);

}

void EnemyPath::BossMove(float time) {
	
	MoveTo *left = MoveTo::create(1.5, Vec2(179, 800));
	MoveTo*backRight = MoveTo::create(1.5, Vec2(384, 800));
	MoveTo *right = MoveTo::create(1.5, Vec2(589, 800));
	MoveTo *backLeft = MoveTo::create(1.5, Vec2(384, 800));
	MoveTo*down = MoveTo::create(1.5, Vec2(384, 512));
	MoveTo*up = MoveTo::create(1.5, Vec2(384, 800));
	Sequence* list = Sequence::create(left, backRight,DelayTime::create(1), right, backLeft,DelayTime::create(1), down, up,DelayTime::create(1), NULL);
	boss->runAction(list);
}
void EnemyPath::MangerBoss() {
	boss = NewEnemyPlane::createNewEnemyPlane("boss1.png");
	auto body = PhysicsBody::createBox(boss->getContentSize());
	//body->setContactTestBitmask(0x08);
	body->setCollisionBitmask(0x0);
	body->setContactTestBitmask(0xFFFFFFFF);
	body->setCategoryBitmask(0xFFFFFFFF);
	boss->setPhysicsBody(body);
	//boss->setTypeOfPlane(enemy_Boss1);
	boss->setAnchorPoint(Vec2(0.5, 0.5));
	boss->setPosition(Vec2(384, 1232));
	boss->setTag(5);
	boss->setTypeOfPlane(enemy_Boss1);


	addChild(boss);
	MoveTo *down = MoveTo::create(3, Vec2(384, 800));
	//mangerBossBullet();
	schedule(schedule_selector(EnemyPath::BossBullet1), 12);
	schedule(schedule_selector(EnemyPath::BossBullet2), 12);
	schedule(schedule_selector(EnemyPath::BossBullet3), 12);
	schedule(schedule_selector(EnemyPath::BossBullet4), 12);
	schedule(schedule_selector(EnemyPath::BossBullet5), 12);

	schedule(schedule_selector(EnemyPath::BossBullet21), 12, 999, 3);
	schedule(schedule_selector(EnemyPath::BossBullet22), 12, 999, 3);
	schedule(schedule_selector(EnemyPath::BossBullet23), 12, 999, 3);
	schedule(schedule_selector(EnemyPath::BossBullet24), 12, 999, 3);
	schedule(schedule_selector(EnemyPath::BossBullet25), 12, 999, 3);

	schedule(schedule_selector(EnemyPath::BossBullet6), 12, 999, 6);
	schedule(schedule_selector(EnemyPath::BossBullet7), 12, 999, 6);

	schedule(schedule_selector(EnemyPath::BossBullet26), 12, 999, 9);
	schedule(schedule_selector(EnemyPath::BossBullet27), 12, 999, 9);
	boss->runAction(down);
}
void EnemyPath::runBoss() {
	schedule(schedule_selector(EnemyPath::BossMove), 12);
}
void EnemyPath::BossBullet1(float time) {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("instancePictures.plist", "instancePictures.png");
	Bullet *blt1 = Bullet::createBullet("bullet4.png");
	blt1->type = bullet_def;
	{
		auto body = PhysicsBody::createBox(blt1->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt1->setPhysicsBody(body);
	}
	blt1->setPosition(Vec2(boss->getPosition().x, boss->getPosition().y - boss->getContentSize().height / 2));
	this->addChild(blt1, 10);
	blt1->setRotation(45);
	float endX1;
	float endY1;
	float flyLen1;
	if (blt1->getPosition().x > blt1->getPosition().y) {
		endX1 = blt1->getPosition().x - blt1->getPosition().y;
		endY1 = 0;
		flyLen1 = blt1->getPosition().y*sqrt(2);
	}
	else {
		endX1 = 0;
		endY1 = blt1->getPosition().y - blt1->getPosition().x;
		flyLen1 = blt1->getPosition().x*sqrt(2);
	}
	float flyVelocity = 200;
	float flyTime1 = flyLen1 / flyVelocity;

	auto actionMove1 = MoveTo::create(flyTime1, Point(endX1, endY1));
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyPath::removeBullet, this));
	Sequence* sequence5 = Sequence::create(actionMove1, actionDone, NULL);

	blt1->runAction(sequence5);

}

void EnemyPath::BossBullet2(float time) {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("instancePictures.plist", "instancePictures.png");
	Bullet *blt2 = Bullet::createBullet("bullet4.png");
	blt2->type = bullet_def;
	{
		auto body = PhysicsBody::createBox(blt2->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt2->setPhysicsBody(body);
	}
	blt2->setPosition(Vec2(boss->getPosition().x, boss->getPosition().y - boss->getContentSize().height / 2));
	this->addChild(blt2, 10);
	blt2->setRotation(22.5);
	float endX2;
	float endY2;
	float flyLen2;
	float flyVelocity = 200;
	if (blt2->getPosition().y > blt2->getPosition().x / tan(0.3926991)) {
		endX2 = 0;
		endY2 = blt2->getPosition().y - blt2->getPosition().x / tan(0.3926991);
		flyLen2 = blt2->getPosition().x / sin(0.3926991);
	}
	else {
		endX2 = blt2->getPosition().x - blt2->getPosition().y*tan(0.3926991);
		endY2 = 0;
		flyLen2 = blt2->getPosition().y / cos(0.3926991);
	}
	float flyTime2 = flyLen2 / flyVelocity;

	auto actionMove2 = MoveTo::create(flyTime2, Point(endX2, endY2));
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyPath::removeBullet, this));
	Sequence* sequence2 = Sequence::create(actionMove2, actionDone, NULL);

	blt2->runAction(sequence2);
}

void EnemyPath::BossBullet3(float time) {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("instancePictures.plist", "instancePictures.png");
	Bullet *blt3 = Bullet::createBullet("bullet4.png");
	blt3->type = bullet_def;
	{
		auto body = PhysicsBody::createBox(blt3->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt3->setPhysicsBody(body);
	}
	blt3->setPosition(Vec2(boss->getPosition().x, boss->getPosition().y - boss->getContentSize().height / 2));
	this->addChild(blt3, 10);
	float endX3 = blt3->getPosition().x;
	float endY3 = 0;
	float flyVelocity = 200;
	float flyTime3 = endX3 / flyVelocity;
	auto actionMove3 = MoveTo::create(flyTime3, Point(endX3, endY3));
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyPath::removeBullet, this));
	Sequence* sequence3 = Sequence::create(actionMove3, actionDone, NULL);
	blt3->runAction(sequence3);
}

void EnemyPath::BossBullet4(float time) {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("instancePictures.plist", "instancePictures.png");
	Bullet *blt4 = Bullet::createBullet("bullet4.png");
	blt4->type = bullet_def;
	{
		auto body = PhysicsBody::createBox(blt4->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt4->setPhysicsBody(body);
	}
	blt4->setPosition(Vec2(boss->getPosition().x, boss->getPosition().y - boss->getContentSize().height / 2));
	this->addChild(blt4, 10);
	blt4->setRotation(-22.5);
	float endX4;
	float endY4;
	float flyLen4;
	float flyVelocity = 200;
	if (blt4->getPosition().y*tan(0.3926991) > (768 - blt4->getPosition().x)) {
		endX4 = 0;
		endY4 = blt4->getPosition().y - (768 - blt4->getPosition().x) / tan(0.3926991);
		flyLen4 = (768 - blt4->getPosition().x) / sin(0.3926991);
	}
	else {
		endX4 = blt4->getPosition().x + blt4->getPosition().y*tan(0.3926991);
		endY4 = 0;
		flyLen4 = blt4->getPosition().y / cos(0.3926991);
	}
	float flyTime4 = flyLen4 / flyVelocity;

	auto actionMove4 = MoveTo::create(flyTime4, Point(endX4, endY4));
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyPath::removeBullet, this));
	Sequence* sequence4 = Sequence::create(actionMove4, actionDone, NULL);

	blt4->runAction(sequence4);
}

void EnemyPath::BossBullet5(float time) {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("instancePictures.plist", "instancePictures.png");
	Bullet *blt5 = Bullet::createBullet("bullet4.png");
	blt5->type = bullet_def;
	{
		auto body = PhysicsBody::createBox(blt5->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt5->setPhysicsBody(body);
	}
	blt5->setPosition(Vec2(boss->getPosition().x, boss->getPosition().y - boss->getContentSize().height / 2));
	this->addChild(blt5, 10);
	blt5->setRotation(135);
	float endX5;
	float endY5;
	float flyLen5;
	if (blt5->getPosition().y > (768 - blt5->getPosition().x)) {
		endY5 = blt5->getPosition().y - (768 - blt5->getPosition().x);
		endX5 = 768;
		flyLen5 = (768 - blt5->getPosition().x)*sqrt(2);
	}
	else {
		endX5 = blt5->getPosition().y + blt5->getPosition().x;
		endY5 = 0;
		flyLen5 = blt5->getPosition().y*sqrt(2);
	}
	float flyVelocity = 200;
	float flyTime5 = flyLen5 / flyVelocity;

	auto actionMove5 = MoveTo::create(flyTime5, Point(endX5, endY5));
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyPath::removeBullet, this));
	Sequence* sequence5 = Sequence::create(actionMove5, actionDone, NULL);

	blt5->runAction(sequence5);
}

void EnemyPath::BossBullet6(float time) {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("instancePictures.plist", "instancePictures.png");
	Bullet *blt16 = Bullet::createBullet("bullet4.png");
	Bullet *blt26 = Bullet::createBullet("bullet4.png");
	Bullet *blt36 = Bullet::createBullet("bullet4.png");
	blt16->type = bullet_def;
	blt26->type = bullet_def;
	blt36->type = bullet_def;
	{
		auto body = PhysicsBody::createBox(blt16->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt16->setPhysicsBody(body);
	}
	{
		auto body = PhysicsBody::createBox(blt26->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt26->setPhysicsBody(body);
	}
	{
		auto body = PhysicsBody::createBox(blt36->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt36->setPhysicsBody(body);
	}
	blt16->setPosition(Vec2(boss->getPosition().x - 105.15, boss->getPosition().y));
	blt26->setPosition(Vec2(boss->getPosition().x - 125.15, boss->getPosition().y));
	blt36->setPosition(Vec2(boss->getPosition().x - 145.15, boss->getPosition().y));
	this->addChild(blt16);
	this->addChild(blt26);
	this->addChild(blt36);
	float flyVelocity = 200;
	float flyTime6 = blt16->getPosition().y / flyVelocity;

	auto actionMove6 = MoveTo::create(flyTime6, Point(blt16->getPosition().x, 0));
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyPath::removeBullet, this));
	Sequence* sequence6 = Sequence::create(actionMove6, actionDone, NULL);
	blt16->runAction(sequence6);
	blt26->runAction(sequence6->clone());
	blt36->runAction(sequence6->clone());
}

void EnemyPath::BossBullet7(float time) {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("instancePictures.plist", "instancePictures.png");
	Bullet *blt1 = Bullet::createBullet("bullet4.png");
	Bullet *blt2 = Bullet::createBullet("bullet4.png");
	Bullet *blt3 = Bullet::createBullet("bullet4.png");
	blt1->type = bullet_def;
	blt2->type = bullet_def;
	blt3->type = bullet_def;
	{
		auto body = PhysicsBody::createBox(blt1->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt1->setPhysicsBody(body);
	}
	{
		auto body = PhysicsBody::createBox(blt2->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt2->setPhysicsBody(body);
	}
	{
		auto body = PhysicsBody::createBox(blt3->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt3->setPhysicsBody(body);
	}
	blt1->setPosition(Vec2(boss->getPosition().x + 105.15, boss->getPosition().y));
	blt2->setPosition(Vec2(boss->getPosition().x + 125.15, boss->getPosition().y));
	blt3->setPosition(Vec2(boss->getPosition().x + 145.15, boss->getPosition().y));
	this->addChild(blt1);
	this->addChild(blt2);
	this->addChild(blt3);
	float flyVelocity = 200;
	float flyTime6 = blt1->getPosition().y / flyVelocity;

	auto actionMove6 = MoveTo::create(flyTime6, Point(blt1->getPosition().x, 0));
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyPath::removeBullet, this));
	Sequence* sequence6 = Sequence::create(actionMove6, actionDone, NULL);
	blt1->runAction(sequence6);
	blt2->runAction(sequence6->clone());
	blt3->runAction(sequence6->clone());
}



void EnemyPath::BossBullet21(float time) {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("instancePictures.plist", "instancePictures.png");
	Bullet *blt1 = Bullet::createBullet("bullet3.png");
	blt1->type = bullet_def;
	{
		auto body = PhysicsBody::createBox(blt1->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt1->setPhysicsBody(body);
	}
	blt1->setPosition(Vec2(boss->getPosition().x, boss->getPosition().y - boss->getContentSize().height / 2));
	this->addChild(blt1, 10);
	blt1->setRotation(45);
	float endX1;
	float endY1;
	float flyLen1;
	if (blt1->getPosition().x > blt1->getPosition().y) {
		endX1 = blt1->getPosition().x - blt1->getPosition().y;
		endY1 = 0;
		flyLen1 = blt1->getPosition().y*sqrt(2);
	}
	else {
		endX1 = 0;
		endY1 = blt1->getPosition().y - blt1->getPosition().x;
		flyLen1 = blt1->getPosition().x*sqrt(2);
	}
	float flyVelocity = 200;
	float flyTime1 = flyLen1 / flyVelocity;

	auto actionMove1 = MoveTo::create(flyTime1, Point(endX1, endY1));
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyPath::removeBullet, this));
	Sequence* sequence5 = Sequence::create(actionMove1, actionDone, NULL);

	blt1->runAction(sequence5);

}

void EnemyPath::BossBullet22(float time) {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("instancePictures.plist", "instancePictures.png");
	Bullet *blt2 = Bullet::createBullet("bullet3.png");
	blt2->type = bullet_def;
	{
		auto body = PhysicsBody::createBox(blt2->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt2->setPhysicsBody(body);
	}
	blt2->setPosition(Vec2(boss->getPosition().x, boss->getPosition().y - boss->getContentSize().height / 2));
	this->addChild(blt2, 10);
	blt2->setRotation(22.5);
	float endX2;
	float endY2;
	float flyLen2;
	float flyVelocity = 200;
	if (blt2->getPosition().y > blt2->getPosition().x / tan(0.3926991)) {
		endX2 = 0;
		endY2 = blt2->getPosition().y - blt2->getPosition().x / tan(0.3926991);
		flyLen2 = blt2->getPosition().x / sin(0.3926991);
	}
	else {
		endX2 = blt2->getPosition().x - blt2->getPosition().y*tan(0.3926991);
		endY2 = 0;
		flyLen2 = blt2->getPosition().y / cos(0.3926991);
	}
	float flyTime2 = flyLen2 / flyVelocity;

	auto actionMove2 = MoveTo::create(flyTime2, Point(endX2, endY2));
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyPath::removeBullet, this));
	Sequence* sequence2 = Sequence::create(actionMove2, actionDone, NULL);

	blt2->runAction(sequence2);
}

void EnemyPath::BossBullet23(float time) {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("instancePictures.plist", "instancePictures.png");
	Bullet *blt3 = Bullet::createBullet("bullet3.png");
	blt3->type = bullet_def;
	{
		auto body = PhysicsBody::createBox(blt3->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt3->setPhysicsBody(body);
	}
	blt3->setPosition(Vec2(boss->getPosition().x, boss->getPosition().y - boss->getContentSize().height / 2));
	this->addChild(blt3, 10);
	float endX3 = blt3->getPosition().x;
	float endY3 = 0;
	float flyVelocity = 200;
	float flyTime3 = endX3 / flyVelocity;
	auto actionMove3 = MoveTo::create(flyTime3, Point(endX3, endY3));
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyPath::removeBullet, this));
	Sequence* sequence3 = Sequence::create(actionMove3, actionDone, NULL);
	blt3->runAction(sequence3);
}

void EnemyPath::BossBullet24(float time) {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("instancePictures.plist", "instancePictures.png");
	Bullet *blt4 = Bullet::createBullet("bullet3.png");
	blt4->type = bullet_def;
	{
		auto body = PhysicsBody::createBox(blt4->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt4->setPhysicsBody(body);
	}
	blt4->setPosition(Vec2(boss->getPosition().x, boss->getPosition().y - boss->getContentSize().height / 2));
	this->addChild(blt4, 10);
	blt4->setRotation(-22.5);
	float endX4;
	float endY4;
	float flyLen4;
	float flyVelocity = 200;
	if (blt4->getPosition().y*tan(0.3926991) > (768 - blt4->getPosition().x)) {
		endX4 = 0;
		endY4 = blt4->getPosition().y - (768 - blt4->getPosition().x) / tan(0.3926991);
		flyLen4 = (768 - blt4->getPosition().x) / sin(0.3926991);
	}
	else {
		endX4 = blt4->getPosition().x + blt4->getPosition().y*tan(0.3926991);
		endY4 = 0;
		flyLen4 = blt4->getPosition().y / cos(0.3926991);
	}
	float flyTime4 = flyLen4 / flyVelocity;

	auto actionMove4 = MoveTo::create(flyTime4, Point(endX4, endY4));
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyPath::removeBullet, this));
	Sequence* sequence4 = Sequence::create(actionMove4, actionDone, NULL);

	blt4->runAction(sequence4);
}

void EnemyPath::BossBullet25(float time) {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("instancePictures.plist", "instancePictures.png");
	Bullet *blt5 = Bullet::createBullet("bullet3.png");
	blt5->type = bullet_def;
	{
		auto body = PhysicsBody::createBox(blt5->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt5->setPhysicsBody(body);
	}
	blt5->setPosition(Vec2(boss->getPosition().x, boss->getPosition().y - boss->getContentSize().height / 2));
	this->addChild(blt5, 10);
	blt5->setRotation(135);
	float endX5;
	float endY5;
	float flyLen5;
	if (blt5->getPosition().y > (768 - blt5->getPosition().x)) {
		endY5 = blt5->getPosition().y - (768 - blt5->getPosition().x);
		endX5 = 768;
		flyLen5 = (768 - blt5->getPosition().x)*sqrt(2);
	}
	else {
		endX5 = blt5->getPosition().y + blt5->getPosition().x;
		endY5 = 0;
		flyLen5 = blt5->getPosition().y*sqrt(2);
	}
	float flyVelocity = 200;
	float flyTime5 = flyLen5 / flyVelocity;

	auto actionMove5 = MoveTo::create(flyTime5, Point(endX5, endY5));
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyPath::removeBullet, this));
	Sequence* sequence5 = Sequence::create(actionMove5, actionDone, NULL);

	blt5->runAction(sequence5);
}







void EnemyPath::BossBullet26(float time) {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("instancePictures.plist", "instancePictures.png");
	Bullet *blt6 = Bullet::createBullet("bullet3.png");
	blt6->type = bullet_def;
	{
		auto body = PhysicsBody::createBox(blt6->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt6->setPhysicsBody(body);
	}
	blt6->setPosition(Vec2(boss->getPosition().x - 125.15, boss->getPosition().y));
	this->addChild(blt6);
	float flyVelocity = 200;
	float flyTime6 = blt6->getPosition().y / flyVelocity;

	auto actionMove6 = MoveTo::create(flyTime6, Point(blt6->getPosition().x, 0));
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyPath::removeBullet, this));
	Sequence* sequence6 = Sequence::create(actionMove6, actionDone, NULL);
	blt6->runAction(sequence6);
}

void EnemyPath::BossBullet27(float time) {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("instancePictures.plist", "instancePictures.png");
	Bullet *blt7 = Bullet::createBullet("bullet3.png");
	blt7->type = bullet_def;
	{
		auto body = PhysicsBody::createBox(blt7->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		blt7->setPhysicsBody(body);
	}
	blt7->setPosition(Vec2(boss->getPosition().x + 125.15, boss->getPosition().y));
	this->addChild(blt7);
	float flyVelocity = 200;
	float flyTime6 = blt7->getPosition().y / flyVelocity;

	auto actionMove6 = MoveTo::create(flyTime6, Point(blt7->getPosition().x, 0));
	auto actionDone = CallFuncN::create(
		CC_CALLBACK_1(EnemyPath::removeBullet, this));
	Sequence* sequence6 = Sequence::create(actionMove6, actionDone, NULL);
	blt7->runAction(sequence6);
}

void EnemyPath::chapter2() {
	schedule(schedule_selector(EnemyPath::setBulletBody), 0);
	schedule(schedule_selector(EnemyPath::setPlaneBody), 0);
	CallFuncN *fun1 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath5, this));
	CallFuncN *fun2 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath3, this));
	CallFuncN *fun3 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath1, this));
	CallFuncN *fun4 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath4, this));
	CallFuncN *fun5 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath2, this));
	CallFuncN *fun6 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath6, this));
	CallFuncN *fun0 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath7, this));
	CallFuncN *fun8 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runBoss, this));
	CallFuncN *fun7 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::MangerBoss, this));
	Sequence* seq = Sequence::create(
		DelayTime::create(2)
		, fun0,
		fun1,
		DelayTime::create(15),
		fun2,
		DelayTime::create(31),
		fun3,
		DelayTime::create(24),
		fun4,
		DelayTime::create(24),
		fun5,
		DelayTime::create(29),
		fun6,
		DelayTime::create(32),
		fun7,
		fun8,
		NULL);
	this->runAction(seq);

	//设置随机数
}

void EnemyPath::chapter3() {
	schedule(schedule_selector(EnemyPath::setBulletBody), 0);
	schedule(schedule_selector(EnemyPath::setPlaneBody), 0);
	CallFuncN *fun1 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath4, this));
	CallFuncN *fun2 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath5, this));
	CallFuncN *fun3 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath6, this));
	CallFuncN *fun4 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath1, this));
	CallFuncN *fun5 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath3, this));
	CallFuncN *fun6 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath2, this));
	CallFuncN *fun0 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runPath7, this));
	CallFuncN *fun8 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::runBoss, this));
	CallFuncN *fun7 = CallFuncN::create(CC_CALLBACK_0(EnemyPath::MangerBoss, this));
	Sequence* seq = Sequence::create(
		DelayTime::create(2)
		, fun0,
		fun1,
		DelayTime::create(24),
		fun2,
		DelayTime::create(15),
		fun3,
		DelayTime::create(32),
		fun4,
		DelayTime::create(24),
		fun5,
		DelayTime::create(31),
		fun6,
		DelayTime::create(29),
		fun7,
		fun8,
		NULL);
	this->runAction(seq);

	//设置随机数
}
void EnemyPath::mangerBossBullet() {
	Vector<Node*>allnodes = getChildren();
	for (int i = int(allnodes.size() - 1); i >= 0; i--) {
		auto node = allnodes.at(i);

		if (strcmp(typeid(*node).name(), typeid(NewEnemyPlane).name()) == 0) {
			NewEnemyPlane *Plane = (NewEnemyPlane*)node;
			if (plane->getTag() == 5) {
				schedule(schedule_selector(EnemyPath::BossBullet1), 12);
				schedule(schedule_selector(EnemyPath::BossBullet2), 12);
				schedule(schedule_selector(EnemyPath::BossBullet3), 12);
				schedule(schedule_selector(EnemyPath::BossBullet4), 12);
				schedule(schedule_selector(EnemyPath::BossBullet5), 12);

				schedule(schedule_selector(EnemyPath::BossBullet21), 12, 999, 3);
				schedule(schedule_selector(EnemyPath::BossBullet22), 12, 999, 3);
				schedule(schedule_selector(EnemyPath::BossBullet23), 12, 999, 3);
				schedule(schedule_selector(EnemyPath::BossBullet24), 12, 999, 3);
				schedule(schedule_selector(EnemyPath::BossBullet25), 12, 999, 3);

				schedule(schedule_selector(EnemyPath::BossBullet6), 12, 999, 6);
				schedule(schedule_selector(EnemyPath::BossBullet7), 12, 999, 6);

				schedule(schedule_selector(EnemyPath::BossBullet26), 12, 999, 9);
				schedule(schedule_selector(EnemyPath::BossBullet27), 12, 999, 9);


			}

		}
	}
}