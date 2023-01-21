
// CntrItem.cpp : implementation of the CStaticSplitCntrItem class
//

#include "pch.h"
#include "framework.h"
#include "StaticSplit.h"

#include "StaticSplitDoc.h"
#include "StaticSplitView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStaticSplitCntrItem implementation

IMPLEMENT_SERIAL(CStaticSplitCntrItem, CRichEditCntrItem, 0)

CStaticSplitCntrItem::CStaticSplitCntrItem(REOBJECT* preo, CStaticSplitDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: add one-time construction code here
}

CStaticSplitCntrItem::~CStaticSplitCntrItem()
{
	// TODO: add cleanup code here
}


// CStaticSplitCntrItem diagnostics

#ifdef _DEBUG
void CStaticSplitCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CStaticSplitCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

