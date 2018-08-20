// RecordsetAdd.cpp : implementation file
//

#include "stdafx.h"
#include "databaseGUI.h"
#include "RecordsetAdd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecordsetAdd

IMPLEMENT_DYNAMIC(CRecordsetAdd, CRecordset)

CRecordsetAdd::CRecordsetAdd(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRecordsetAdd)
	m_SNO = _T("");
	m_SNAME = _T("");
	m_SAGE = _T("");
	m_SDEPT = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CRecordsetAdd::GetDefaultConnect()
{
	return _T("ODBC;DSN=学生信息");
}

CString CRecordsetAdd::GetDefaultSQL()
{
	return _T("[dbo].[S]");
}

void CRecordsetAdd::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRecordsetAdd)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[SNO]"), m_SNO);
	RFX_Text(pFX, _T("[SNAME]"), m_SNAME);
	RFX_Text(pFX, _T("[SAGE]"), m_SAGE);
	RFX_Text(pFX, _T("[SDEPT]"), m_SDEPT);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRecordsetAdd diagnostics

#ifdef _DEBUG
void CRecordsetAdd::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRecordsetAdd::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
