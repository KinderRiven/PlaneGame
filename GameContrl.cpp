// GameContrl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyGame.h"
#include "GameContrl.h"
#include "afxdialogex.h"
#include "Game_Lv.h"
#include "GameMessage.h"
#include "AboutMe.h"
#include "Help.h"
#include "GameSetting.h"


// GameContrl �Ի���

IMPLEMENT_DYNAMIC(GameContrl, CDialogEx)

GameContrl::GameContrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(GameContrl::IDD, pParent)
{

}

GameContrl::~GameContrl()
{
	GameMessage::_OK = 1;
}

void GameContrl::DoDataExchange(CDataExchange* pDX)
{
	l = 50000, d = 1000;
	DDX_Control(pDX, IDC_COMBO1, Mystep);
	DDX_Control(pDX, IDC_COMBO2, Mynum);
	DDX_Control(pDX, IDC_COMBO4, Myhero);
	DDX_Text(pDX, IDC_EDIT2, l);
	DDX_Text(pDX, IDC_EDIT3, d);
	DDV_MinMaxInt(pDX, l, 1, 100000);
	DDV_MinMaxInt(pDX, d, 0, 2000);
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(GameContrl, CDialogEx)
	ON_BN_CLICKED(IDOK, &GameContrl::OnBnClickedOk)
	ON_BN_CLICKED(IDOK2, &GameContrl::OnBnClickedOk2)
	ON_BN_CLICKED(IDC_BUTTON1, &GameContrl::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &GameContrl::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_COMBO2, &GameContrl::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON3, &GameContrl::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT2, &GameContrl::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON4, &GameContrl::OnBnClickedButton4)
END_MESSAGE_MAP()


// GameContrl ��Ϣ�������


void GameContrl::OnBnClickedOk()
{
	UpdateData(TRUE);
	int n = Mystep.GetCurSel() + 1;
	int m = Mynum.GetCurSel() + 1;
	int t = Myhero.GetCurSel() + 1;
	if (n == 0 || m == 0 || t == 0)
	{
		MessageBox(_T("��~��ѡ�����б�ѡ��!"), _T("������յ���ʾ"), 0);
		return;
	}
	if (l < 1 || l > 100000 || d < 0 || d > 2000) return;
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	Game_Lv::Hero_Life = l;
	Game_Lv::Hero_Bullet = d;
	Game_Lv::Start_step = n;
	Game_Lv::Hero_num = m;
	if (t == 2)
		Game_Lv::Hero2_num = Game_Lv::Hero_num;
	else
		Game_Lv::Hero2_num = 0;
	CDialogEx::OnOK();
}


void GameContrl::OnBnClickedOk2()
{
	Game_Lv::Start_step = 0;
	Game_Lv::Hero_num = 0;
	CDialogEx::OnOK();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

BOOL GameContrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GameMessage::_OK = 0;
	((CEdit*)GetDlgItem(IDC_EDIT2))->SetLimitText(6);
	((CEdit*)GetDlgItem(IDC_EDIT3))->SetLimitText(4);
	UpdateData(TRUE);
	return TRUE;
}

void GameContrl::OnBnClickedButton1()
{
	AboutMe writer;
	writer.DoModal();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
void GameContrl::OnBnClickedButton2()
{
	MessageBox(_T("�ѳɹ������������", _T("��ã�~"),0));
	GameMessage::Hero_Kind = 2;
	GameMessage::Hero2_Kind = 4;
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
void GameContrl::OnCbnSelchangeCombo2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void GameContrl::OnBnClickedButton3()
{
	Help help;
	help.DoModal();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void GameContrl::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void GameContrl::OnBnClickedButton4()
{
	GameSetting Set;
	Set.DoModal();
}
