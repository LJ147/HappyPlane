#pragma once
#ifndef __FLYWORD_H__
#define __FLYWORD_H__
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
class FlyWord : public Node {
public:
	//��������Ʈ��,create �� init ������һ���,����create��ʱ���Ȼ�����init
	static FlyWord* create(int lab, Point begin);
	//init��������3���������ֱ���Ʈ����ַ����������С�������￪ʼƮ��,init������������Ҫ�ǳ�ʼ��FloatWord���õ�Label
	bool init(int lab, Point begin);



	//���ִ��µ���Ʈ��
	void Flying(float time);
	//����Ʈ����ɾ�����ж���
	void Flyend();


private:
	int _fontSize;//�����С
	Point _begin;//Ҫ��ӵ��Ĺ�������ĵ�
	Label* m_plabel;//��������
	Label *level;

};
#endif // __FLYWORD_H__