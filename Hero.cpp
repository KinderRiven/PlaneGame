#include "stdafx.h"
#include "Hero.h"
#include "resource.h"
#include "GameMessage.h"
#include "Bullet.h"
#include "Game_Lv.h"
#include "AllSpeed.h"
#include "AllHurt.h"
//��ʼ��
Hero::Hero(int num,int p,int cscore)
{
	player = p;		//�ĸ�Ӣ��
	if (player == 1){ //һ����ҿ��Ƶ�Ӣ��
		if (num == 1)
		{
			B_Lv = 1;
			Lv = 1;				//Ӣ�۳�ʼ�ĵȼ�Ϊ1
			speed = AllSpeed::speed_h1;			 //�趨��ʼ���ٶ�
			life = Game_Lv::Hero_Life;		 //�趨��ʼ������
			bmp.LoadBitmap(num + 2000); //����ɻ�����
			bound_num = 3;		 //��ʼը��
			bullet_num = Game_Lv::Hero_Bullet;//�����ӵ�
		}
		else if (num == 2){
			B_Lv = 3;
			Lv = 2;				//Ӣ�۳�ʼ�ĵȼ�Ϊ1
			speed = AllSpeed::speed_h2;			 //�趨��ʼ���ٶ�
			life = 500000;		 //�趨��ʼ������
			bound_num = 1000;		 //��ʼը��
			bullet_num = 10000;//�����ӵ�
			bmp.LoadBitmap(num + 2000); //����ɻ�����
		}
		else if (num == 3)
		{
			B_Lv = 1;
			Lv = 3;				//Ӣ�۳�ʼ�ĵȼ�Ϊ1
			speed = AllSpeed::speed_h1;			 //�趨��ʼ���ٶ�
			life = Game_Lv::Hero_Life;		 //�趨��ʼ������
			bmp.LoadBitmap(num + 2000); //����ɻ�����
			bound_num = 3;		 //��ʼը��
			bullet_num = Game_Lv::Hero_Bullet;//�����ӵ�
		}
		else if (num == 4)
		{
			B_Lv = 3;
			Lv = 4;				 //Ӣ�۳�ʼ�ĵȼ�Ϊ1
			speed = AllSpeed::speed_h2;//�趨��ʼ���ٶ�
			life = 500000;		 //�趨��ʼ������
			bound_num = 1000;	 //��ʼը��
			bullet_num = 10000;  //�����ӵ�
			bmp.LoadBitmap(num + 2000); //����ɻ�����
		}
		hurt = AllHurt::hurt_hero;
		is_dead = false;
		x = 500; y = 500;	 //��ʼ��Ӣ�۵�λ��
		dir_x = 0; dir_y = 0;//��ʼ������
		score = cscore;		 //�趨��ʼ�ĵĵ÷�Ϊ0
		width = 124;		 //�ɻ����
		height = 97;		 //�ɻ��߶�
		vk_up    = 'W';		 //������ַ�����Լ�����
		vk_down  = 'S';		vk_a = 'J';  vk_d = 'P';
		vk_left  = 'A';		vk_b = 'K';
		vk_right = 'D';		vk_c = 'L';
	}
	if (player == 2){ //2����ҿ��Ƶ�Ӣ��
		if (num == 1){
			B_Lv = 1;
			Lv = 1;				//Ӣ�۳�ʼ�ĵȼ�Ϊ1
			speed = AllSpeed::speed_h1;			 //�趨��ʼ���ٶ�
			life = Game_Lv::Hero_Life;		 //�趨��ʼ������
			bound_num = 3;					 //��ʼը��
			bullet_num = Game_Lv::Hero_Bullet;//�����ӵ�
			bmp.LoadBitmap(num + 2000); //����ɻ�����
		}
		else if (num == 2){
			B_Lv = 3;
			Lv = 2;				//Ӣ�۳�ʼ�ĵȼ�Ϊ1
			speed = AllSpeed::speed_h2;			 //�趨��ʼ���ٶ�
			life = 500000;		 //�趨��ʼ������
			bound_num = 1000;		 //��ʼը��
			bullet_num = 10000;//�����ӵ�
			bmp.LoadBitmap(num + 2000); //����ɻ�����
		}
		else if (num == 3)
		{
			B_Lv = 1;
			Lv = 3;				//Ӣ�۳�ʼ�ĵȼ�Ϊ1
			speed = AllSpeed::speed_h1;			 //�趨��ʼ���ٶ�
			life = Game_Lv::Hero_Life;		 //�趨��ʼ������
			bound_num = 3;					 //��ʼը��
			bullet_num = Game_Lv::Hero_Bullet;//�����ӵ�
			bmp.LoadBitmap(num + 2000); //����ɻ�����
		}
		else if (num == 4)
		{
			B_Lv = 3;
			Lv = 4;				//Ӣ�۳�ʼ�ĵȼ�Ϊ1
			speed = AllSpeed::speed_h2;			 //�趨��ʼ���ٶ�
			life = 500000;		 //�趨��ʼ������
			bound_num = 1000;	  //��ʼը��
			bullet_num = 10000;  //�����ӵ�
			bmp.LoadBitmap(num + 2000); //����ɻ�����
		}
		score = cscore;		 //�趨��ʼ�ĵĵ÷�Ϊ0
		hurt = AllHurt::hurt_hero;
		width = 124; height = 97;
		is_dead = false;
		x = 1000; y = 500;	 //��ʼ��Ӣ�۵�λ��
		dir_x = 0; dir_y = 0;//��ʼ������
		vk_up    = VK_UP;		 //������ַ�����Լ�����
		vk_down  = VK_DOWN;
		vk_left  = VK_LEFT;	
		vk_right = VK_RIGHT;
		vk_a = VK_NUMPAD1;
		vk_b = VK_NUMPAD2;
		vk_c = VK_NUMPAD3;
		vk_d = VK_NUMPAD4;
	}
}
//��������
Hero::~Hero()
{
}
bool Hero::Get_Dir() //�����ƶ����ж�
{
	if (player == 1)
	{ //���1���ƶ�
		if (is_dead) return false;
		if (GetKeyState(vk_up) & 0x8000){
			dir_y = -1; dir_x = 0;
			if (GetKeyState(vk_left) & 0x8000){
				dir_x = -1;
			}
			if (GetKeyState(vk_right) & 0x8000){
				dir_x = 1;
			}
		}
		else if (GetKeyState(vk_down) & 0x8000){
			dir_y = 1; dir_x = 0;
			if (GetKeyState(vk_left) & 0x8000){
				dir_x = -1;
			}
			if (GetKeyState(vk_right) & 0x8000){
				dir_x = 1;
			}
		}
		else if (GetKeyState(vk_left) & 0x8000){
			dir_x = -1;  dir_y = 0;
			if (GetKeyState(vk_up) & 0x8000){
				dir_y = -1;
			}
			if (GetKeyState(vk_down) & 0x8000){
				dir_y = 1;
			}
		}
		else if (GetKeyState(vk_right) & 0x8000){
			dir_x = 1;  dir_y = 0;
			if (GetKeyState(vk_up) & 0x8000){
				dir_y = -1;
			}
			if (GetKeyState(vk_down) & 0x8000){
				dir_y = 1;
			}
		}
		else {
			dir_x = 0;
			dir_y = 0;
			return false;
		}
	}
	if (player == 2)
	{ //���1���ƶ�
		if (is_dead) return false;
		if (GetKeyState(vk_up) & 0x8000){
			dir_y = -1; dir_x = 0;
			if (GetKeyState(vk_left) & 0x8000){
				dir_x = -1;
			}
			if (GetKeyState(vk_right) & 0x8000){
				dir_x = 1;
			}
		}
		else if (GetKeyState(vk_down) & 0x8000){
			dir_y = 1; dir_x = 0;
			if (GetKeyState(vk_left) & 0x8000){
				dir_x = -1;
			}
			if (GetKeyState(vk_right) & 0x8000){
				dir_x = 1;
			}
		}
		else if (GetKeyState(vk_left) & 0x8000){
			dir_x = -1;  dir_y = 0;
			if (GetKeyState(vk_up) & 0x8000){
				dir_y = -1;
			}
			if (GetKeyState(vk_down) & 0x8000){
				dir_y = 1;
			}
		}
		else if (GetKeyState(vk_right) & 0x8000){
			dir_x = 1;  dir_y = 0;
			if (GetKeyState(vk_up) & 0x8000){
				dir_y = -1;
			}
			if (GetKeyState(vk_down) & 0x8000){
				dir_y = 1;
			}
		}
		else {
			dir_x = 0;
			dir_y = 0;
			return false;
		}
	}
	return true;
}

