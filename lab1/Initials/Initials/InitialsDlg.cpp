
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

	// создаем перо и кисть с использованием классов библиотеки MFC 

	CBrush brushFirst(RGB(0, 255, 0));
	CBrush brushSecond(RGB(255, 0, 0));
	CBrush brushThird(RGB(0, 0, 255));

	// Выбираем их в контекст устройства 
	CBrush* pOldBrush = dc.SelectObject(&brushFirst);
	PaintLetterD(dc, { 50, m_startPointDraw + m_offset });
	
	pOldBrush = dc.SelectObject(&brushSecond);
	PaintLetterA(dc, { 150, m_startPointDraw + m_offset });
	
	pOldBrush = dc.SelectObject(&brushThird);
	PaintLetterA(dc, { 250, m_startPointDraw + m_offset });

	dc.SelectObject(pOldBrush);
}

int CInitialsDlg::OnCreate(LPCREATESTRUCT createdStruct)
{
	m_lastTick = GetTickCount();
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
	dc.Rectangle(100 + point.x, 50 + point.y, 110 + point.x, 100 + point.y);
	dc.Rectangle(110 + point.x, 50 + point.y, 150 + point.x, 60 + point.y);
	dc.Rectangle(150 + point.x, 50 + point.y, 160 + point.x, 100 + point.y);
	dc.Rectangle(90 + point.x, 100 + point.y, 170 + point.x, 110 + point.y);
	dc.Rectangle(90 + point.x, 100 + point.y, 100 + point.x, 140 + point.y);
	dc.Rectangle(160 + point.x, 100 + point.y, 170 + point.x, 140 + point.y);
}

void CInitialsDlg::PaintLetterA(CPaintDC& dc, const Point& point)
{
	dc.Rectangle(100 + point.x, 50 + point.y, 110 + point.x, 160 + point.y);
	dc.Rectangle(110 + point.x, 50 + point.y, 150 + point.x, 60 + point.y);
	dc.Rectangle(150 + point.x, 50 + point.y, 160 + point.x, 160 + point.y);
	dc.Rectangle(100 + point.x, 100 + point.y, 160 + point.x, 110 + point.y);
}

void CInitialsDlg::Animate()
{
	auto currentTick = GetTickCount();
	if (m_offset >= 140 || m_offset <= -140)
	{
		m_lastTick = currentTick;
		m_acceleration *= -1;
		m_speed = 0;
		m_startPointDraw = m_offset < 0 ? 0 : m_offset;
	}
	
	auto delta = (currentTick - m_lastTick) * 0.001;

	m_speed += m_acceleration * delta;
	m_offset = m_speed * delta / 2;


	Invalidate();
	UpdateWindow();
}

