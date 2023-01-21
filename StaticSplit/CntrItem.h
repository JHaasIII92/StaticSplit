
// CntrItem.h : interface of the CStaticSplitCntrItem class
//

#pragma once

class CStaticSplitDoc;
class CStaticSplitView;

class CStaticSplitCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CStaticSplitCntrItem)

// Constructors
public:
	CStaticSplitCntrItem(REOBJECT* preo = nullptr, CStaticSplitDoc* pContainer = nullptr);
		// Note: pContainer is allowed to be null to enable IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-null document pointer

// Attributes
public:
	CStaticSplitDoc* GetDocument()
		{ return reinterpret_cast<CStaticSplitDoc*>(CRichEditCntrItem::GetDocument()); }
	CStaticSplitView* GetActiveView()
		{ return reinterpret_cast<CStaticSplitView*>(CRichEditCntrItem::GetActiveView()); }

// Implementation
public:
	~CStaticSplitCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

