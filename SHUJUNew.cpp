// SHUJUNew.cpp : implementation file
//

#include "stdafx.h"
#include "databaseGUI.h"
#include "SHUJUNew.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSHUJUNew dialog


CSHUJUNew::CSHUJUNew(CWnd* pParent /*=NULL*/)
	: CDialog(CSHUJUNew::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSHUJUNew)
	m_Course = _T("");
	m_TeacherID = _T("");
	m_TeacherName = _T("");
	//}}AFX_DATA_INIT
}


void CSHUJUNew::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSHUJUNew)
	DDX_Text(pDX, IDC_Course, m_Course);
	DDX_Text(pDX, IDC_TeacherID, m_TeacherID);
	DDX_Text(pDX, IDC_TeacherName, m_TeacherName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSHUJUNew, CDialog)
	//{{AFX_MSG_MAP(CSHUJUNew)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSHUJUNew message handlers
