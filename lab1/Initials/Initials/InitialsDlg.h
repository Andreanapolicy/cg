
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

	struct LetterDynamicInfo
	{
		double acceleration = 0;
		double speed = 0;
		int offset = 0;
		int start = 0;
		DWORD lastTick = 0;
	};

	void PaintLetterD(CPaintDC& dc, const Point& point);
	void PaintLetterA(CPaintDC& dc, const Point& point);
	void Animate();
	void CalculateOffset(LetterDynamicInfo& letterDynamicInfo);

	LetterDynamicInfo m_firstInfo = {1};
	LetterDynamicInfo m_secondInfo = {2};
	LetterDynamicInfo m_thirdInfo = {3};
};
