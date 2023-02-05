
// InitialsDlg.h : header file
//

#pragma once

#include "Point.h"

// CInitialsDlg dialog
class CInitialsDlg : public CDialogEx
{
// Construction
public:
	CInitialsDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INITIALS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	void PaintLetterD(CPaintDC& dc, const Point& point);
	void PaintLetterA(CPaintDC& dc, const Point& point);
};
