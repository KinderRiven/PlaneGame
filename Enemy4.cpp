#include "stdafx.h"
#include "Enemy4.h"
#include "AllHurt.h"
#include "AllLife.h"
#include "AllScore.h"
#include "AllSpeed.h"
#include "GameMessage.h"
//int speed;			//�ٶ�.
//bool is_dead;		//�ж��Ƿ�����
//CBitmap bmp;		//ͼƬ
//int width, height;	//ģ�͵Ĵ�С
//int x, y;			//λ������
//int dir_x, dir_y;	//��������
//int hurt;			//ÿ����Ʒ���˺���������ײ�˺����ӵ��˺�����Ʒ�˺�
Enemy4::Enemy4(int xx,int yy,int dx,int dy)
{
	x = xx; y = yy; dir_x = dx; dir_y = dy;
	width = 200; height = 121;
	speed = AllSpeed::speed_enemy4;
	hurt  = AllHurt::hurt_enemy4;
	score = AllScore::score_enemy4;
	life  = AllLife::life_enemy4;
	is_dead = false;
	bmp.LoadBitmap(Enemy_y5);
}
Enemy4::~Enemy4()
{
}
void Enemy4::move()
{
	x = x + dir_x * speed;
	y = y + dir_y * speed;
	SetPos();
}
void Enemy4::SetPos()
{
	int w = GameMessage::rect.Width();
	int h = GameMessage::rect.Height();
	if (y > h) y = -200;
}
void Enemy4::draw(CDC* pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(NULL);
	memDC.SelectObject(&bmp);
	if (!is_dead){
		pDC->TransparentBlt(x, y, 150, 100, &memDC, 0, 0, width, height, RGB(0, 0, 0));
	}
}