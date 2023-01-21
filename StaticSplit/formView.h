#pragma once



// formView form view

class formView : public CFormView
{
	DECLARE_DYNCREATE(formView)

protected:
	formView();           // protected constructor used by dynamic creation
	virtual ~formView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_formView };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};


