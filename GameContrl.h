#pragma once


// GameContrl �Ի���

class GameContrl : public CDialogEx
{
	DECLARE_DYNAMIC(GameContrl)

public:
	int l, d;
	CComboBox Mystep;
	CComboBox Mynum;
	CComboBox Myhero;
	GameContrl(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~GameContrl();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedOk2();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton4();
};
