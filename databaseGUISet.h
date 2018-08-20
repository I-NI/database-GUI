// databaseGUISet.h : interface of the CDatabaseGUISet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATABASEGUISET_H__4162C595_E3D0_4F23_AB15_3468E13E0F9E__INCLUDED_)
#define AFX_DATABASEGUISET_H__4162C595_E3D0_4F23_AB15_3468E13E0F9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDatabaseGUISet : public CRecordset
{
public:
	CDatabaseGUISet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDatabaseGUISet)

// Field/Param Data
	//{{AFX_FIELD(CDatabaseGUISet, CRecordset)
	CString	m_SNO;
	CString	m_SNAME;
	CString	m_SAGE;
	CString	m_SDEPT;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDatabaseGUISet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATABASEGUISET_H__4162C595_E3D0_4F23_AB15_3468E13E0F9E__INCLUDED_)

