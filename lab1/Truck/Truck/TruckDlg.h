
// TruckDlg.h : header file
//

#pragma once
#include "Point.h"
#include <memory>
#include "TruckDrawing.h"

// CTruckDlg dialog
class CTruckDlg : public CDialogEx
{
// Construction
public:
	CTruckDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRUCK_DIALOG };
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
	std::unique_ptr<TruckDrawing> m_truckDrawing;
};
