#pragma once
#include "GameMessage.h"
#include "GameNature.h"
//int speed;			//�ٶ�.
//bool is_dead;		//�ж��Ƿ�����
//CBitmap bmp;		//ͼƬ
//int width, height;	//ģ�͵Ĵ�С
//int x, y;			//λ������
//int dir_x, dir_y;	//��������
//int hurt;			//ÿ����Ʒ���˺���������ײ�˺����ӵ��˺�����Ʒ�˺�
class Enemy4:
	public GameNature
{
public:
	Enemy4(int x,int y,int dx = 0,int dy = 1);
	~Enemy4();
	void move();
	void SetPos();
	void draw(CDC* pDC);
	int score;
	int life;
};

