#pragma once
#include "GameNature.h"
//public:
//	GameNature();
//	~GameNature();
//	virtual void draw(CDC* pDC);//��ͼ����
//	virtual void move();
//	void UpDatePos();
//	bool return_dead();
//	int  return_width();
//	int  return_height();
//	int  return_x();
//	int  return_y();
//	int  return_hurt();
//	void goto_die();
//	int speed;			//�ٶ�
//protected:
//	CBitmap bmp;		//ͼƬ
//	int width, height;	//ģ�͵Ĵ�С
//	int x, y;			//λ������
//	int dir_x, dir_y;	//��������
//	int hurt;			//ÿ����Ʒ���˺���������ײ�˺����ӵ��˺�����Ʒ�˺�
//	bool is_dead;		//�ж��Ƿ�����
class Enemy3 :
	public GameNature
{
public:
	 Enemy3(int v,int xx,int yy,int dx,int dy);
	~Enemy3();
	void move();
	void Change_Pos();
	void draw(CDC* pDC);
	int life;
	int score;
	int lv;//3�ŵл�������,0��1��2����3����
};

