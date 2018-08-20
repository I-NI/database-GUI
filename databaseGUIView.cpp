// databaseGUIView.cpp : implementation of the CDatabaseGUIView class
//

#include "stdafx.h"
#include "databaseGUI.h"

#include "databaseGUISet.h"
#include "databaseGUIDoc.h"
#include "CntrItem.h"
#include "databaseGUIView.h"

#include "AddNew.h"	//CAddNew类
#include "MainFrm.h"		//主界面类
#include "SHUJUNew.h"	//CSHUJUNew类

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDatabaseGUIView

IMPLEMENT_DYNCREATE(CDatabaseGUIView, CRecordView)

BEGIN_MESSAGE_MAP(CDatabaseGUIView, CRecordView)
	//{{AFX_MSG_MAP(CDatabaseGUIView)
	ON_WM_DESTROY()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, OnCancelEditCntr)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_MOD, OnMod)
	ON_BN_CLICKED(IDC_CHECK, OnCheck)
	ON_BN_CLICKED(CreateTablebutton, OnCreateTablebutton)
	ON_BN_CLICKED(AddNewtableButton, OnAddNewtableButton)
	ON_BN_CLICKED(DelNewtableButton, OnDelNewtableButton)
	ON_BN_CLICKED(ModButton, OnModButton)
	ON_BN_CLICKED(Select, OnSelect)
	ON_BN_CLICKED(query, Onquery)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDatabaseGUIView construction/destruction

CDatabaseGUIView::CDatabaseGUIView()
	: CRecordView(CDatabaseGUIView::IDD)
{
	//{{AFX_DATA_INIT(CDatabaseGUIView)
	m_pSet = NULL;
	m_query = _T("");
	m_sql = _T("");
	m_checkname = _T("");
	//}}AFX_DATA_INIT
	m_pSelection = NULL;
	// TODO: add construction code here

}

CDatabaseGUIView::~CDatabaseGUIView()
{
}

void CDatabaseGUIView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDatabaseGUIView)
	DDX_FieldText(pDX, IDC_ID_EDIT, m_pSet->m_SNO, m_pSet);
	DDX_FieldText(pDX, IDC_NAME_EDIT, m_pSet->m_SNAME, m_pSet);
	DDX_FieldText(pDX, IDC_DEPT_EDIT, m_pSet->m_SDEPT, m_pSet);
	DDX_FieldText(pDX, IDC_AGE_EDIT, m_pSet->m_SAGE, m_pSet);
	DDX_Text(pDX, IDC_query_EDIT, m_query);
	DDX_Text(pDX, IDC_SQL_EDIT, m_sql);
	DDX_Text(pDX, IDC_CHECKNAME, m_checkname);
	//}}AFX_DATA_MAP
}

BOOL CDatabaseGUIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CDatabaseGUIView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_databaseGUISet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	// TODO: remove this code when final selection model code is written
	//m_pSelection = NULL;    // initialize selection

	while (!m_pSet->IsEOF())
	{
		m_pSet->MoveNext();
		m_pSet->GetRecordCount();
	}
	m_pSet->MoveFirst();
	UpdateData(true);
	CListCtrl * list=(CListCtrl*) GetDlgItem(IDC_LIST1);//(CListCtrl&)GetListCtrl();
	list->ModifyStyle(NULL,LVS_REPORT);

	list->SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE);
	//像这种过长的语句在word只能分开在不同行，但是在程序里要写在一行里。
	list->InsertColumn(0,"SNO");
	list->InsertColumn(1,"SNAME"); 
	list->InsertColumn(2,"SAGE"); 
	list->InsertColumn(3,"SDEPT"); 
	list->SetColumnWidth(0,80);
	list->SetColumnWidth(1,80);
	list->SetColumnWidth(2,80); 
	list->SetColumnWidth(3,80);
	UpdateData(false);
}

/////////////////////////////////////////////////////////////////////////////
// CDatabaseGUIView printing

BOOL CDatabaseGUIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDatabaseGUIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDatabaseGUIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CDatabaseGUIView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used.
   CRecordView::OnDestroy();
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
}


/////////////////////////////////////////////////////////////////////////////
// OLE Client support and commands

