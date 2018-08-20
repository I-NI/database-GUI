#if !defined(AFX_SHUJUNEW_H__A2D04A90_2990_4171_BEFA_C3BC0CE66FB9__INCLUDED_)
#define AFX_SHUJUNEW_H__A2D04A90_2990_4171_BEFA_C3BC0CE66FB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SHUJUNew.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSHUJUNew dialog

class CSHUJUNew : public CDialog
{
// Construction
public:
	CSHUJUNew(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSHUJUNew)
	enum { IDD = IDD_DIALOG2 };
	CString	m_Course;
	CString	m_TeacherID;
	CString	m_TeacherName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSHUJUNew)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSHUJUNew)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHUJUNEW_H__A2D04A90_2990_4171_BEFA_C3BC0CE66FB9__INCLUDED_)
