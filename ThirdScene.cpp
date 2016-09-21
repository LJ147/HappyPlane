#include "ThirdScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include"AudioEngine.h"
#include "MainGamePauseLayer.h"
#include "EnemyPath.h"
#include "HeroPlane.h"
#include "NewEnemyPlane.h"
#include "Bullet.h"
#include"Gameover.h"
#include"Victory.h"
#include "Buff.h"
#include "AudioEngine.h"
#include "UserDate.h"
#include"FlyWord.h"
#include"Bomb.h"
using namespace experimental;
using namespace cocostudio::timeline;
using namespace cocos2d;

USING_NS_CC;

static ThirdScene *m_mainscene = NULL;
//�������������
Scene* ThirdScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	Vect gravity = Vect(0.0f, 0.0f);//0����
	scene->getPhysicsWorld()->setGravity(gravity);
	// 'layer' is an autorelease object
	if (m_mainscene != NULL) {
		//delete m_mainscene;
	}
	// add layer as a child to scene
	m_mainscene = ThirdScene::create();
	scene->addChild(m_mainscene);
	// return the scene
	return scene;
}
//��������
ThirdScene::~ThirdScene()
{
	//m_event->autorelease();
	//_eventDispatcher->removeEventListenersForTarget(this);
}

// on "init" you need to initialize your instance
bool ThirdScene::init()
{

	if (!Layer::init())
	{
		return false;
	}
	extern int a;
	a = 3;
	FlyWord *word = FlyWord::create(6, Vec2(384, 512));
	//addChild(word,1);

	scoreNum = 0;
	addtionalScore = 0;
	//_eventDispatcher->removeEventListenersForTarget(this);
	visibleSize = Director::getInstance()->getWinSize();
	//����ҷ�Ӣ�۷ɻ�
	{
		heroPlaneG = HeroPlane::createHeroPlane("plane3.png");
		heroPlaneG->setAnchorPoint(Vec2(0.5, 0.5));
		heroPlaneG->setPosition(Vec2(visibleSize.width / 2, 100));
		heroPlaneG->setTag(4);//�ҷ��ɻ�tagΪ4
		{
			//��������body ��������
			auto body = PhysicsBody::createBox(heroPlaneG->getContentSize());
			body->setCollisionBitmask(0x0);
			body->setContactTestBitmask(0xFFFFFFFF);
			body->setCategoryBitmask(0xFFFFFFFF);
			heroPlaneG->setPhysicsBody(body);
		}
		{//��ʼʱ����˸����
			auto fadeout1 = FadeOut::create(0.15);
			auto delay1 = DelayTime::create(0.001);
			auto fadein1 = FadeIn::create(0.15);
			auto fadeout2 = FadeOut::create(0.15);
			auto delay2 = DelayTime::create(0.001);
			auto fadein2 = FadeIn::create(0.15);
			auto fadeout3 = FadeOut::create(0.15);
			auto delay3 = DelayTime::create(0.001);
			auto fadein3 = FadeIn::create(0.15);
			auto fadeout4 = FadeOut::create(0.15);
			auto delay4 = DelayTime::create(0.001);
			auto fadein4 = FadeIn::create(0.15);
			auto seq = Sequence::create(fadeout1, delay1, fadein1, fadeout2, delay2, fadein2, fadeout3, delay3, fadein3, fadeout4, delay4, fadein4, nullptr);
			heroPlaneG->runAction(seq);
		}

		this->addChild(heroPlaneG, 1);
	}
	/*	�������� �з��ɻ�*/
	{
		auto enemyPath1 = EnemyPath::create();
		enemyPath1->getHero(heroPlaneG);
		addChild(enemyPath1, 1);
		enemyPath1->chapter3();//ֱ�ӵ���
	}
	//�����ɼ���ǩ
	score = Label::createWithTTF("Score: 0", "arial.ttf", 35);
	score->setAnchorPoint(Vec2(0, 1));
	score->setPosition(Vec2(20, 1024));
	score->setColor(Color3B(255, 97, 0));
	addChild(score, 1);
	//Ѫ��HP��ǩ
	healthPoint = Label::createWithTTF("HP: 100", "arial.ttf", 35);
	healthPoint->setAnchorPoint(Vec2(0, 1));
	healthPoint->setPosition(Vec2(20, 954));
	healthPoint->setColor(Color3B(255, 97, 0));
	addChild(healthPoint, 1);

	/*��Ҫ��������� �����ɻ����ӵ�*/
	{
		//��ʱ��������л�
		//	schedule(schedule_selector(ThirdScene::managerEnemyPlanes), 1.0f);
		//��ʱ�������Buff����
		schedule(schedule_selector(ThirdScene::manageBuff), 6.0f);
		//��ʱ�����ҷ��ӵ����ƶ�
		schedule(schedule_selector(ThirdScene::mangerMainBullet), 0.2f);
		//��ʱ�ƶ��ӵ�
		schedule(schedule_selector(ThirdScene::moveBullet), 0.005f);
		//��Ƶ���ж��Ƿ���Ϸ����
		schedule(schedule_selector(ThirdScene::judgeWhetherGameIsOver), 0.01f);
	}
	/*�ֲ����� ���ð�ť*/
	{
		//����ͼһ
		bgImg = Sprite::create("gameBgp3.png");
		bgImg->setAnchorPoint(Vec2(0.5, 0.5));
		bgImg->setPosition(Vec2(384, 512));
		addChild(bgImg);
		//�ڶ��ű���ͼ
		bgTop = Sprite::create("gameBgp3.png");
		bgTop->setAnchorPoint(Vec2(0.5, 0.5));
		bgTop->setPosition(Vec2(384, 1536));
		addChild(bgTop);
		schedule(schedule_selector(ThirdScene::updateBgImg), 0.009);

		//���ð�ť
		Sprite*normal1 = Sprite::create("setButtonNormal.png");
		Sprite*seleted1 = Sprite::create("setButtonSelected.png");
		MenuItemSprite*setBtn1 = MenuItemSprite::create(normal1, seleted1, CC_CALLBACK_1(ThirdScene::changeToSetScene, this));
		Menu *btn1 = Menu::create(setBtn1, NULL);
		btn1->setAnchorPoint(Vec2(0.5, 0.5));
		btn1->setPosition(Vec2(721.5, 974));
		addChild(btn1);
	}

	/*�ƶ��ҷ��ɻ�  �߽�����Ӧ�¼�*/
	{
		//�������������¼�
		auto listener1 = EventListenerTouchOneByOne::create();
		//�����Ƿ񴫵ݴ���
		listener1->setSwallowTouches(true);
		//ͨ�� lambda ���ʽʵ�ִ����¼��Ļص�����
		listener1->onTouchBegan = [](Touch* touch, Event* event) {
			// target��ΪheroPlaneG�������
			auto target = static_cast<Sprite*>(event->getCurrentTarget());
			Point locationInNode = target->convertToNodeSpace(touch->getLocation());
			Size s = target->getContentSize();
			Rect rect = Rect(0, 0, s.width, s.height);
			// �����������
			if (rect.containsPoint(locationInNode))
			{
				return true;
			}
			return false;
		};
		// ����������ƶ�
		listener1->onTouchMoved = [](Touch* touch, Event* event) {
			auto target = static_cast<Sprite*>(event->getCurrentTarget());
			CCSize planeSize = target->getContentSize();
			Size visibleSize = Director::getInstance()->getVisibleSize();
			// �ֱ��ж��ĸ��߽�
			if (target->getPositionX() > visibleSize.width - planeSize.width / 2) {
				target->setPositionX(visibleSize.width - planeSize.width / 2);
			}
			if (target->getPositionY() > visibleSize.height - planeSize.height / 2) {
				target->setPositionY(visibleSize.height - planeSize.height / 2);
			}
			if (target->getPositionX() < planeSize.width / 2)
			{
				target->setPositionX(planeSize.width / 2);
			}
			if (target->getPositionY() < planeSize.height / 2)
			{
				target->setPositionY(planeSize.height / 2);
			}
			// �ƶ�����
			target->setPosition(target->getPosition() + touch->getDelta());
		};
		// �������
		listener1->onTouchEnded = [=](Touch* touch, Event* event) {
			auto target = static_cast<Sprite*>(event->getCurrentTarget());
		};
		// �󶨼����¼��;���
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, heroPlaneG);
	}

	/*��ײ���*/
	{
		// ע��������ײ�¼�����
		m_event = EventListenerPhysicsContact::create();
		m_event->onContactBegin = [this](PhysicsContact& contact)
		{
			auto spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();
			auto spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();
			//�ҷ��ӵ���з��ɻ�����ײ
			//spriteAΪ�ӵ���spriteBΪ�з��ɻ�
			if (spriteA && spriteB &&spriteA->getTag() == 0
				&& spriteB->getTag() <= 3 && spriteB->getTag() >= 1) {
				NewEnemyPlane* local = (NewEnemyPlane*)spriteB;
				if (local->currentHp <= 0)
				{
					local->IsDead = true;
					planeBlowup(spriteB);
				}
				else
				{
					local->currentHp -= 1;
				}
				spriteA->removeFromParentAndCleanup(true);
			}
			//spriteBΪ�ӵ���spriteAΪ�з��ɻ�
			else if (spriteA &&spriteB &&spriteB->getTag() == 0
				&& spriteA->getTag() <= 3 && spriteA->getTag() >= 1)
			{
				NewEnemyPlane* local = (NewEnemyPlane*)spriteA;
				if (local->currentHp <= 0)
				{
					local->IsDead = true;
					planeBlowup(spriteA);
				}
				else
				{
					local->currentHp = (local->currentHp - 1);
				}
				spriteB->removeFromParentAndCleanup(true);
			}
			//spriteAΪ�ӵ���spriteBΪBOSS
			if (spriteA && spriteB &&spriteA->getTag() == 0
				&& spriteB->getTag() == 5) {
				NewEnemyPlane* local = (NewEnemyPlane*)spriteB;
				if (local->currentHp <= 0)
				{
					local->IsDead = true;
					//planeBlowup(spriteB);
					Bomb* bomb = Bomb::create();
					addChild(bomb, 10);
					bomb->PlayExplosion(spriteB->getPosition());
					IsBossDead = true;
				}
				else
				{
					local->currentHp -= 1;
				}
				spriteA->removeFromParentAndCleanup(true);
			}
			//spriteBΪ�ӵ���spriteAΪ�з��ɻ�
			else if (spriteA &&spriteB &&spriteB->getTag() == 0
				&& spriteA->getTag() == 5)
			{
				NewEnemyPlane* local = (NewEnemyPlane*)spriteA;
				if (local->currentHp <= 0)
				{
					local->IsDead = true;
					//planeBlowup(spriteA);

					IsBossDead = true;

				}
				else
				{
					local->currentHp = (local->currentHp - 1);
				}
				spriteB->removeFromParentAndCleanup(true);
			}


			/*  �ҷ��ɻ��͵з���ײ   */

			//�ҷ��ɻ��͵з��ɻ����� �ҷ��ɻ�spriteAΪtag��4�����з��ɻ�spriteBΪTag��1 2 3��
			else if (spriteA &&spriteB&&spriteA->getTag() == 4
				&& spriteB->getTag() >= 1 && spriteB->getTag() <= 3) {
				planeBlowup(spriteB);
				heroPlaneG->minusHp = 50;
				heroPlaneG->IsReduceBlood = true;
				refreshTheHP();
				return true;
			}
			//�ҷ��ɻ��͵з��ɻ����� �ҷ��ɻ�spriteBΪtag��4�����з��ɻ�spriteAΪTag��1 2 3��
			else if (spriteA && spriteB &&spriteA->getTag() >= 1 && spriteA->getTag() <= 3
				&& spriteB->getTag() == 4) {
				planeBlowup(spriteA);
				heroPlaneG->minusHp = 50;
				heroPlaneG->IsReduceBlood = true;
				refreshTheHP();
				return true;
			}
			//�ҷ��ɻ���BOSS���� �ҷ��ɻ�spriteAΪtag��4�����з��ɻ�spriteBΪTag��5��
			else if (spriteA&&spriteB&&spriteA->getTag() == 4
				&& spriteB->getTag() == 5) {
				heroPlaneG->minusHp = 50;
				heroPlaneG->IsReduceBlood = true;
				refreshTheHP();
				return true;
			}
			//�ҷ��ɻ��͵з�BOSS���� �ҷ��ɻ�spriteBΪtag��4�����з��ɻ�spriteAΪTag��5��
			else if (spriteA && spriteB &&spriteA->getTag() == 5
				&& spriteB->getTag() == 4) {
				heroPlaneG->minusHp = 50;
				heroPlaneG->IsReduceBlood = true;
				refreshTheHP();
				return true;
			}
			//�ҷ��ɻ��͵з��ӵ����� �ҷ��ɻ�spriteAΪtag��4�����з��ӵ�spriteBΪTag��9��
			else if (spriteA &&spriteB&&spriteA->getTag() == 4
				&& spriteB->getTag() == 9) {
				spriteB->removeFromParentAndCleanup(true);
				heroPlaneG->IsThreeShooting = false;
				heroPlaneG->IsDoubleShooting = false;
				return true;
			}
			//�ҷ��ɻ��͵з��ӵ����� �ҷ��ɻ�spriteBΪtag��4�����з��ɻ�spriteAΪTag��9��
			else if (spriteA && spriteB &&spriteA->getTag() == 9
				&& spriteB->getTag() == 4) {
				spriteA->removeFromParentAndCleanup(true);
				heroPlaneG->IsThreeShooting = false;
				heroPlaneG->IsDoubleShooting = false;
				return true;
			}
			// ������ײ
			else  if (spriteA &&spriteB&&spriteA->getTag() == 4
				&& spriteB->getTag() >= 6 && spriteB->getTag() <= 8) {
				switch (spriteB->getTag())
				{
				case 6:
					heroPlaneG->IsDoubleShooting = true;//˫���ӵ�
					heroPlaneG->IsThreeShooting = false;
					break;
				case 7:
					heroPlaneG->currentHp = 100;//����ѪҺ
					heroPlaneG->IsAddBlood = true;
					refreshTheHP();
					break;
				case 8:
					heroPlaneG->IsThreeShooting = true;//�����ӵ�
					heroPlaneG->IsDoubleShooting = false;
					break;
				default:
					break;
				}
				removeBuff(spriteB);
				return true;
			}
			else if (spriteA && spriteB &&spriteA->getTag() >= 6 && spriteB->getTag() <= 8
				&& spriteB->getTag() == 4) {
				switch (spriteA->getTag())
				{
				case 6:
					heroPlaneG->IsDoubleShooting = true;
					heroPlaneG->IsThreeShooting = false;
					break;
				case 7:
					heroPlaneG->currentHp = 100;
					heroPlaneG->IsAddBlood = true;
					refreshTheHP();
					break;
				case 8:
					heroPlaneG->IsThreeShooting = true;
					heroPlaneG->IsDoubleShooting = false;
					break;
				default:
					break;
				}
				removeBuff(spriteA);
				return true;
			}
		};
		m_event->onContactPostSolve = [](PhysicsContact& contact,
			const PhysicsContactPostSolve& solve) {
		};
		Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(
			m_event, 1);
	}
	return true;
}
//��ʼ������
void ThirdScene::initAllParamters() {

}
//���ð�ť
void ThirdScene::changeToSetScene(Ref *object) {
	/*��ȡ��ǰ������ͼƬ������*/
	auto size = Director::getInstance()->getWinSize();
	render = RenderTexture::create(size.width, size.height);
	//��ʼ��ȡ����
	render->begin();
	//���ýڵ��visit�������뵽��Ⱦ��
	Director::getInstance()->getRunningScene()->visit();
	//����
	render->end();
	render->retain();
	auto _schedule = this->getScheduler();
	auto replaceScene = [&](float tm)
	{
		//����л�����
		Director::getInstance()->pushScene(MainGamePauseLayer::createScene(render));
	};
	_schedule->schedule(replaceScene, this, 0.0f, 0, 0.0f, false, "screenshot1");
}

