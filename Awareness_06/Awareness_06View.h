
// Awareness_06View.h: CAwareness06View 클래스의 인터페이스
//

#pragma once
#include "StartFormView.h"
#include "GameSelectFormView.h"

class CAwareness06View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CAwareness06View() noexcept;
	DECLARE_DYNCREATE(CAwareness06View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_AWARENESS_MAIN_DIALOG };
#endif

// 특성입니다.
public:
	CAwareness06Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

	StartFormView* m_startFormView;
	GameSelectFormView* m_gameSelectFormView;

// 구현입니다.
public:
	virtual ~CAwareness06View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	void allocForms();
	void ShowForm(int idx);
protected:
	afx_msg LRESULT OnChangeform(WPARAM wParam, LPARAM lParam);
};

#ifndef _DEBUG  // Awareness_06View.cpp의 디버그 버전
inline CAwareness06Doc* CAwareness06View::GetDocument() const
   { return reinterpret_cast<CAwareness06Doc*>(m_pDocument); }
#endif

