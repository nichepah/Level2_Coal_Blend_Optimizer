
// Coal_Blending_View.h : main header file for the Coal_Blending_View application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCoal_Blending_ViewApp:
// See Coal_Blending_View.cpp for the implementation of this class
//

class CCoal_Blending_ViewApp : public CWinAppEx
{
public:
	CCoal_Blending_ViewApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCoal_Blending_ViewApp theApp;
