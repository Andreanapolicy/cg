
// InitialsDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Initials.h"
#include "InitialsDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CInitialsDlg::CInitialsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INITIALS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CInitialsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CInitialsDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CInitialsDlg message handlers

BOOL CInitialsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CInitialsDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting 

	// ������� ���� � ����� � �������������� ������� ���������� MFC 

	CBrush brushFirst(RGB(0, 255, 0));
	CBrush brushSecond(RGB(255, 0, 0));
	CBrush brushThird(RGB(0, 0, 255));

	// �������� �� � �������� ���������� 
	CBrush* pOldBrush = dc.SelectObject(&brushFirst);
	CalculateOffset(m_firstInfo);
	PaintLetterD(dc, { 50, m_firstInfo.start + m_firstInfo.offset });
	
	pOldBrush = dc.SelectObject(&brushSecond);
	CalculateOffset(m_secondInfo);
	PaintLetterA(dc, { 150, m_secondInfo.start + m_secondInfo.offset });
	
	pOldBrush = dc.SelectObject(&brushThird);
	CalculateOffset(m_thirdInfo);
	PaintLetterA(dc, { 250, m_thirdInfo.start + m_thirdInfo.offset });
	
	dc.SelectObject(pOldBrush);
}

int CInitialsDlg::OnCreate(LPCREATESTRUCT createdStruct)
{
	auto lastTick = GetTickCount();
	m_firstInfo.lastTick = lastTick;
	m_secondInfo.lastTick = lastTick;
	m_thirdInfo.lastTick = lastTick;
	
	SetTimer(ANIMATION_TIMER_ID, 1, NULL);
	return 0;
}

void CInitialsDlg::OnDestroy()
{
	KillTimer(ANIMATION_TIMER_ID);
}

void CInitialsDlg::OnTimer(UINT_PTR ptr)
{
	switch(ptr)
	{
	case ANIMATION_TIMER_ID:
		Animate();
		break;
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CInitialsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CInitialsDlg::PaintLetterD(CPaintDC& dc, const Point& point)
{
	dc.Rectangle(100 + point.x, 10 + point.y, 110 + point.x, 60 + point.y);
	dc.Rectangle(110 + point.x, 10 + point.y, 150 + point.x, 20 + point.y);
	dc.Rectangle(150 + point.x, 10 + point.y, 160 + point.x, 60 + point.y);
	dc.Rectangle(90 + point.x, 60 + point.y, 170 + point.x, 70 + point.y);
	dc.Rectangle(90 + point.x, 60 + point.y, 100 + point.x, 100 + point.y);
	dc.Rectangle(160 + point.x, 60 + point.y, 170 + point.x, 100 + point.y);
}

void CInitialsDlg::PaintLetterA(CPaintDC& dc, const Point& point)
{
	dc.Rectangle(100 + point.x, 10 + point.y, 110 + point.x, 120 + point.y);
	dc.Rectangle(110 + point.x, 10 + point.y, 150 + point.x, 20 + point.y);
	dc.Rectangle(150 + point.x, 10 + point.y, 160 + point.x, 120 + point.y);
	dc.Rectangle(100 + point.x, 60 + point.y, 160 + point.x, 70 + point.y);
}

void CInitialsDlg::Animate()
{
	Invalidate();
	UpdateWindow();
}

void CInitialsDlg::CalculateOffset(LetterDynamicInfo& letterDynamicInfo)
{
	const auto borderOffset = 140;

	auto currentTick = GetTickCount();
	if (letterDynamicInfo.offset >= borderOffset || letterDynamicInfo.offset <= -borderOffset)
	{
		letterDynamicInfo.lastTick = currentTick;
		letterDynamicInfo.acceleration *= -1;
		letterDynamicInfo.speed = 0;
		letterDynamicInfo.start = letterDynamicInfo.offset < 0 ? 0 : letterDynamicInfo.offset;
	}

	auto delta = (currentTick - letterDynamicInfo.lastTick) * 0.001;

	letterDynamicInfo.speed += letterDynamicInfo.acceleration * delta;
	letterDynamicInfo.offset = letterDynamicInfo.speed * delta / 2;
}

