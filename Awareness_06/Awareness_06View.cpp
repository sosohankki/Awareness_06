
// Awareness_06View.cpp: CAwareness06View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Awareness_06.h"
#endif

#include "Awareness_06Doc.h"
#include "Awareness_06View.h"
#include "constant.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAwareness06View

IMPLEMENT_DYNCREATE(CAwareness06View, CFormView)

BEGIN_MESSAGE_MAP(CAwareness06View, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_MESSAGE(WM_CHANGEFORM, &CAwareness06View::OnChangeform)
END_MESSAGE_MAP()

// CAwareness06View 생성/소멸

CAwareness06View::CAwareness06View() noexcept
	: CFormView(IDD_AWARENESS_MAIN_DIALOG)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CAwareness06View::~CAwareness06View()
{
}

void CAwareness06View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CAwareness06View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CAwareness06View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	allocForms();
	ShowForm(IDD_DIALOG_START);
}


// CAwareness06View 인쇄

BOOL CAwareness06View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CAwareness06View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CAwareness06View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CAwareness06View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CAwareness06View 진단

#ifdef _DEBUG
void CAwareness06View::AssertValid() const
{
	CFormView::AssertValid();
}

void CAwareness06View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CAwareness06Doc* CAwareness06View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAwareness06Doc)));
	return (CAwareness06Doc*)m_pDocument;
}
#endif //_DEBUG


// CAwareness06View 메시지 처리기

void CAwareness06View::allocForms()
{
	CCreateContext context;
	ZeroMemory(&context, sizeof(context));

	CRect rectOfPanelArea;

	GetDlgItem(IDC_STATIC_DLG)->GetWindowRect(&rectOfPanelArea);
	ScreenToClient(&rectOfPanelArea);

	m_startFormView = new StartFormView();
	m_startFormView->Create(NULL, NULL, WS_CHILD , rectOfPanelArea, this, IDD_DIALOG_START, &context);
	m_startFormView->OnInitialUpdate();
	m_startFormView->ShowWindow(SW_SHOW);
	
	m_gameSelectFormView = new GameSelectFormView();
	m_gameSelectFormView->Create(NULL, NULL, WS_CHILD, rectOfPanelArea, this, IDD_DIALOG_START, &context);
	m_gameSelectFormView->OnInitialUpdate();
	m_gameSelectFormView->ShowWindow(SW_HIDE);
}


void CAwareness06View::ShowForm(int idx)
{
	m_startFormView->ShowWindow(idx == IDD_DIALOG_START ? SW_SHOW : SW_HIDE);
	m_gameSelectFormView->ShowWindow(idx == IDD_DIALOG_SELECT_GAME ? SW_SHOW : SW_HIDE);
}


afx_msg LRESULT CAwareness06View::OnChangeform(WPARAM wParam, LPARAM lParam)
{
	ShowForm((int)wParam);
	return 0;
}
