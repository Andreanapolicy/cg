
// Truck.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTruckApp:
// See Truck.cpp for the implementation of this class
//

class CTruckApp : public CWinApp
{
public:
	CTruckApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTruckApp theApp;
