#pragma once
#include "GameNature.h"
//��Ʒ����
//��Ʒ���·�Ϊ3�࣬һ���Ǽ�Ѫ��һ����������һ�����ӵ�����
//CBitmap bmp;		//ͼƬ
//int width, height;	//ģ�͵Ĵ�С
//int x, y;			//λ������
//int dir_x, dir_y;	//��������
//int hurt;			//ÿ����Ʒ���˺���������ײ�˺����ӵ��˺�����Ʒ�˺�
class Things:
	public GameNature
{
public:
	Things(int lv,int x,int y);
	void draw(CDC* pDC);
	void SetPosition();
	void move();
	~Things();
	int Lv;		//�����ӵ�������
	int value;	//��������		
	int speed;
};

