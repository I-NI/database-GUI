// databaseGUISet.cpp : implementation of the CDatabaseGUISet class
//

#include "stdafx.h"
#include "databaseGUI.h"
#include "databaseGUISet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDatabaseGUISet implementation

IMPLEMENT_DYNAMIC(CDatabaseGUISet, CRecordset)

CDatabaseGUISet::CDatabaseGUISet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDatabaseGUISet)
	m_SNO = _T("");
	m_SNAME = _T("");
	m_SAGE = _T("");
	m_SDEPT = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CDatabaseGUISet::GetDefaultConnect()
{
	return _T("ODBC;DSN=学生信息");
}

CString CDatabaseGUISet::GetDefaultSQL()
{
	return _T("[dbo].[S]");
}

void CDatabaseGUISet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDatabaseGUISet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[SNO]"), m_SNO);
	RFX_Text(pFX, _T("[SNAME]"), m_SNAME);
	RFX_Text(pFX, _T("[SAGE]"), m_SAGE);
	RFX_Text(pFX, _T("[SDEPT]"), m_SDEPT);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDatabaseGUISet diagnostics

#ifdef _DEBUG
void CDatabaseGUISet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDatabaseGUISet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