BOOL CDatabaseGUIView::IsSelected(const CObject* pDocItem) const
{
	// The implementation below is adequate if your selection consists of
	//  only CDatabaseGUICntrItem objects.  To handle different selection
	//  mechanisms, the implementation here should be replaced.

	// TODO: implement this function that tests for a selected OLE client item

	return pDocItem == m_pSelection;
}

void CDatabaseGUIView::OnInsertObject()
{
	// Invoke the standard Insert Object dialog box to obtain information
	//  for new CDatabaseGUICntrItem object.
	COleInsertDialog dlg;
	if (dlg.DoModal() != IDOK)
		return;

	BeginWaitCursor();

	CDatabaseGUICntrItem* pItem = NULL;
	TRY
	{
		// Create new item connected to this document.
		CDatabaseGUIDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CDatabaseGUICntrItem(pDoc);
		ASSERT_VALID(pItem);

		// Initialize the item from the dialog data.
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // any exception will do
		ASSERT_VALID(pItem);
		
        if (dlg.GetSelectionType() == COleInsertDialog::createNewItem)
			pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);

		// As an arbitrary user interface design, this sets the selection
		//  to the last item inserted.

		// TODO: reimplement selection as appropriate for your application

		m_pSelection = pItem;   // set selection to last inserted item
		pDoc->UpdateAllViews(NULL);
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the container (not the server) causes the deactivation.
void CDatabaseGUIView::OnCancelEditCntr()
{
	// Close any in-place active item on this view.
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}

// Special handling of OnSetFocus and OnSize are required for a container
//  when an object is being edited in-place.
void CDatabaseGUIView::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// need to set focus to this item if it is in the same view
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != NULL)
		{
			pWnd->SetFocus();   // don't call the base class
			return;
		}
	}

	CRecordView::OnSetFocus(pOldWnd);
}

void CDatabaseGUIView::OnSize(UINT nType, int cx, int cy)
{
	CRecordView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
		pActiveItem->SetItemRects();
}

/////////////////////////////////////////////////////////////////////////////
// CDatabaseGUIView diagnostics

