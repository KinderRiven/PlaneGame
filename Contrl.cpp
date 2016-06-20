// Contrl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyGame.h"
#include "Contrl.h"
#include "afxdialogex.h"
#include "GameMessage.h"
#include "Game_Lv.h"


// Contrl �Ի���

IMPLEMENT_DYNAMIC(Contrl, CDialogEx)

Contrl::Contrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(Contrl::IDD, pParent)
{

}

Contrl::~Contrl()
{
}

void Contrl::DoDataExchange(CDataExchange* pDX)
{
	hero_life = 10000; hero_bullet = 5000;
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, Game_Step);
	DDX_Text(pDX, IDC_EDIT2, hero_life);
	DDX_Text(pDX, IDC_EDIT3, hero_bullet);
	DDX_Control(pDX, IDC_COMBO2, Hero_num);
	DDV_MinMaxInt(pDX, hero_life,  1, 20000);
	DDV_MinMaxInt(pDX, hero_bullet, 1, 2000);
}
BEGIN_MESSAGE_MAP(Contrl, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Contrl::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT2, &Contrl::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK, &Contrl::OnBnClickedOk)
	ON_BN_CLICKED(2, &Contrl::OnBnClicked2)
	ON_CBN_SELCHANGE(IDC_COMBO2, &Contrl::OnCbnSelchangeCombo2)
	ON_EN_CHANGE(IDC_EDIT3, &Contrl::OnEnChangeEdit3)
END_MESSAGE_MAP()


// Contrl ��Ϣ�������



void Contrl::OnBnClickedOk()
{
	UpdateData(TRUE);
	game_step = Game_Step.GetCurSel();
	hero_num  = Hero_num.GetCurSel();
	if (game_step == -1 && GameMessage::step == 0)
	{
		MessageBox(_T("��~�㻹ûѡ��ؿ���"), _T("������յĶԻ���"), 0);
		return;
	}
	if (hero_num == -1)
	{
		MessageBox(_T("��~�㻹ûѡ��Ӣ�۵�������"), _T("���Դ�صĶԻ���"), 0);
		return;
	}
	Game_Lv::Start_step = game_step;
	Game_Lv::Hero_Bullet = hero_bullet;
	Game_Lv::Hero_Life = hero_life;
	Game_Lv::Hero_num  = hero_num;
	//UpdateData(FALSE);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}