int Hero::Get_Hit()
{
	if (is_dead) return 0;
	if (GetKeyState(vk_a) & 0x8000) return 1; //��ͨ����
	if (GetKeyState(vk_b) & 0x8000) return 2; //���⹥��
	if (GetKeyState(vk_c) & 0x8000) return 3; //����
	if (GetKeyState(vk_d) & 0x8000) return 4; //����
	return 0;
}
bool Hero::Get_Attack()
{
	if (is_dead) return false;
	switch (Get_Hit()){
	case 1:
		if (B_Lv == 1)
			bullet_list.AddTail(new Bullet(1, x + width / 2 - 16, y + height / 2 - 30,0,-1)); //�����ӵ���������ӵ�������ȥ
		else if (B_Lv == 2)
		{
			bullet_list.AddTail(new Bullet(1, x + width / 2 - 16, y + height / 2 - 30, 0, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(1, x - 40, y + height / 2 - 30,0,-1)); //�����ӵ���������ӵ�������ȥ
		}
		else if (B_Lv >= 3)
		{
			bullet_list.AddTail(new Bullet(1, x + width / 2 - 16, y + height / 2 - 30, 0, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(1, x - 40, y + height / 2 - 30, 0, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(1, x + 124 + 25, y + height / 2 - 30, 0, -1));
		}
		break;
	case 2:
		if (bullet_num - 3 < 0) break;
		bullet_num -=3;
		if (B_Lv == 1){
			bullet_list.AddTail(new Bullet(4, x + width / 2 - 16, y + height / 2 - 15, 0, -1)); //�����ӵ���������ӵ�������ȥ
		}
		else if (B_Lv == 2)
		{
			bullet_list.AddTail(new Bullet(4, x + width / 2 - 16, y + height / 2 - 15, 0, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(4, x + width / 2 - 16, y + height / 2 - 15, 1, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(4, x + width / 2 - 16, y + height / 2 - 15, -1, -1)); //�����ӵ���������ӵ�������ȥ
		}
		if (B_Lv >= 3)
		{
			bullet_list.AddTail(new Bullet(4, x + width / 2 - 16, y + height / 2 - 15, 0, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(4, x + width / 2 - 16, y + height / 2 - 15, 1, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(4, x + width / 2 - 16, y + height / 2 - 15, -1, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(4, x + width / 2 - 16, y + height / 2 - 15, 0, 1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(4, x + width / 2 - 16, y + height / 2 - 15, 1, 1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(4, x + width / 2 - 16, y + height / 2 - 15, -1, 1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(4, x + width / 2 - 16, y + height / 2 - 15, -1, 0)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(4, x + width / 2 - 16, y + height / 2 - 15, 1, 0)); //�����ӵ���������ӵ�������ȥ
		}
		break;
	case 3:
		if (bullet_num - 6 < 0) break;
		bullet_num -= 6;
		if (B_Lv == 1){
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, 0, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, 1, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, -1, -1)); //�����ӵ���������ӵ�������ȥ
		}
		else if (B_Lv == 2)
		{
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, 0, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, 1, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, -1, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, 0, 1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, 1, 1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, -1, 1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, -1, 0)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, 1, 0)); //�����ӵ���������ӵ�������ȥ
		}
		if (B_Lv >= 3)
		{
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, 0, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x, y, 0, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x + width - 20, y + height, 0, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, 1, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, -1, -1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, 0, 1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, 1, 1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, -1, 1)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, -1, 0)); //�����ӵ���������ӵ�������ȥ
			bullet_list.AddTail(new Bullet(6, x + width / 2 - 16, y + height / 2 - 15, 1, 0)); //�����ӵ���������ӵ�������ȥ
		}
		break;
	case 4:
		if (bound_num <= 0) break;
		bound_num--;
		int w = GameMessage::rect.Width(), h = GameMessage::rect.Height();
		for (int i = 0; i < w; i += 100)
		{
			int j = rand() % 300;
			bullet_list.AddTail(new Bullet(8, i, h + j, 0, -1));
		}
	}
	return true;
}
//�ɻ��ӵ��Ļ��ƺ���
void Hero::draw_buttle(CDC* cDC)
{
	if (bullet_list.IsEmpty())  return;
	POSITION post;
	//����ı���
	for (POSITION pos = bullet_list.GetHeadPosition(); (post = pos) != NULL;)
	{
		Bullet* temp = (Bullet*)bullet_list.GetNext(pos);
		if (temp->return_dead()) continue; //����ӵ�Խ��Ͳ����л���
		temp->move();					   //�ƶ��ӵ�
		temp->draw(cDC);				   //�����ӵ�
		temp->is_break();
		if (temp->return_dead())		   //����ӵ�Խ��
		{
			bullet_list.RemoveAt(post);
			delete temp;
		}
	}
}

void Hero::draw(CDC *pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(NULL);
	memDC.SelectObject(&bmp);
	if (!is_dead)
	{
		UpDatePos();
		pDC->TransparentBlt(x, y, width, height, &memDC, 0, 0, width, height, RGB(238, 243, 250));
	}
}