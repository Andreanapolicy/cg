
// ImageReader.h : main header file for the ImageReader application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"

// CImageReaderApp:
// See ImageReader.cpp for the implementation of this class
//

class CImageReaderApp : public CWinApp
{
public:
	CImageReaderApp() noexcept;

public:
	virtual BOOL InitInstance();
	afx_msg void OnFileOpen();

	UINT m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
private:
	CSingleDocTemplate* m_pDocTemplate;
};

extern CImageReaderApp theApp;