//�����ҷ��ɻ��ӵ�
void ThirdScene::mangerMainBullet(float time) {

	if (heroPlaneG->IsThreeShooting == true)
	{
		blt1 = Bullet::createBullet("bullet1.png");
		blt2 = Bullet::createBullet("bullet1.png");
		blt3 = Bullet::createBullet("bullet1.png");

		Vec2 planeLocal = heroPlaneG->getPosition();
		auto planeLocal1 = Vec2(planeLocal.x - 12, planeLocal.y + 65);
		auto planeLocal2 = Vec2(planeLocal.x + 4, planeLocal.y + 65);
		auto planeLocal3 = Vec2(planeLocal.x + 20, planeLocal.y + 65);

		blt1->setPosition(planeLocal1);
		blt1->type = bullet_main;
		blt1->setTag(0);

		blt2->setPosition(planeLocal2);
		blt2->type = bullet_main;
		blt2->setTag(0);

		blt3->setPosition(planeLocal3);
		blt3->type = bullet_main;
		blt3->setTag(0);
		{
			//��������body
			auto body = PhysicsBody::createBox(blt1->getContentSize());
			//body->setContactTestBitmask(0x08);
			body->setCollisionBitmask(0x0);
			body->setContactTestBitmask(0xFFFFFFFF);
			body->setCategoryBitmask(0xFFFFFFFF);
			blt1->setPhysicsBody(body);

			auto body2 = PhysicsBody::createBox(blt2->getContentSize());
			body2->setCollisionBitmask(0x0);
			body2->setContactTestBitmask(0xFFFFFFFF);
			body2->setCategoryBitmask(0xFFFFFFFF);
			blt2->setPhysicsBody(body2);

			auto body3 = PhysicsBody::createBox(blt3->getContentSize());
			body3->setCollisionBitmask(0x0);
			body3->setContactTestBitmask(0xFFFFFFFF);
			body3->setCategoryBitmask(0xFFFFFFFF);
			blt3->setPhysicsBody(body3);
		}
		addChild(blt1, 1);
		addChild(blt2, 1);
		addChild(blt3, 1);

	}
	else
	{
		if (heroPlaneG->IsDoubleShooting == true)
		{
			blt1 = Bullet::createBullet("bullet2.png");
			blt2 = Bullet::createBullet("bullet2.png");

			Vec2 planeLocal = heroPlaneG->getPosition();
			blt1->type = bullet_main;
			auto planeLocal1 = Vec2(planeLocal.x - 2, planeLocal.y + 65);
			auto planeLocal2 = Vec2(planeLocal.x + 10, planeLocal.y + 65);

			blt1->setPosition(planeLocal1);
			blt1->type = bullet_main;
			blt1->setTag(0);

			blt2->setPosition(planeLocal2);
			blt2->type = bullet_main;
			blt2->setTag(0);
			{
				//��������body
				auto body = PhysicsBody::createBox(blt1->getContentSize());
				//body->setContactTestBitmask(0x08);
				body->setCollisionBitmask(0x0);
				body->setContactTestBitmask(0xFFFFFFFF);
				body->setCategoryBitmask(0xFFFFFFFF);
				blt1->setPhysicsBody(body);

				auto body2 = PhysicsBody::createBox(blt2->getContentSize());
				body2->setCollisionBitmask(0x0);
				body2->setContactTestBitmask(0xFFFFFFFF);
				body2->setCategoryBitmask(0xFFFFFFFF);
				blt2->setPhysicsBody(body2);
			}
			addChild(blt1, 1);
			addChild(blt2, 1);
		}
		else
		{
			blt1 = Bullet::createBullet("bullet3.png");
			Vec2 planeLocal = heroPlaneG->getPosition();
			blt1->type = bullet_main;
			planeLocal = Vec2(planeLocal.x + 4, planeLocal.y + 65);
			blt1->setPosition(planeLocal);
			blt1->setTag(0);
			{
				//��������body
				auto body = PhysicsBody::createBox(blt1->getContentSize());
				//body->setContactTestBitmask(0x08);
				body->setCollisionBitmask(0x0);
				body->setContactTestBitmask(0xFFFFFFFF);
				body->setCategoryBitmask(0xFFFFFFFF);
				blt1->setPhysicsBody(body);
			}
			addChild(blt1, 1);
		}
	}
}

