
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
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT createdStruct);
	afx_msg void OnTimer(UINT_PTR ptr);
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	enum
	{
		ANIMATION_TIMER_ID = 1
	}; 

	void PaintLetterD(CPaintDC& dc, const Point& point);
	void PaintLetterA(CPaintDC& dc, const Point& point);
	void Animate();

	DWORD m_lastTick;
	int m_speed = 0;
	int m_offset = 0;
	int m_startPointDraw = 0;
	double m_acceleration = 0.5;
};