#ifdef _DEBUG
void CDatabaseGUIView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDatabaseGUIView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDatabaseGUIDoc* CDatabaseGUIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDatabaseGUIDoc)));
	return (CDatabaseGUIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDatabaseGUIView database support
CRecordset* CDatabaseGUIView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CDatabaseGUIView message handlers

void CDatabaseGUIView::OnAdd() 
{
// TODO: Add your control notification handler code here
	CAddNew dlg; 
	CString str; 
	CString str1; 
	CDatabase db;
	if (IDOK==dlg.DoModal())
	{
		try
		{
str1.Format("INSERT INTO S/*这里为自己建的表的名称*/(SNO,SNAME,SAGE,SDEPT) values('%s','%s','%s','%s')",dlg.m_id,dlg.m_name,dlg.m_age,dlg.m_dept);
			db.Open("学生信息");
			db.ExecuteSQL(str1);
		}
		catch(CDBException *e)
		{
			AfxMessageBox(e->m_strError);
			return;
		}
		str.Format("添加[%s]成功！",dlg.m_name); 
		MessageBox(str,NULL,MB_OK|MB_ICONINFORMATION);
	}

		
}

void CDatabaseGUIView::OnDel() 
{
// TODO: Add your control notification handler code here
	//
	CAddNew dlg; 
	CDatabase db; 
	try
	{
		CString str1; CString str;
		
		str.Format("删除记录[%s]成功！",m_pSet->m_SNAME);
		str1.Format("DELETE FROM S/*同理改为自己建立的S表的名称*/ WHERE SNO='%s'",m_pSet->m_SNO);
		db.Open("学生信息");
		db.ExecuteSQL(str1); 
		MessageBox(str,NULL,MB_OK|MB_ICONINFORMATION);
		//	MessageBox("HELLO");
	}
	catch (CDBException* e)
	{
		AfxMessageBox(e->m_strError);
		return;
	}	
}

void CDatabaseGUIView::OnMod() 
{
// TODO: Add your control notification handler code here
	CAddNew dlg; 
	CString str; 
	CString str1; 
	CDatabase db;
	if (IDOK==dlg.DoModal())
	{
	try
	{
	str1.Format("UPDATE S SET SNAME='%s',SAGE='%s',SDEPT='%s' WHERE SNO='%s'",dlg.m_name,dlg.m_age,dlg.m_dept,dlg.m_id);
		db.Open("学生信息");
		db.ExecuteSQL(str1);
	}
	catch(CDBException *e)
	{
		AfxMessageBox(e->m_strError);
		return;
	}
	str.Format("修改[%s]成功！",dlg.m_name);
	MessageBox(str,NULL,MB_OK|MB_ICONINFORMATION);
	}	
}

void CDatabaseGUIView::OnCheck() 
{
// TODO: Add your control notification handler code here
	UpdateData(true);
	CDatabase db;
	db.Open("学生信息");
	CString str;
	m_checkname.TrimLeft();
	if(m_checkname.IsEmpty())
	{
		MessageBox("要查询的学号不能为空! ");
		return;
	}
	CRecordset recset(&db);
	CString strSQL;
	strSQL.Format( "SELECT * FROM S WHERE SNO='%s'", m_checkname );
	recset.Open(CRecordset::forwardOnly, strSQL, CRecordset::readOnly);
	if(recset.IsEOF())
	{
		MessageBox("没有查到你要找的学生记录!");
	}
	else
	{
		CString temp1, temp2, temp4;
		CString temp3;
		recset.GetFieldValue("SNO", temp1);
		recset.GetFieldValue("SNAME", temp2);
		recset.GetFieldValue("SAGE", temp3);
		recset.GetFieldValue("SDEPT", temp4);
		m_pSet->m_SNO=temp1;
		m_pSet->m_SNAME=temp2;
		m_pSet->m_SAGE=temp3;
		m_pSet->m_SDEPT=temp4;

		GetDlgItem(IDC_ID_EDIT)-> SetWindowText(temp1); 
		GetDlgItem(IDC_NAME_EDIT)-> SetWindowText(temp2); 
		GetDlgItem(IDC_AGE_EDIT)-> SetWindowText(temp3); 
		GetDlgItem(IDC_DEPT_EDIT)-> SetWindowText(temp4); 
	}
	recset.Close();	
}

void CDatabaseGUIView::OnCreateTablebutton() 
{
// TODO: Add your control notification handler code here
	CDatabase db;
	//if (!SQLConfigDataSource(NULL,ODBC_ADD_DSN,"SQL Server","DSN=学生信息"));
	try
	{
		db.Open("学生信息");
		db.ExecuteSQL("CREATE TABLE	TEACHERS(TeacherID CHAR(4),TeacherName CHAR(10),Course CHAR(10), PRIMARY KEY (TeacherID))");
	}
	catch (CDBException* e)
	{
		AfxMessageBox(e->m_strError);
		return;
	}
	MessageBox("新建表成功！");	
}

void CDatabaseGUIView::OnAddNewtableButton() 
{
// TODO: Add your control notification handler code here
	CSHUJUNew dlg; 
	CString str; 
	CString str1; 
	CDatabase db;
	if (IDOK==dlg.DoModal())
	{
		try
		{
			str1.Format("INSERT INTO TEACHERS(TeacherID,TeacherName,Course) VALUES('%s','%s','%s')",dlg.m_TeacherID,dlg.m_TeacherName,dlg.m_Course);
			db.Open("学生信息");
			db.ExecuteSQL(str1);
		}
		catch (CDBException* e)
		{
			e->ReportError();
			return;
		}
		MessageBox("添加数据成功！");
	}	
}

void CDatabaseGUIView::OnDelNewtableButton() 
{
// TODO: Add your control notification handler code here
	CDatabase db;
	try
	{
		db.Open("学生信息");
		db.ExecuteSQL("DROP TABLE TEACHERS");
	}
	catch(CDBException *e)
	{
		AfxMessageBox(e->m_strError);
		return;
	}
	MessageBox("删除表成功！");	
}

void CDatabaseGUIView::OnModButton() 
{
// TODO: Add your control notification handler code here
	CDatabase db;
	try
	{
		db.Open("学生信息");
		db.ExecuteSQL("ALTER TABLE TEACHERS ADD Teacher_Age INT");
	}
	catch(CDBException *e)
	{
		AfxMessageBox(e->m_strError);
		return;
	}
	MessageBox("修改表成功！");		
}

void CDatabaseGUIView::OnSelect() 
{
// TODO: Add your control notification handler code here
	UpdateData(true);
	CListCtrl * list=(CListCtrl*) GetDlgItem(IDC_LIST1);//(CListCtrl&)GetListCtrl();
	list->ModifyStyle(NULL,LVS_REPORT);
	list->SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE);
	list->DeleteAllItems(); 
	CDatabase db;
	db.Open("学生信息");
	CRecordset recset(&db);
	list->DeleteAllItems();

	CString sql,edit1;
	m_sql.TrimLeft();
	if ( m_sql.IsEmpty())
	{
		AfxMessageBox("请输入查询语句！");
		return;
	}
	sql.Format("%s", m_sql); 
	char tempp[255]; 
	strcpy(tempp,sql);
	for (int i=0;i<3;i++)
	{
		if (isupper(tempp[i]))
			tempp[i]=tolower(tempp[i]);
	}
	if((tempp[0]=='s' && tempp[1]=='e' && tempp[2]=='l'))
	{
		recset.Open(CRecordset::forwardOnly,sql,CRecordset::readOnly);
		int ii;
		while(!recset.IsEOF())
		{
			CString temp1,temp2,temp3,temp4; recset.GetFieldValue("SNO",temp1); recset.GetFieldValue("SNAME",temp2); recset.GetFieldValue("SAGE",temp3); recset.GetFieldValue("SDEPT",temp4);
			ii=list->InsertItem(0,"");
			list->InsertItem(ii,"");
			list->SetItemText(ii,0, temp1); list->SetItemText(ii,1, temp2); list->SetItemText(ii,2, temp3); list->SetItemText(ii,3, temp4); UpdateData(false);
			ii++;
			recset.MoveNext();
		}
	}
	else
	{
		recset.Close(); MessageBox("查询成功！！！");
		try
		{
			db.ExecuteSQL(sql);
			db.Close();
		}
		catch (CDBException* e)
		{
			AfxMessageBox(e->m_strError);
			return;
		}
		MessageBox("执行成功，请刷新数据库显示执行结果！");
	}
	db.Close();		
}

