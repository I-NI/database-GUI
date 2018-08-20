// CntrItem.h : interface of the CDatabaseGUICntrItem class
//

#if !defined(AFX_CNTRITEM_H__6168D315_DB1E_40EF_ABA4_95251FD1E4C5__INCLUDED_)
#define AFX_CNTRITEM_H__6168D315_DB1E_40EF_ABA4_95251FD1E4C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDatabaseGUIDoc;
class CDatabaseGUIView;

class CDatabaseGUICntrItem : public COleClientItem
{
	DECLARE_SERIAL(CDatabaseGUICntrItem)

// Constructors
public:
	CDatabaseGUICntrItem(CDatabaseGUIDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	CDatabaseGUIDoc* GetDocument()
		{ return (CDatabaseGUIDoc*)COleClientItem::GetDocument(); }
	CDatabaseGUIView* GetActiveView()
		{ return (CDatabaseGUIView*)COleClientItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDatabaseGUICntrItem)
	public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();
	protected:
	virtual void OnGetItemPosition(CRect& rPosition);
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	//}}AFX_VIRTUAL

// Implementation
public:
	~CDatabaseGUICntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNTRITEM_H__6168D315_DB1E_40EF_ABA4_95251FD1E4C5__INCLUDED_)