//�Ƴ��ӵ�
void ThirdScene::removeBullet(Ref *object) {
	Bullet *blt = (Bullet *)object;
	blt->stopAllActions();
	removeChild(blt);
}
//�Ƴ�����
void ThirdScene::removeBuff(Ref *object) {
	Buff *buff = (Buff *)object;
	addtionalScore = 5;
	refreshTheScore();
	buff->stopAllActions();
	removeChild(buff);
}
void ThirdScene::removeHeroPlane(Ref * object)
{

}

void ThirdScene::heroPlaneDie(Ref * object)
{
}

//����������ɵз��ɻ� �����㷨��������
void ThirdScene::managerEnemyPlanes(float time) {
	if (this->enemyNumber < 1000) {
		this->enemyNumber++;
		NewEnemyPlane *enemy = NewEnemyPlane::createNewEnemyPlane("missile.png");
		enemy->setTag(3);
		enemy->setTypeOfPlane(3);

		int Xlocal = random(50, 600);
		int Ylocal = (1050);
		int ZXLocal = Xlocal;
		int ZYLocal = -150;
		enemy->setPosition(Vec2(Xlocal, Ylocal));
		{
			//��������body
			auto body = PhysicsBody::createBox(enemy->getContentSize());
			body->setCollisionBitmask(0x0);
			body->setContactTestBitmask(0xFFFFFFFF);
			body->setCategoryBitmask(0xFFFFFFFF);
			enemy->setPhysicsBody(body);
		}
		this->addChild(enemy, 1);
		MoveTo* move = MoveTo::create(random(3, 5), Vec2(ZXLocal, ZYLocal));
		CallFuncN* fun = CallFuncN::create(CC_CALLBACK_1(ThirdScene::removePlane, this));
		Sequence* seq = Sequence::create(move, fun, NULL);
		enemy->runAction(seq);
	}

}

