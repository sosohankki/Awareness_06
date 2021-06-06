// StartFormView.cpp: 구현 파일
//

#include "pch.h"
#include "Awareness_06.h"
#include "StartFormView.h"
#include "constant.h"

// StartFormView

IMPLEMENT_DYNCREATE(StartFormView, CFormView)

StartFormView::StartFormView()
	: CFormView(IDD_DIALOG_START)
{
}

StartFormView::~StartFormView()
{
}

void StartFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_YEAR, m_edYear);
	DDX_Control(pDX, IDC_SPIN_YEAR, m_spYear);
	DDX_Control(pDX, IDC_EDIT_MONTH, m_edMonth);
	DDX_Control(pDX, IDC_SPIN_MONTH, m_spMonth);
}

BEGIN_MESSAGE_MAP(StartFormView, CFormView)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_YEAR, &StartFormView::OnDeltaposSpinYear)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MONTH, &StartFormView::OnDeltaposSpinMonth)
	ON_BN_CLICKED(IDC_BUTTON_NEXTPAGE, &StartFormView::OnBnClickedButtonNextpage)
END_MESSAGE_MAP()


// StartFormView 진단

#ifdef _DEBUG
void StartFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void StartFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// StartFormView 메시지 처리기


void StartFormView::OnDeltaposSpinYear(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iVal = pNMUpDown->iPos + pNMUpDown->iDelta;
	if ((2010 <= iVal) && (iVal <= 2020)) {
		CString sValue;
		sValue.Format(_T("%d\n"), iVal);
		m_edYear.SetWindowTextW(sValue);
	}

	*pResult = 0;
}


void StartFormView::OnDeltaposSpinMonth(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int iVal = pNMUpDown->iPos + pNMUpDown->iDelta;
	if ((1 <= iVal) && (iVal <= 12)) {
		CString sValue;
		sValue.Format(_T("%d\n"), iVal);
		m_edMonth.SetWindowTextW(sValue);
	}

	*pResult = 0;
}


void StartFormView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_edYear.SetWindowTextW(_T("2020"));
	m_edMonth.SetWindowTextW(_T("1"));

	m_spYear.SetRange(2010, 2020);
	m_spYear.SetPos(2020);

	m_spMonth.SetRange(1, 12);
	m_spMonth.SetPos(1);
}


BOOL StartFormView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void StartFormView::OnBnClickedButtonNextpage()
{
	::SendMessage(GetParent()->m_hWnd, WM_CHANGEFORM, IDD_DIALOG_SELECT_GAME, NULL);
}