void CDatabaseGUIView::Onquery() 
{
// TODO: Add your control notification handler code here
	UpdateData(true);
	CListCtrl * list=(CListCtrl*) GetDlgItem(IDC_LIST1);//(CListCtrl&)GetListCtrl();
	list->ModifyStyle(NULL,LVS_REPORT);
	list->SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE);
	//list->DeleteAllItems();
	CDatabase db;
	db.Open("学生信息");
	CRecordset recset(&db); 
	list->DeleteAllItems(); 
	CString sql,edit1; 
	m_query.TrimLeft();
	if ( m_query.IsEmpty())
	{
		AfxMessageBox("请输入学号、姓名、年龄或专业！");
		return;
	}
	sql.Format("select * from S where (SNO='%s') or (SNAME='%s') or (SAGE='%s') or (SDEPT='%s')", m_query,m_query,m_query,m_query); recset.Open(CRecordset::forwardOnly,sql,CRecordset::readOnly); int ii;
	while(!recset.IsEOF())
	{
	CString temp1,temp2,temp3,temp4; recset.GetFieldValue("SNO",temp1); recset.GetFieldValue("SNAME",temp2); recset.GetFieldValue("SAGE",temp3); recset.GetFieldValue("SDEPT",temp4);


	ii=list->InsertItem(0,"");
	list->InsertItem(ii,"");
	list->SetItemText(ii,0, temp1); list->SetItemText(ii,1, temp2); list->SetItemText(ii,2, temp3); list->SetItemText(ii,3, temp4); UpdateData(false);
	ii++;
	recset.MoveNext();
	}
	recset.Close(); MessageBox("查询成功！！！");
	db.Close();	
}
