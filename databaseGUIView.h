// databaseGUIView.h : interface of the CDatabaseGUIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATABASEGUIVIEW_H__44130784_ACFF_4A05_BB51_9F18BE573AA4__INCLUDED_)
#define AFX_DATABASEGUIVIEW_H__44130784_ACFF_4A05_BB51_9F18BE573AA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDatabaseGUICntrItem;
class CDatabaseGUISet;

class CDatabaseGUIView : public CRecordView
{
protected: // create from serialization only
	CDatabaseGUIView();
	DECLARE_DYNCREATE(CDatabaseGUIView)

public:
	//{{AFX_DATA(CDatabaseGUIView)
	enum { IDD = IDD_DATABASEGUI_FORM };
	CDatabaseGUISet* m_pSet;
	CString	m_query;
	CString	m_sql;
	CString	m_checkname;
	//}}AFX_DATA

// Attributes
public:
	CDatabaseGUIDoc* GetDocument();
	// m_pSelection holds the selection to the current CDatabaseGUICntrItem.
	// For many applications, such a member variable isn't adequate to
	//  represent a selection, such as a multiple selection or a selection
	//  of objects that are not CDatabaseGUICntrItem objects.  This selection
	//  mechanism is provided just to help you get started.

	// TODO: replace this selection mechanism with one appropriate to your app.
	CDatabaseGUICntrItem* m_pSelection;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDatabaseGUIView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL IsSelected(const CObject* pDocItem) const;// Container support
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDatabaseGUIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDatabaseGUIView)
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnMod();
	afx_msg void OnCheck();
	afx_msg void OnCreateTablebutton();
	afx_msg void OnAddNewtableButton();
	afx_msg void OnDelNewtableButton();
	afx_msg void OnModButton();
	afx_msg void OnSelect();
	afx_msg void Onquery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in databaseGUIView.cpp
inline CDatabaseGUIDoc* CDatabaseGUIView::GetDocument()
   { return (CDatabaseGUIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATABASEGUIVIEW_H__44130784_ACFF_4A05_BB51_9F18BE573AA4__INCLUDED_)
