#if !defined(AFX_ADDNEW_H__2110B1FA_31B1_42B7_987C_540C1C4BEFE2__INCLUDED_)
#define AFX_ADDNEW_H__2110B1FA_31B1_42B7_987C_540C1C4BEFE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddNew.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddNew dialog

class CAddNew : public CDialog
{
// Construction
public:
	CAddNew(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddNew)
	enum { IDD = IDD_DIALOG1 };
	CString	m_age;
	CString	m_dept;
	CString	m_id;
	CString	m_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddNew)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddNew)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDNEW_H__2110B1FA_31B1_42B7_987C_540C1C4BEFE2__INCLUDED_)
