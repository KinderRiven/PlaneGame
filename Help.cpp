// Help.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyGame.h"
#include "Help.h"
#include "afxdialogex.h"


// Help �Ի���

IMPLEMENT_DYNAMIC(Help, CDialogEx)

Help::Help(CWnd* pParent /*=NULL*/)
	: CDialogEx(Help::IDD, pParent)
{

}

Help::~Help()
{
}

void Help::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Help, CDialogEx)
END_MESSAGE_MAP()


// Help ��Ϣ�������
