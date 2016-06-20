#include "stdafx.h"
#include "Enemy1.h"
#include "GameMessage.h"
#include "AllLife.h"
#include "AllScore.h"
#include "AllHurt.h"
//  ����һ��
//	GameNature();
//	~GameNature();
//	virtual void draw(CDC* pDC);//��ͼ����
//	virtual void move();
//	void UpDatePos();
//	CBitmap bmp;		//ͼƬ
//	int width, height;	//ģ�͵Ĵ�С
//	int x, y;			//λ������
//	int speed;			//�ٶ�
//	int dir_x, dir_y;	//��������
//	int hurt;			//ÿ����Ʒ���˺���������ײ�˺����ӵ��˺�����Ʒ�˺�
//	bool is_dead;		//�ж��Ƿ�����
Enemy1::Enemy1()
{
	int w = GameMessage::rect.Width();
	int h = GameMessage::rect.Height();
	is_dead = false; //���ߵ�
	life = AllLife::life_enemy1;
	width = 208; height = 157;
	x = rand() % w;   y = -300;
	speed = rand() % 15 + 5;
	dir_x = 0; dir_y = 1;	//����һ��ʼ������
	hurt = AllHurt::hurt_enemy1;			//��ײ�˺�
	score = AllScore::score_enemy1;			//����ĵ÷�
	bmp.LoadBitmap(3001);	//����λͼ
	if (x + width > w) x = w - width;
}
Enemy1::~Enemy1()
{
}
void Enemy1::move()
{
	x = x + dir_x * speed;
	y = y + dir_y * speed;
	Change_Dir(); //�ı��ƶ��켣
}
void Enemy1::Change_Dir()
{
	int h = GameMessage::rect.Height();
	if (y > h/3) //���ط�
	{
		speed = rand() % 10 + 5;
		dir_x = 0;
		dir_y = -1;
	}
	if (y < -50) //��ǰ��
	{
		speed = rand() % 20 + 5;
		dir_x = 0;
		dir_y = 1;
	}
}
void Enemy1::draw(CDC *pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(NULL);
	memDC.SelectObject(&bmp);
	if (!is_dead){
		pDC->TransparentBlt(x, y, width, height, &memDC, 0, 0, width, height, RGB(255, 255, 255));
	}
}
bool Enemy1::Attack()
{
	int t = rand() % 10;
	if (t == 3) return true;
	else return false;
}