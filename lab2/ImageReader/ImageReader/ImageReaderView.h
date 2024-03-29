
// ImageReaderView.h : interface of the CImageReaderView class
//

#pragma once
#include <memory>
#include "gdiplus.h"
#include "GdiplusInitializer.h"
#include "ContentFitManager.h"

class CImageReaderView : public CView
{
protected: // create from serialization only
	CImageReaderView() noexcept;
	DECLARE_DYNCREATE(CImageReaderView)

// Attributes
public:
	CImageReaderDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CImageReaderView();
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
	afx_msg void OnSize(UINT nType, int cx, int cy);

private:
	Gdiplus::Rect CImageReaderView::GetContentBound();
	void Draw(CDC* pDC);
	void RedrawBackBuffer();

	CGdiplusInitializer m_gdiplusInitializer;
	std::shared_ptr<Gdiplus::Bitmap> m_pBitmap;
	std::shared_ptr<Gdiplus::Bitmap> m_pBackBuffer;
	ContentFitManager m_contentFitManager;
};

#ifndef _DEBUG  // debug version in ImageReaderView.cpp
inline CImageReaderDoc* CImageReaderView::GetDocument() const
   { return reinterpret_cast<CImageReaderDoc*>(m_pDocument); }
#endif

