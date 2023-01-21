
// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "pch.h"
#include "framework.h"
#include "StaticSplit.h"
#include "StaticSplitDoc.h"
#include "StaticSplitView.h"
#include "formView.h"
#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
END_MESSAGE_MAP()

// CChildFrame construction/destruction

CChildFrame::CChildFrame() noexcept
{
	// TODO: add member initialization code here
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying the CREATESTRUCT cs
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}
#endif //_DEBUG

// CChildFrame message handlers


BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class

// create a splitter with 1 row, 2 columns
	if (!m_wndMainSplit.CreateStatic(this, 1, 2))
	{
		TRACE0("Failed to CreateStaticSplitter\n");
		return FALSE;
	}

	// add the first splitter pane - the default view in column 0
	if (!m_wndMainSplit.CreateView(0, 0,
		RUNTIME_CLASS(formView), CSize(0, 0), pContext))
	{
		TRACE0("Failed to create first pane\n");
		return FALSE;
	}

	// add the second splitter pane - which is a nested splitter with 2 rows
	if (!m_wndChildSplit.CreateStatic(
		&m_wndMainSplit,     // our parent window is the first splitter
		2, 2,               // the new splitter is 2 rows, 1 column
		WS_CHILD | WS_VISIBLE | WS_BORDER,  // style, WS_BORDER is needed
		m_wndMainSplit.IdFromRowCol(0, 1)
		// new splitter is in the first row, 2nd column of first splitter
	))
	{
		TRACE0("Failed to create nested splitter\n");
		return FALSE;
	}

	// now create the two views inside the nested splitter
	int cyText = max(lpcs->cy - 70, 20);    // height of text pane

	if (!m_wndChildSplit.CreateView(0, 0,
		RUNTIME_CLASS(CStaticSplitView), CSize(0, cyText), pContext))
	{
		TRACE0("Failed to create second pane\n");
		return FALSE;
	}

	if (!m_wndChildSplit.CreateView(1, 0,
		RUNTIME_CLASS(CStaticSplitView), CSize(0, 0), pContext))
	{
		TRACE0("Failed to create third pane\n");
		return FALSE;
	}

	if (!m_wndChildSplit.CreateView(0, 1,
		RUNTIME_CLASS(CStaticSplitView), CSize(0, 0), pContext))
	{
		TRACE0("Failed to create third pane\n");
		return FALSE;
	}

	if (!m_wndChildSplit.CreateView(1, 1,
		RUNTIME_CLASS(CStaticSplitView), CSize(0, 0), pContext))
	{
		TRACE0("Failed to create third pane\n");
		return FALSE;
	}

	// activate the model pane
	SetActiveView((CView*)m_wndChildSplit.GetPane(0, 0));

	// default is to not display the object view
	//m_wndSplitter.HideColumn(0);

	return TRUE;
}