//����������ɵ��� �����㷨
void ThirdScene::manageBuff(float time) {
	int buffNum = 0;
	if (buffNum < 1000) {
		buffNum++;

		char buffName[1003];
		int rand = random(1, 3);

		sprintf(buffName, "buff%d.png", rand);
		//log("buffName:%d", buffName);

		Buff *buff = Buff::createBuff(buffName);
		auto rand2 = rand + 5;
		buff->setTag(rand2);



		int Xlocal = random(50, 600);
		int Ylocal = (1050);
		int ZXLocal = Xlocal;
		int ZYLocal = -150;
		buff->setPosition(Vec2(Xlocal, Ylocal));
		{
			//��������body
			auto body = PhysicsBody::createBox(buff->getContentSize());
			body->setCollisionBitmask(0x0);
			body->setContactTestBitmask(0xFFFFFFFF);
			body->setCategoryBitmask(0xFFFFFFFF);
			buff->setPhysicsBody(body);
		}
		this->addChild(buff, 1);
		MoveTo* move = MoveTo::create(random(3, 5), Vec2(ZXLocal, ZYLocal));
		CallFuncN* fun = CallFuncN::create(CC_CALLBACK_1(ThirdScene::removePlane, this));
		Sequence* seq = Sequence::create(move, fun, NULL);
		buff->runAction(seq);
	}

}
//�Ƴ��ɻ�
void ThirdScene::removePlane(Node* pTarget) {
	auto plane = (Sprite*)pTarget;
	if (plane != nullptr) {

		plane->removeFromParentAndCleanup(true);
	}
}

