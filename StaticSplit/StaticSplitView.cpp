
// StaticSplitView.cpp : implementation of the CStaticSplitView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "StaticSplit.h"
#endif

#include "StaticSplitDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "StaticSplitView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStaticSplitView

IMPLEMENT_DYNCREATE(CStaticSplitView, CRichEditView)

BEGIN_MESSAGE_MAP(CStaticSplitView, CRichEditView)
	ON_WM_DESTROY()
	ON_CONTROL_REFLECT(EN_CHANGE, &CStaticSplitView::OnEnChange)
END_MESSAGE_MAP()

// CStaticSplitView construction/destruction

CStaticSplitView::CStaticSplitView() noexcept
{
	// TODO: add construction code here
	m_bNotifyChng = true;

}

CStaticSplitView::~CStaticSplitView()
{
}

BOOL CStaticSplitView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRichEditView::PreCreateWindow(cs);
}

void CStaticSplitView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// Set the printing margins (720 twips = 1/2 inch)
	SetMargins(CRect(720, 720, 720, 720));
}

void CStaticSplitView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != nullptr && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == nullptr);
   }
   CRichEditView::OnDestroy();
}



// CStaticSplitView diagnostics

#ifdef _DEBUG
void CStaticSplitView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CStaticSplitView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CStaticSplitDoc* CStaticSplitView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStaticSplitDoc)));
	return (CStaticSplitDoc*)m_pDocument;
}
#endif //_DEBUG


// CStaticSplitView message handlers


void CStaticSplitView::OnUpdate(CView* pSender, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: Add your specialized code here and/or call the base class
		// TODO: Add your specialized code here and/or call the base class
	CStaticSplitDoc* pDoc = GetDocument();
	CStaticSplitView* pNewView = (CStaticSplitView*)pSender;

	if (pNewView == NULL)
	{
		return;
	}
	m_bNotifyChng = false;
	POSITION pos = pDoc->GetFirstViewPosition();
	while (pos)
	{
		CRect  rectClip;
		CString str;
		CStaticSplitView* pView = (CStaticSplitView*)pDoc->GetNextView(pos);

		if (pNewView != pView)
		{
			pNewView->GetWindowTextW(str);
			pView->m_bNotifyChng = false;
			pView->SetWindowTextW(str);
			pView->m_bNotifyChng = true;
		}
	}

	return;
}


void CStaticSplitView::OnEnChange()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CRichEditView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	if (m_bNotifyChng)
	{
		CStaticSplitDoc* pDoc = GetDocument();
		pDoc->UpdateAllViews(this);
	}

	
	return;
}
