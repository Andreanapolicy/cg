
// ImageReaderView.h : interface of the CImageReaderView class
//

#pragma once

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
};

#ifndef _DEBUG  // debug version in ImageReaderView.cpp
inline CImageReaderDoc* CImageReaderView::GetDocument() const
   { return reinterpret_cast<CImageReaderDoc*>(m_pDocument); }
#endif

