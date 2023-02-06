
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
	CPaintDC dc(this); // device context for painting

	DrawCircle(dc, 100, 100, 50);
}

HCURSOR CCircleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCircleDlg::DrawCircle(CPaintDC& dc, int centerX, int centerY, int radius)
{
	for (auto index = radius; index > 0; index -= 1)
	{
		int x1, y1, yk = 0;
		int sigma, delta, f;
		delta = 2 * (1 - index);
		y1 = index;
		x1 = 0;

		do
		{
			dc.SetPixel(centerX + x1, centerY + y1, RGB(150, 150, 150));
			dc.SetPixel(centerX - x1, centerY + y1, RGB(2, 3, 4));
			dc.SetPixel(centerX + x1, centerY - y1, RGB(2, 3, 4));
			dc.SetPixel(centerX - x1, centerY - y1, RGB(2, 3, 4));

			f = 0;
			if (y1 < yk)
			{
				break;
			}
			if (delta < 0)
			{
				sigma = 2 * (delta + y1) - 1;

				if (sigma <= 0)
				{
					x1++;
					delta += 2 * x1 + 1;
					f = 1;
				}
			}
			else if (delta > 0)
			{
				sigma = 2 * (delta - x1) - 1;
				if (sigma > 0)
				{
					y1--;
					delta += 1 - 2 * y1;
					f = 1;
				}
			}
			if (!f)
			{
				x1++;
				y1--;
				delta += 2 * (x1 - y1 - 1);
			}

		} while (1);
	}
}