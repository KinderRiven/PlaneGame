#include "stdafx.h"
#include "Enemy2.h"
#include "GameMessage.h"
#include "GameNature.h"
#include "AllSpeed.h"
#include "AllLife.h"
#include "AllScore.h"
#include "AllHurt.h"
//virtual void draw(CDC* pDC);//��ͼ����
//virtual void move();
//void UpDatePos();
//bool return_dead();
//int  return_width();
//int  return_height();
//int  return_x();
//int  return_y();
//int  return_hurt();
//void goto_die();
//protected:
//	CBitmap bmp;		//ͼƬ
//	int width, height;	//ģ�͵Ĵ�С
//	int x, y;			//λ������
//	int speed;			//�ٶ�
//	int dir_x, dir_y;	//��������
//	int hurt;			//ÿ����Ʒ���˺���������ײ�˺����ӵ��˺�����Ʒ�˺�
//	bool is_dead;		//�ж��Ƿ�����
Enemy2::Enemy2()
{
	int w = GameMessage::rect.Width();
	int h = GameMessage::rect.Height();
	is_dead = false; //���ߵ�
	life = AllLife::life_enemy2;
	x = rand() % w;   y = -rand() % 200;
	width = 110; height = 85;
	speed = AllSpeed::speed_enemy2;
	get_dir();
	hurt = hurt = AllHurt::hurt_enemy2;				//��ײ�˺�
	score = AllScore::score_enemy2;				//����ĵ÷�
	bmp.LoadBitmap(3002);		//����λͼ
	if (x + width > w) x = w - width;
}
Enemy2::~Enemy2()
{
}
void Enemy2::draw(CDC* pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(NULL);
	memDC.SelectObject(&bmp);
	if (!is_dead){
		pDC->TransparentBlt(x, y, width, height, &memDC, 0, 0, width, height, RGB(0, 0, 0));
	}
}
void Enemy2::move()
{
	x = x + dir_x * speed;
	y = y + dir_y * speed;
	ChangePos();
}
void Enemy2::ChangePos()
{
	int w = GameMessage::rect.Width();
	int h = GameMessage::rect.Height();
	if (y > h){
		x = rand() % w;
		y = -rand() % 200;
		get_dir();
		if (x + width > w) x = w - width;
	}
}
void Enemy2::get_dir()
{
	dir_y = 1;
	int t = rand() % 5;
	if (t == 0) dir_x = 0;
	if (t == 1) dir_x = 1;
	if (t == 2) dir_x = 2; 
	if (t == 3) dir_x = -1;
	if (t == 4) dir_x = -2;
}
bool Enemy2::Attack()
{
	int t = rand() % 20;
	if (t == 7) return true;
	else  return false;
}