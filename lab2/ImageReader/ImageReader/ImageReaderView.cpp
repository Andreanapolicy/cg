
// ImageReaderView.cpp : implementation of the CImageReaderView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ImageReader.h"
#endif

#include "ImageReaderDoc.h"
#include "ImageReaderView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageReaderView

IMPLEMENT_DYNCREATE(CImageReaderView, CView)

BEGIN_MESSAGE_MAP(CImageReaderView, CView)
END_MESSAGE_MAP()

// CImageReaderView construction/destruction

CImageReaderView::CImageReaderView() noexcept
{
	// TODO: add construction code here

}

CImageReaderView::~CImageReaderView()
{
}

BOOL CImageReaderView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CImageReaderView drawing

void CImageReaderView::OnDraw(CDC* /*pDC*/)
{
	CImageReaderDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CImageReaderView diagnostics

#ifdef _DEBUG
void CImageReaderView::AssertValid() const
{
	CView::AssertValid();
}

void CImageReaderView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageReaderDoc* CImageReaderView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageReaderDoc)));
	return (CImageReaderDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageReaderView message handlers
