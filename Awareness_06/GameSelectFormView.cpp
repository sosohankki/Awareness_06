// GameSelectFormView.cpp: 구현 파일
//

#include "pch.h"
#include "Awareness_06.h"
#include "GameSelectFormView.h"
#include "constant.h"

// GameSelectFormView

IMPLEMENT_DYNCREATE(GameSelectFormView, CFormView)

GameSelectFormView::GameSelectFormView()
	: CFormView(IDD_DIALOG_SELECT_GAME)
{

}

GameSelectFormView::~GameSelectFormView()
{
}

void GameSelectFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(GameSelectFormView, CFormView)
	ON_BN_CLICKED(IDOK, &GameSelectFormView::OnBnClickedOk)
END_MESSAGE_MAP()


// GameSelectFormView 진단

#ifdef _DEBUG
void GameSelectFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void GameSelectFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// GameSelectFormView 메시지 처리기


BOOL GameSelectFormView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void GameSelectFormView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}


void GameSelectFormView::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.


	::SendMessage(GetParent()->m_hWnd, WM_CHANGEFORM, IDD_DIALOG_START, NULL);
}
