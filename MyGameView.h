
// MyGameView.h : CMyGameView ��Ľӿ�
//

#pragma once


class CMyGameView : public CView
{
protected: // �������л�����
	CMyGameView();
	DECLARE_DYNCREATE(CMyGameView)

// ����
public:
	CMyGameDoc* GetDocument() const;
	CDC MemDC; //���ȶ���һ����ʾ�豸����
	CRect m_client; //��ȡDC
	CBitmap MemBitmap; //λͼ����


// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMyGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
	//virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // MyGameView.cpp �еĵ��԰汾
inline CMyGameDoc* CMyGameView::GetDocument() const
   { return reinterpret_cast<CMyGameDoc*>(m_pDocument); }
#endif

