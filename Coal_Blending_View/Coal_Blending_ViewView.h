
// Coal_Blending_ViewView.h : interface of the CCoal_Blending_ViewView class
//

#pragma once


class CCoal_Blending_ViewView : public CScrollView
{
protected: // create from serialization only
	CCoal_Blending_ViewView();
	DECLARE_DYNCREATE(CCoal_Blending_ViewView)

// Attributes
public:
	CCoal_Blending_ViewDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCoal_Blending_ViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	
	CString ValidatePath(CString);
	afx_msg void OnY18Currentvalue();
	
	afx_msg void OnY18Blend();
	
	afx_msg void OnSilo153();
	afx_msg void OnSiloCoalmines();
	afx_msg void OnSilo2();
	afx_msg void OnSilo2a();
};

#ifndef _DEBUG  // debug version in Coal_Blending_ViewView.cpp
inline CCoal_Blending_ViewDoc* CCoal_Blending_ViewView::GetDocument() const
   { return reinterpret_cast<CCoal_Blending_ViewDoc*>(m_pDocument); }
#endif