/*�����ֲ�*/

void ThirdScene::changeBgImgPosition(Sprite *brImage_m) {
	if (brImage_m->getPosition().y <= -512) {
		brImage_m->setPosition(Vec2(384, 1534));
	}
	else {
		float yy = brImage_m->getPosition().y;
		yy -= 1;
		brImage_m->setPosition(Vec2(384, yy));
	}
}
void ThirdScene::updateBgImg(float time) {
	changeBgImgPosition(this->bgImg);
	changeBgImgPosition(this->bgTop);
}


//Ѫ��
void ThirdScene::changeTheHP() {
	if (heroPlaneG->currentHp < 0)
	{
		heroPlaneG->IsDead = true;
		heroPlaneG->minusHp = 0;
	}
	else
	{
		int nextHP = (heroPlaneG->currentHp - heroPlaneG->minusHp);
		if (heroPlaneG->IsAddBlood = true)
		{
			healthPoint->setString("HP: 100");
			heroPlaneG->IsAddBlood = false;

		}
		if (heroPlaneG->IsReduceBlood = true)
		{
			if (nextHP > 0)
			{
				char HPFormat[20];
				sprintf(HPFormat, "HP: %d", nextHP);
				healthPoint->setString(HPFormat);
				heroPlaneG->currentHp = heroPlaneG->currentHp - heroPlaneG->minusHp;
				heroPlaneG->minusHp = 0;
			}
			if (nextHP <= 0)
			{
				heroPlaneG->IsDead = true;
				healthPoint->setString("HP: 0");
				heroPlaneG->currentHp = 0;
				heroPlaneG->minusHp = 0;
			}
			heroPlaneG->IsReduceBlood = false;
		}
	}
}
//Ѫ��
void ThirdScene::refreshTheHP() {
	CallFunc* HPtextShow = CallFunc::create(CC_CALLBACK_0(ThirdScene::changeTheHP, this));
	Sequence* list = Sequence::create(HPtextShow, NULL);
	healthPoint->runAction(list);
	int hp = heroPlaneG->currentHp;
	switch (hp)
	{
	case 0:
		heroPlaneG->IsDead = true;
		break;
	default:
		break;
	}
}


