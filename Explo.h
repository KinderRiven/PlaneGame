#pragma once
#include "GameNature.h"
class Explo:
	public GameNature
{
public:
	Explo(int num,int xx,int yy); //��λ��xx,yy�����б�ը
	void loadimage();    //����ͼƬ
	void draw(CDC* cDC); //��ͼ
	bool is_end();	//��ը����
	~Explo();
	int index;  //Ŀǰ��λ��
	int num;	//ͼ������
	int length; //����ͼƬ����
	CImageList imagelist;
};