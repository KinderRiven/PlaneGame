#pragma once


// Help �Ի���

class Help : public CDialogEx
{
	DECLARE_DYNAMIC(Help)

public:
	Help(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Help();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
