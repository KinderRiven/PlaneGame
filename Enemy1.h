#pragma once
#include "GameNature.h"
class Enemy1:
	public GameNature
{
public:
	Enemy1();
	~Enemy1();
	void move();
	void Change_Dir();
	void draw(CDC* cDC);
	bool Attack(); //�����ӵ�
	int life;
	int score;
};

