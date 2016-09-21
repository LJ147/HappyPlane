#include "FlyWord.h"
FlyWord* FlyWord::create(int lab, CCPoint begin) {

	FlyWord* ret = new FlyWord();
	
	if (ret && ret->init(lab, begin)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);//��ȫɾ��
	return nullptr;
}

bool FlyWord::init(int tag, CCPoint begin) {
	if (!CCNode::init()) {
		return false;
	}
	//��ʼ��
	
	//չʾ��Ϣ
	//�����ʵ���ʵ������xml�ļ����ص��ʵ���
	auto *chnStrings = Dictionary::createWithContentsOfFile("FlyWord.xml");
	//ͨ��xml�ļ��е�key��ȡvalue
	const char *str1 = ((String*)chnStrings->objectForKey("string1"))->getCString();
	//����һ����ǩ��ʾ����
	auto* label1 = Label::create(str1, "YouYuan.ttf", 36);
	

	const char *str2 = ((String*)chnStrings->objectForKey("string2"))->getCString();
	auto* label2 = Label::create(str2, "YouYuan.ttf", 36);
	

	const char *str3 = ((String*)chnStrings->objectForKey("string3"))->getCString();
	auto* label3 = Label::createWithTTF(str3, "YouYuan.ttf", 36);

	const char *str4 = ((String*)chnStrings->objectForKey("string4"))->getCString();
	auto* label4 = Label::create(str4, "YouYuan.ttf", 50);
	const char *str5 = ((String*)chnStrings->objectForKey("string5"))->getCString();
	auto* label5 = Label::create(str5, "YouYuan.ttf", 50);
	const char *str6 = ((String*)chnStrings->objectForKey("string6"))->getCString();
	auto* label6 = Label::create(str6, "YouYuan.ttf", 50);

	
	_begin = begin;
	ccColor3B RGB;
	RGB.r = 255;
	RGB.g = 165;
	RGB.b = 0;
	ScaleTo*max = ScaleTo::create(0.5, 2);
	switch (tag) {
	case 1:
		m_plabel = label1;
		m_plabel->setColor(RGB);
		m_plabel->runAction(max);
		break;
	case 2:
		m_plabel = label2;
		m_plabel->setColor(RGB);
		m_plabel->runAction(max);
		break;
	case 3:
		m_plabel = label3;
		m_plabel->setColor(RGB);
		m_plabel->runAction(max);
		break;
	case 4:
		m_plabel = label4;
		m_plabel->setColor(RGB);
	
		break;
	case 5:
		m_plabel = label5;
		m_plabel->setColor(RGB);
		
	case 6:
		m_plabel = label6;
		m_plabel->setColor(RGB);
		
		break;
	default:
		break;
	}
	this->addChild(m_plabel);
	this->setPosition(ccp(begin.x, begin.y));
	//��ʼ����ɺ�Ϳ�ʼƮ����

	if (tag < 4) {
		Flying(0.5f);
	}
	else {
		Flying(2.0f);
	}

	

	return true;
}

//���ִ��µ���Ʈ��
void FlyWord::Flying(float time)
{

	CCMoveBy* moveact = CCMoveBy::create(2, CCPointMake(0, 70));//0.5�������ƶ�70

																   //�����ص�����������Ʈ�����
	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(FlyWord::Flyend));
	//������������
	CCActionInterval* act = CCSequence::create(moveact, callFunc, NULL);
	//setVisible(true);
	this->runAction(act);


}


void FlyWord::Flyend()
{
	//���֮��Ѹö�����ڴ���ɾ����
	this->removeAllChildrenWithCleanup(true);
	this->removeFromParentAndCleanup(true);
}

