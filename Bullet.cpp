#include "stdafx.h"
#include "Bullet.h"
#include "GameNature.h"
#include "resource.h"
#include "GameMessage.h"
#include "AllSpeed.h"
#include "AllHurt.h"
Bullet::Bullet(int v,int xx,int yy)
{

	bmp.LoadBitmap(4000 + v); //���ز�ͬ���͵��ӵ�
	x = xx; y = yy;				 //λ��
	dir_x = 0; dir_y = -1;
	is_dead = false; 
	if (v == 1){					 //hero1
		hurt = AllHurt::hurt_b1;					 //�����ÿһ���ӵ����˺�
		width = 27; height = 64;     //��С
		speed = AllSpeed::speed_b1;					 //�ӵ��ٶ�
		//��ʼ���ӵ��ķ���Ӧ�������ϵ�
	}
	else if (v == 2){				//���͵л�
		hurt = AllHurt::hurt_b2;					//�����ÿһ���ӵ����˺�
		width = 50; height = 101;    //��С
		speed = AllSpeed::speed_b2;					 //�ӵ��ٶ�
		//��ʼ���ӵ��ķ���Ӧ�������ϵ�
	}
	else if (v == 3){				//С�͵л�
		hurt = AllHurt::hurt_b3;
		width = 15; height = 15;
		speed = AllSpeed::speed_b3;
	}
	else if (v == 4){				//�����ӵ�
		hurt = AllHurt::hurt_b4;
		width = 27; height = 47;
		speed = AllSpeed::speed_b4;
	}
	else if (v == 5){				
		hurt = AllHurt::hurt_b5;
		width = 20; height = 20;
		speed = AllSpeed::speed_b5;
	}
	else if (v == 6)
	{
		hurt = AllHurt::hurt_b6;
		width = 50; height = 32;
		speed = AllSpeed::speed_b6;
	}
	else if (v == 7)
	{
		hurt = AllHurt::hurt_b7;
		width = 50; height = 50;
		speed = AllSpeed::speed_b7;
	}
	else if (v == 8)
	{
		hurt = AllHurt::hurt_b8;
		width = 43; height = 88;
		speed = AllSpeed::speed_b8;
	}
}
Bullet::Bullet(int v, int xx, int yy, int dx, int dy)
{
	bmp.LoadBitmap(4000 + v); //���ز�ͬ���͵��ӵ�
	x = xx; y = yy;			  //λ��
	dir_x = dx; dir_y = dy;
	is_dead = false;
	//J
	if (v == 1)
	{
		hurt = AllHurt::hurt_b1;				 //�����ÿһ���ӵ����˺�
		width = 27; height = 64;  //��С
		speed = AllSpeed::speed_b1;					 //�ӵ��ٶ�
		//��ʼ���ӵ��ķ���Ӧ�������ϵ�
	}
	//�л�����
	else if (v == 2){
		hurt = AllHurt::hurt_b2;				 //�����ÿһ���ӵ����˺�
		width = 50; height = 101;     //��С
		speed = AllSpeed::speed_b2;					 //�ӵ��ٶ�
		//��ʼ���ӵ��ķ���Ӧ�������ϵ�
	}
	//�л�С��
	else if (v == 3){
		hurt = AllHurt::hurt_b3;
		width = 8; height = 8;
		speed = AllSpeed::speed_b3;
	}
	//����
	else if (v == 4){
		hurt = AllHurt::hurt_b4;
		width = 27; height = 47;
		speed = AllSpeed::speed_b4;
	}
	//BOSS
	else if (v == 5){
		hurt = AllHurt::hurt_b5;
		width = 20; height = 20;
		speed = AllSpeed::speed_b5;
	}
	//����
	else if (v == 6)
	{
		hurt = AllHurt::hurt_b6;
		width = 50; height = 32;
		speed = AllSpeed::speed_b6;
	}
	else if (v == 7)
	{
		hurt = AllHurt::hurt_b7;
		width = 50; height = 50;
		speed = AllSpeed::speed_b7;
	}
	else if (v == 8)
	{
		hurt = AllHurt::hurt_b8;
		width = 43; height = 88;
		speed = AllSpeed::speed_b8;
	}
}
Bullet::~Bullet()
{

}
void Bullet::draw(CDC* pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(NULL);
	memDC.SelectObject(&bmp);
	if (!is_dead){
		pDC->TransparentBlt(x, y, width, height, &memDC, 0, 0, width, height, RGB(238, 243, 250));
	}
}
bool Bullet::is_break(){
	int w = GameMessage::rect.Width();
	int h = GameMessage::rect.Height();
	if (x < -500 || x > w + 500){
		is_dead = true;
		return true;
	}
	if (y < -500 || y > h + 500){
		is_dead = true;
		return true;
	}
	return false;
}
void Bullet::change(int sp,int dx,int dy)
{
	speed = sp;
	dir_x = dx; dir_y = dy;
}