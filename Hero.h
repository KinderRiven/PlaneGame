#pragma once
#include "Plane.h"
//��ҿ��Ƶķɻ�����
//����Ӣ�۵Ļ�������
class Hero:
	public Plane
{
public:
	Hero(int num, int Player, int cscore = 0);
	~Hero();
	void draw(CDC* pDC);
	bool Get_Dir();
	void Hero_Move();	//����ƶ�����
	bool Get_Attack();  //Ӣ�۹���
	void draw_buttle(CDC* cDC); //���ӵ�
	int  Get_Hit();		//��ȡ������Ϣ
	CObList bullet_list;//�ӵ�����
	int Lv;				//�ж�Ӣ�۵ĵȼ������ݵȼ��ж��ӵ�������
	int B_Lv;
	int score;			//Ӣ�������еķ���
	int bound_num;		//���еĸ���
	int bullet_num;		//�ر��ӵ��ĸ���
	int player;
private:
	int vk_up, vk_down, vk_left, vk_right;//�ɻ��ƶ����ϡ��¡�����
	int vk_a, vk_b, vk_c,vk_d; //�ɻ����ӵ����ر��ӵ��ʹ���
};

