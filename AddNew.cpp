// AddNew.cpp : implementation file
//

#include "stdafx.h"
#include "databaseGUI.h"
#include "AddNew.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddNew dialog


CAddNew::CAddNew(CWnd* pParent /*=NULL*/)
	: CDialog(CAddNew::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddNew)
	m_age = _T("");
	m_dept = _T("");
	m_id = _T("");
	m_name = _T("");
	//}}AFX_DATA_INIT
}


void CAddNew::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddNew)
	DDX_Text(pDX, IDC_AGE, m_age);
	DDX_Text(pDX, IDC_DEPT, m_dept);
	DDX_Text(pDX, IDC_ID, m_id);
	DDX_Text(pDX, IDC_NAME, m_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddNew, CDialog)
	//{{AFX_MSG_MAP(CAddNew)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddNew message handlers
