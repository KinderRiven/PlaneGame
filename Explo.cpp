#include "stdafx.h"
#include "Explo.h"
#include "resource.h"
//Explo(int num, int xx, int yy); //��λ��xx,yy�����б�ը
//void loadimage();    //����ͼƬ
//void draw(); //��ͼ
//~Explo();
//int num;	//ͼ������
//int length; //����ͼƬ����
//CBitmap bmp;		//ͼƬ
//int width, height;	//ģ�͵Ĵ�С
//int x, y;			//λ������
//int speed;			//�ٶ�
//int dir_x, dir_y;	//��������
//int hurt;			//ÿ����Ʒ���˺���������ײ�˺����ӵ��˺�����Ʒ�˺�
//bool is_dead;		//�ж��Ƿ�����
Explo::Explo(int n, int xx, int yy)
{
	//�жϱ�ըλ�ú�����
	x = xx;	y = yy; index = 0;
	if (n == 1)  //С��ը
	{
		bmp.LoadBitmap(5001);
		length = 33;
		num = 8;

	}
	else if (n == 2)
	{
		bmp.LoadBitmap(5002);
		length = 66;
		num = 8;
	}
	else if (n == 3)
	{
		bmp.LoadBitmap(5003);
		length = 66 * 4;
		num = 8;
	}
	loadimage();
}

Explo::~Explo()
{
}
//����
void Explo::loadimage()
{
	//���ر�ըͼ��
	if (!imagelist.Create(length, length, ILC_COLOR24 | ILC_MASK, 8, 0))
		return;
	imagelist.Add(&bmp, RGB(0, 0, 0));
}
//��
void Explo::draw(CDC* cDC)
{
	imagelist.Draw(cDC, index, CPoint(x, y), ILD_TRANSPARENT);
	index++;
	is_end();
}
bool Explo::is_end()
{
	if (index > num)
		goto_die();
	return return_dead();
}