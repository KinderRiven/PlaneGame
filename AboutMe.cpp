// AboutMe.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyGame.h"
#include "AboutMe.h"
#include "afxdialogex.h"


// AboutMe �Ի���

IMPLEMENT_DYNAMIC(AboutMe, CDialogEx)

AboutMe::AboutMe(CWnd* pParent /*=NULL*/)
	: CDialogEx(AboutMe::IDD, pParent)
{

}

AboutMe::~AboutMe()
{
}

void AboutMe::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AboutMe, CDialogEx)
END_MESSAGE_MAP()


// AboutMe ��Ϣ�������
