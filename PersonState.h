#pragma once
#include "GameNature.h"
//#include "Hero.h"
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
//protected:
//	CBitmap bmp;		//ͼƬ
//	int width, height;	//ģ�͵Ĵ�С
//	int x, y;			//λ������
//	int speed;			//�ٶ�
//	int dir_x, dir_y;	//��������
//	int hurt;			//ÿ����Ʒ���˺���������ײ�˺����ӵ��˺�����Ʒ�˺�
//	bool is_dead;		//�ж��Ƿ�����
//Hero(int num);
//~Hero();
//bool Get_Dir();
//void Hero_Move();	//����ƶ�����
//bool Get_Attack();  //Ӣ�۹���
//void draw_buttle(CDC* cDC); //���ӵ�
//int  Get_Hit();		//��ȡ������Ϣ
//CObList bullet_list;//�ӵ�����
//int Lv;				//�ж�Ӣ�۵ĵȼ������ݵȼ��ж��ӵ�������
//int score;			//Ӣ�������еķ���
//int bound_num;		//���еĸ���
//int bullet_num;		//�ر��ӵ��ĸ���
class PersonState:
	public GameNature
{
public:
	PersonState(int num = 1);
	~PersonState();
	void draw(CDC* cDC);
	CBitmap score_bmp;
	int player;
};

