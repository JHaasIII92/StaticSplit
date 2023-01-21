// formView.cpp : implementation file
//

#include "pch.h"
#include "StaticSplit.h"
#include "formView.h"


// formView

IMPLEMENT_DYNCREATE(formView, CFormView)

formView::formView()
	: CFormView(IDD_formView)
{

}

formView::~formView()
{
}

void formView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(formView, CFormView)
END_MESSAGE_MAP()


// formView diagnostics

#ifdef _DEBUG
void formView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void formView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// formView message handlers
