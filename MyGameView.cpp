
// MyGameView.cpp : CMyGameView ���ʵ��
//
#include "stdafx.h"
#include "BackGround.h"
#include "GameMessage.h"
#include "Windows.h"
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MyGame.h"
#endif

#include "MyGameDoc.h"
#include "MyGameView.h"
#include "time.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMyGameView

IMPLEMENT_DYNCREATE(CMyGameView, CView)

BEGIN_MESSAGE_MAP(CMyGameView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMyGameView ����/����

CMyGameView::CMyGameView()
{
	// TODO:  �ڴ˴���ӹ������

}

CMyGameView::~CMyGameView()
{
}

BOOL CMyGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), NULL);
	return CView::PreCreateWindow(cs);
}

// CMyGameView ����

void CMyGameView::OnDraw(CDC* /*pDC*/)
{
	CMyGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMyGameView ��ӡ

BOOL CMyGameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMyGameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMyGameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMyGameView ���

#ifdef _DEBUG
void CMyGameView::AssertValid() const
{
	CView::AssertValid();
}

void CMyGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyGameDoc* CMyGameView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyGameDoc)));
	return (CMyGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyGameView ��Ϣ�������


void CMyGameView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	GetClientRect(&GameMessage::rect); //��ȡ
	CView::OnTimer(nIDEvent);
	CClientDC DC(this);
	switch (nIDEvent)
	{
	case 0:
		GameMessage::ShowBackground(&MemDC);
		GameMessage::ShowHero(&MemDC);	     //����Ӣ�۵Ļ���(����Ӣ�۷������ӵ�)
		GameMessage::ShowEnemy1(&MemDC);     //����һ�ŵл��Ļ���
		GameMessage::ShowEnemy2(&MemDC);	 //���ж��ŵл��Ļ���
		GameMessage::ShowEnemy3(&MemDC);	 //�������ŵл��Ļ���
		GameMessage::ShowEnemy4(&MemDC);	 //�����ĺŵл��Ļ���
		GameMessage::ShowEnemy5(&MemDC);	 //������ŵл��Ļ���
		GameMessage::ShowEnemyBoss(&MemDC);	 //Boss�Ļ���
		GameMessage::ShowExplo(&MemDC);		 //��ը����
		GameMessage::ShowState(&MemDC);		 //״̬������
		GameMessage::ShowWord(&MemDC);		 //���ֻ���
		GameMessage::ShowEnemyBullet(&MemDC);//�����ӵ�
		GameMessage::ShowHeroLife(&MemDC);	 //��
		GameMessage::ShowThings(&MemDC);	 //��Ʒ
		DC.BitBlt(0, 0, GameMessage::rect.Width(), GameMessage::rect.Height(), &MemDC, 0, 0, SRCCOPY);
		break;
	case 1:
		GameMessage::GameManage();		//��Ϸ���ȹ���
		break;
	case 2:
		GameMessage::GetKeyAttack();		//��ù�����Ϣ
		break;
	case 3:
		GameMessage::EnemyAttack1();		//���й������˵��ж�
		GameMessage::EnemyAttack2();		//���й������˵��ж�
		GameMessage::EnemyAttack3();		//���й������˵��ж�
		GameMessage::EnemyAttack4();
		GameMessage::EnemyAttack5();
		GameMessage::BossAttack();			//BOSS������
		GameMessage::HeroAttack();			//Ӣ�۱�����
		GameMessage::PlaneHit();			//��ײ
		GameMessage::ThingHit();			//��ײ
		break;
	case 4:
		GameMessage::GameToStop();			//��Ϸ��ͣ
		break;
	case 5:
		GameMessage::RandomEnemy(GameMessage::step);
	case 6:
		GameMessage::GameCombine();
		GameMessage::TalkMessage();		//�Ի�����
	}
}
void CMyGameView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	GetClientRect(&GameMessage::rect);
	PlaySound(L"sound.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	srand((unsigned)time);
	SetTimer(0, 50, 0);		 //ÿ���50ms����һ������0
	SetTimer(1, 50, 0);		 //ÿ���50ms����һ������1
	SetTimer(2,120, 0);		 //ÿ���80ms����һ������2
	SetTimer(3, 50, 0);		 //ÿ���50ms����һ������3
	SetTimer(4, 120, 0);	 //ÿ���50ms����һ������4
	SetTimer(5, 2000, 0);	 //ÿ���50ms����һ������5
	SetTimer(6, 300, 0);	 //ÿ���50ms����һ������5
	// TODO:  �ڴ����ר�ô����/����û���
	if (MemDC.m_hDC == NULL)
	{
		MemDC.CreateCompatibleDC(NULL);
		CClientDC DC(this);
		CRect rect;
		this->GetClientRect(&rect);
		MemBitmap.CreateCompatibleBitmap(&DC, rect.Width() * 5, rect.Height() * 5);
		MemDC.SelectObject(&MemBitmap);
	}
}