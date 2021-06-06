#pragma once
// StartFormView 폼 보기

class StartFormView : public CFormView
{
	DECLARE_DYNCREATE(StartFormView)

public:
	StartFormView();
	virtual ~StartFormView();

public:
#ifdef AFX_DESIGN_TIME 
	enum { IDD = IDD_DIALOG_START };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edYear;
	CSpinButtonCtrl m_spYear;
	CEdit m_edMonth;
	CSpinButtonCtrl m_spMonth;
	afx_msg void OnDeltaposSpinYear(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpinMonth(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnInitialUpdate();
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg void OnBnClickedButtonNextpage();
};


