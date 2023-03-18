
// MiniPaintView.h : interface of the CMiniPaintView class
//

#pragma once

#include "CGdiplusInitializer.h"
#include "ContentFitManager.h"
#include <memory>

class CMiniPaintView : public CView
{
protected: // create from serialization only
	CMiniPaintView() noexcept;
	DECLARE_DYNCREATE(CMiniPaintView)

// Attributes
public:
	CMiniPaintDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMiniPaintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

private:
	Gdiplus::Rect GetContentBound();
	void Draw(CDC* pDC);
	void RedrawBackBuffer();

	CGdiplusInitializer m_gdiplusInitializer;
	std::shared_ptr<Gdiplus::Bitmap> m_pBitmap;
	std::shared_ptr<Gdiplus::Bitmap> m_pBackBuffer;
	ContentFitManager m_contentFitManager;

public:
	afx_msg void OnFileNew();
};

#ifndef _DEBUG  // debug version in MiniPaintView.cpp
inline CMiniPaintDoc* CMiniPaintView::GetDocument() const
   { return reinterpret_cast<CMiniPaintDoc*>(m_pDocument); }
#endif

