
// CircleDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Circle.h"
#include "CircleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CCircleDlg::CCircleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CIRCLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_circle = std::make_unique<CircleView>();
}

void CCircleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCircleDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CCircleDlg message handlers

BOOL CCircleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCircleDlg::OnPaint()
{
	CPaintDC dc(this);

	m_circle->Draw(dc, 100, 100, 50, RGB(30, 50, 200), RGB(200, 150, 60));
}

HCURSOR CCircleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}