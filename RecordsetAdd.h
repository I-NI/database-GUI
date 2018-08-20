#if !defined(AFX_RECORDSETADD_H__8A30FBBC_3FD1_4999_9628_E9B19E22CCA0__INCLUDED_)
#define AFX_RECORDSETADD_H__8A30FBBC_3FD1_4999_9628_E9B19E22CCA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RecordsetAdd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRecordsetAdd recordset

class CRecordsetAdd : public CRecordset
{
public:
	CRecordsetAdd(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRecordsetAdd)

// Field/Param Data
	//{{AFX_FIELD(CRecordsetAdd, CRecordset)
	CString	m_SNO;
	CString	m_SNAME;
	CString	m_SAGE;
	CString	m_SDEPT;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecordsetAdd)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECORDSETADD_H__8A30FBBC_3FD1_4999_9628_E9B19E22CCA0__INCLUDED_)
