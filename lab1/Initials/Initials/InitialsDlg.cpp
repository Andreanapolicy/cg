
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

	CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
	CBrush brush(RGB(255, 255, 0));

	// Выбираем их в контекст устройства 
	CPen* pOldPen = dc.SelectObject(&pen);
	CBrush* pOldBrush = dc.SelectObject(&brush);

	PaintLetterD(dc, { 50, 50 + m_speed });
	PaintLetterA(dc, { 150, 50 + m_speed });
	PaintLetterA(dc, { 250, 50 + m_speed });

	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);
}

int CInitialsDlg::OnCreate(LPCREATESTRUCT createdStruct)
{
	m_lastTick = GetTickCount();
	SetTimer(ANIMATION_TIMER_ID, 20, NULL);
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
	m_speed += m_acceleration;

	Invalidate();
	UpdateWindow();
}

