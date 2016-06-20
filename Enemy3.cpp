#include "stdafx.h"
#include "Enemy3.h"
#include "resource.h"
#include "GameMessage.h"
#include "AllSpeed.h"
#include "AllLife.h"
#include "AllScore.h"
#include "AllHurt.h"
//int speed;			//�ٶ�
//CBitmap bmp;			//ͼƬ
//int width, height;	//ģ�͵Ĵ�С
//int x, y;				//λ������
//int dir_x, dir_y;		//��������
//int hurt;				//ÿ����Ʒ���˺���������ײ�˺����ӵ��˺�����Ʒ�˺�
//bool is_dead;			//�ж��Ƿ�����

Enemy3::Enemy3(int v,int xx,int yy,int dx,int dy)
{
	lv = v;//��������
	x = xx; y = yy;
	dir_x = dx; dir_y = dy;
	if (v == 0 || v == 1)
	{
		width  = 150;
		height = 200;
	}
	else
	{
		width  = 159;
		height = 175;
	}
	is_dead = false;
	speed = AllSpeed::speed_enemy3;
	hurt = AllHurt::hurt_enemy3;
	life = AllLife::life_enemy3;
	score = AllScore::score_enemy3;
	bmp.LoadBitmap(3010 + v);
}
Enemy3::~Enemy3()
{

}
void Enemy3::move()
{
	x = x + dir_x * speed;
	y = y + dir_y * speed;
	Change_Pos();
}
//1,2,3,4���ַ���
void Enemy3::Change_Pos()
{
	int h = GameMessage::rect.Height();
	int w = GameMessage::rect.Width();
	int r_y = rand() % h;
	if (lv == 0)
	{
		if (x > w / 2)
		{
			bmp.DeleteObject();
			dir_x = 1; dir_y = -1; //�����Ϸ�
			width = 159; height = 175;
			bmp.LoadBitmap(2 + 3010);
			lv = 2;
		}
		return;
	}
	else if (lv == 1)
	{
		if (x < w / 2)
		{
			bmp.DeleteObject();
			dir_x = -1; dir_y = -1;//�����Ϸ�
			bmp.LoadBitmap(3 + 3010);
			width = 159; height = 175;
			lv = 3;
		}
		return;
	}
	else if (lv == 2)
	{
		if (x < -100 || x > w || y < -100 || y > h) //�����
		{
			bmp.DeleteObject();
			bmp.LoadBitmap(1 + 3010);
			dir_x = -1; dir_y = 0;
			width = 150; height = 200;
			x = w + 100; y = r_y;
			lv = 1;
		}
		return;
	}
	else if (lv == 3)
	{
		if (x < -100 || x > w || y < -100 || y > h)
		{
			bmp.DeleteObject();
			bmp.LoadBitmap(0 + 3010);	//���ҷ�
			dir_x = 1; dir_y = 0;
			width = 150;  height = 200;
			x = -100; y = r_y;
			lv = 0;
		}
		return;
	}
}
void Enemy3::draw(CDC* pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(NULL);
	memDC.SelectObject(&bmp);
	if (!is_dead){
		pDC->TransparentBlt(x, y, 75,100 , &memDC, 0, 0, width, height, RGB(255, 255, 255));
	}
}
