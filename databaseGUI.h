// databaseGUI.h : main header file for the DATABASEGUI application
//

#if !defined(AFX_DATABASEGUI_H__DD30CD25_D2D1_413B_ACBB_070F8FC41E9D__INCLUDED_)
#define AFX_DATABASEGUI_H__DD30CD25_D2D1_413B_ACBB_070F8FC41E9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDatabaseGUIApp:
// See databaseGUI.cpp for the implementation of this class
//

class CDatabaseGUIApp : public CWinApp
{
public:
	CDatabaseGUIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDatabaseGUIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDatabaseGUIApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATABASEGUI_H__DD30CD25_D2D1_413B_ACBB_070F8FC41E9D__INCLUDED_)
