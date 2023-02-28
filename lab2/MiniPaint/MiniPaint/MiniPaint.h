
// MiniPaint.h : main header file for the MiniPaint application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMiniPaintApp:
// See MiniPaint.cpp for the implementation of this class
//

class CMiniPaintApp : public CWinApp
{
public:
	CMiniPaintApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMiniPaintApp theApp;
