#include "stdafx.h"
#include "GameWord.h"
#include "GameMessage.h"
//Format(_T"Hello,world! %d",n);
GameWord::GameWord(CString w,int s,int e,int xx,int yy) //����
{
	word = w;
	start = s;end = e;
	x = xx;	  y = yy;
}
void GameWord::draw(CDC* cDC)
{
	cDC->SetBkMode(TRANSPARENT);//͸������
	cDC->SetTextColor(RGB(0, 0, 0));
	cDC->TextOut(x, y, word);
	start++;			//������ʾ�������ж�ʱ��
}
GameWord::~GameWord()
{

}
