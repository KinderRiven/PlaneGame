#pragma once
#include "GameNature.h"
#include "Resource.h"
class Bullet:
	public GameNature
{
public:
	Bullet(int v,int x,int y);
	Bullet(int v, int x, int y, int dx, int dy);
	//�����ӵ���������г�ʼ�������Ҽ������ĳ�ʼ����
	bool is_break();
	void draw(CDC* pDC);
	void change(int sp,int dx,int dy); //�ı��ӵ��ķ�����ٶ�
	//�ж��ӵ��Ƿ�ɳ����⣬����ɳ���ɾ��
	~Bullet();
};