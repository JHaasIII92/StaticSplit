
// StaticSplitView.h : interface of the CStaticSplitView class
//

#pragma once

class CStaticSplitCntrItem;

class CStaticSplitView : public CRichEditView
{
protected: // create from serialization only
	CStaticSplitView() noexcept;
	DECLARE_DYNCREATE(CStaticSplitView)

// Attributes
public:
	CStaticSplitDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CStaticSplitView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	bool m_bNotifyChng;

protected:

// Generated message map functions
protected:
	afx_msg void OnDestroy();
	DECLARE_MESSAGE_MAP()
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
public:
	afx_msg void OnEnChange();
};

#ifndef _DEBUG  // debug version in StaticSplitView.cpp
inline CStaticSplitDoc* CStaticSplitView::GetDocument() const
   { return reinterpret_cast<CStaticSplitDoc*>(m_pDocument); }
#endif

