#pragma once


// AboutMe �Ի���

class AboutMe : public CDialogEx
{
	DECLARE_DYNAMIC(AboutMe)

public:
	AboutMe(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AboutMe();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
