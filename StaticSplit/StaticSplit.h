
// StaticSplit.h : main header file for the StaticSplit application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CStaticSplitApp:
// See StaticSplit.cpp for the implementation of this class
//

class CStaticSplitApp : public CWinApp
{
public:
	CStaticSplitApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CStaticSplitApp theApp;
