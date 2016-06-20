#include "stdafx.h"
#include "Things.h"
#include "GameMessage.h"
Things::Things(int lv,int xx,int yy) //λ�ã�����
{
	x = xx; y = yy;
	Lv = lv;
	width   = 60;
	height  = 60;
	is_dead = false; //��Ʒ����
	bmp.LoadBitmap(lv + 6000);
	//��Ʒ����
	if (lv == 1) value = 0;
	if (lv == 2) value = 1000;
	if (lv == 3) value = 1500;
	if (lv == 4) value = 500;
	speed = 10;
	dir_y = 1;
	int t = rand() % 3;
	dir_x = t - 1; //�������
}
Things::~Things()
{
}
void Things::SetPosition()   //�ж���Ʒ�Ƿ����
{
	int w = GameMessage::rect.Width();
	int h = GameMessage::rect.Height();
	if (x < -width || y < -height || x > w || y > h)
		is_dead = true;
}
void Things::draw(CDC* pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(NULL);
	memDC.SelectObject(&bmp);
	pDC->TransparentBlt(x, y, width, height, &memDC, 0, 0, width, height, RGB(255, 255, 255));
}
void Things::move()
{
	x = x + dir_x * speed;
	y = y + dir_y * speed;
}