//����ȫ���ӵ��ڵ�ʵ���ƶ�
void ThirdScene::moveBullet(float time) {
	Vector<Node*>allNodes = getChildren();
	for (int i = int(allNodes.size() - 1); i >= 0; i--) {
		auto node = allNodes.at(i);
		if (strcmp(typeid(*node).name(), typeid(Bullet).name()) == 0) {
			Bullet *Bullet_m = (Bullet*)node;
			if (Bullet_m->type == bullet_main) {
				auto yy = Bullet_m->getPosition().y;
				if (yy <= 1024) {
					Bullet_m->setPositionY(yy + 8);
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

//�ı����
void ThirdScene::changeTheScore() {
	char ScoreFormat[20];
	scoreNum = scoreNum + addtionalScore;
	sprintf(ScoreFormat, "score: %d", scoreNum);
	log("ScoreFormat:%s", ScoreFormat);
	score->setString(ScoreFormat);
	addtionalScore = 0;
}
//���붨ʱ��ˢ�·���
void ThirdScene::refreshTheScore() {
	changeTheScore();
}
//�ɻ���ը����  ֻ��ȡTag�жϲ����Ķ�������
void ThirdScene::planeBlowup(Sprite* plane) {
	auto animation = Animation::create();
	//������֮֡���ʱ����
	animation->setDelayPerUnit(0.2f);
	switch (plane->getTag())
	{
	case 1:
		animation->addSpriteFrameWithFile("enemyPlaneBoom1.png");
		addtionalScore = 2;
		break;
	case 2:
		animation->addSpriteFrameWithFile("enemyPlaneBoom2.png");
		addtionalScore = 4;
		break;
	case 3:
		animation->addSpriteFrameWithFile("enemyPlaneBoom3.png");
		addtionalScore = 8;
	case 4:
		animation->addSpriteFrameWithFile("heroPlaneBoom.png");
		break;
	default:
		break;
	}
	//extern bool soundOpen;
	if (soundOpen)
	{
		AudioEngine::play2d("Boom1.mp3", false, 0.1);
	}
	refreshTheScore();
	auto animate = Animate::create(animation);
	auto remove = CallFunc::create(
		CC_CALLBACK_0(ThirdScene::removePlane, this, plane));
	auto sequence = Sequence::create(animate, remove, nullptr);
	plane->runAction(sequence);
}
//�ж������Ƿ�����
void ThirdScene::judgeWhetherGameIsOver(float time) {
	if (heroPlaneG->IsDead) {
		//��������userdefault ����
		UserDefault::getInstance()->setIntegerForKey(NEW_SCORE, scoreNum);
		std::vector<int>scoreList;
		//װ��������
		scoreList.push_back(scoreNum);
		for (int i = 0; i < 3; i++) {
			int score1 = UserDefault::getInstance()->getIntegerForKey(StringUtils::format("%s%d", RANK_SCORE, i).c_str(), 0);
			scoreList.push_back(score1);
		}
		//�����������Ƚϴ�С
		std::sort(scoreList.begin(), scoreList.end(), [](int &a, int &b) {
			return a > b;
		});
		int rank = 0;
		//����󴢴�����
		for (auto i = scoreList.begin(); i != scoreList.end(); i++) {
			UserDefault::getInstance()->setIntegerForKey(StringUtils::format("%s%d", RANK_SCORE, rank).c_str(), *i);
			rank++;
		}
		gameOver();
		heroPlaneG->IsDead = false;

	}
	if (IsBossDead == true) {
		//����Ϸʧ��ʱ�Ĵ���������ͬ
		UserDefault::getInstance()->setIntegerForKey(NEW_SCORE, scoreNum);
		std::vector<int>scoreList;
		scoreList.push_back(scoreNum);
		for (int i = 0; i < 3; i++) {
			int score1 = UserDefault::getInstance()->getIntegerForKey(StringUtils::format("%s%d", RANK_SCORE, i).c_str(), 0);
			scoreList.push_back(score1);
		}
		std::sort(scoreList.begin(), scoreList.end(), [](int &a, int &b) {
			return a > b;
		});

		int rank = 0;
		for (auto i = scoreList.begin(); i != scoreList.end(); i++) {
			UserDefault::getInstance()->setIntegerForKey(StringUtils::format("%s%d", RANK_SCORE, rank).c_str(), *i);
			rank++;
		}
		/*CallFuncN *fun = CallFuncN::create(CC_CALLBACK_1(MainGame::victory, this));
		Sequence *seq = Sequence::create(DelayTime::create(2), fun, NULL);
		runAction(seq->clone());*/
		victory();
	}
}
//������Ϸ�����Ľ���
void ThirdScene::gameOver() {
	/*��ȡ��ǰ������ͼƬ������*/
	auto size = Director::getInstance()->getWinSize();
	//RenderTexture��һ��������Ⱦ�࣬������Ҫ��Ҫ��Ⱦ�ĵ�ǰ�����Ž�ȥ�����ǳ�ʼ�����Ĵ�С
	render = RenderTexture::create(size.width, size.height);
	//��ʼ��ȡ����
	render->begin();
	//���ýڵ��visit�������뵽��Ⱦ��
	Director::getInstance()->getRunningScene()->visit();
	//����
	render->end();
	render->retain();
	//3.0 ������Ҫ�ڽ���������һ֡���ܴ���RenderTexture
	auto _schedule = this->getScheduler();
	auto replaceScene = [&](float tm)
	{
		//����л�����
		Director::getInstance()->pushScene(Gameover::createScene(render));
	};
	_schedule->schedule(replaceScene, this, 0.0f, 0, 0.0f, false, "screenshot");
}
//������Ϸʧ��ʱ�Ľ���
void ThirdScene::victory() {
	/*��ȡ��ǰ������ͼƬ������*/
	auto size = Director::getInstance()->getWinSize();
	//RenderTexture��һ��������Ⱦ�࣬������Ҫ��Ҫ��Ⱦ�ĵ�ǰ�����Ž�ȥ�����ǳ�ʼ�����Ĵ�С
	render = RenderTexture::create(size.width, size.height);
	//��ʼ��ȡ����
	render->begin();
	//���ýڵ��visit�������뵽��Ⱦ��
	Director::getInstance()->getRunningScene()->visit();
	//����
	render->end();
	render->retain();
	//3.0 ������Ҫ�ڽ���������һ֡���ܴ���RenderTexture
	auto _schedule = this->getScheduler();
	auto replaceScene = [&](float tm)
	{
		//����л�����
		Director::getInstance()->pushScene(Victory::createScene(render));
	};
	_schedule->schedule(replaceScene, this, 0.0f, 0, 0.0f, false, "screenshot");
}
//��˸����
void ThirdScene::twinkle()
{
	auto fadeout1 = FadeOut::create(0.15);
	auto delay1 = DelayTime::create(0.001);
	auto fadein1 = FadeIn::create(0.15);
	auto fadeout2 = FadeOut::create(0.15);
	auto delay2 = DelayTime::create(0.001);
	auto fadein2 = FadeIn::create(0.15);
	auto fadeout3 = FadeOut::create(0.15);
	auto delay3 = DelayTime::create(0.001);
	auto fadein3 = FadeIn::create(0.15);
	auto fadeout4 = FadeOut::create(0.15);
	auto delay4 = DelayTime::create(0.001);
	auto fadein4 = FadeIn::create(0.15);
	auto seq = Sequence::create(fadeout1, delay1, fadein1, fadeout2, delay2, fadein2, fadeout3, delay3, fadein3, fadeout4, delay4, fadein4, nullptr);
	heroPlaneG->runAction(seq);
}

