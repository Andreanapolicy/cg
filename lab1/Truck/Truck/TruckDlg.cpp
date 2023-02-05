
// TruckDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Truck.h"
#include "TruckDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTruckDlg dialog

CTruckDlg::CTruckDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TRUCK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_truckDrawing = std::make_unique<TruckDrawing>();
}

void CTruckDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTruckDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CTruckDlg message handlers

BOOL CTruckDlg::OnInitDialog()
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

void CTruckDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	m_truckDrawing->Draw(dc, {});
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTruckDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}