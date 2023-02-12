
// ImageReader.h : main header file for the ImageReader application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CImageReaderApp:
// See ImageReader.cpp for the implementation of this class
//

class CImageReaderApp : public CWinApp
{
public:
	CImageReaderApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	afx_msg void OnFileOpen();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CImageReaderApp theApp;
