
// MyFinalPaint.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMyFinalPaintApp:
// See MyFinalPaint.cpp for the implementation of this class
//

class CMyFinalPaintApp : public CWinApp
{
public:
	CMyFinalPaintApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMyFinalPaintApp theApp;
