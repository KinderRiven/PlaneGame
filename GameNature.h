#pragma once
//����������Ʒ�����Ը�����
//�ٶ� λ�� ���� �Ƿ���� ͼƬ
class GameNature:
	public CObject
{
public:
	GameNature();
	~GameNature();
	virtual void draw(CDC* pDC);//��ͼ����
	virtual void move();
	void UpDatePos();
	bool return_dead();
	int  return_width();
	int  return_height();
	int  return_x();
	int  return_y();
	int  return_hurt();
	void goto_die();
	int speed;			//�ٶ�.
	bool is_dead;		//�ж��Ƿ�����
protected:
	CBitmap bmp;		//ͼƬ
	int width, height;	//ģ�͵Ĵ�С
	int x,y;			//λ������
	int dir_x, dir_y;	//��������
	int hurt;			//ÿ����Ʒ���˺���������ײ�˺����ӵ��˺�����Ʒ�˺�
};

	