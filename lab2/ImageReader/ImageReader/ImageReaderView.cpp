
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

// CImageReaderView

IMPLEMENT_DYNCREATE(CImageReaderView, CView)

BEGIN_MESSAGE_MAP(CImageReaderView, CView)
	ON_COMMAND(ID_FILE_OPEN, &CImageReaderView::OnFileOpen)
END_MESSAGE_MAP()

// CImageReaderView construction/destruction

CImageReaderView::CImageReaderView() noexcept
{
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

void CImageReaderView::OnDraw(CDC* pDC)
{
	CImageReaderDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	Draw(pDC);
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

void CImageReaderView::OnFileOpen()
{
	LPCTSTR pszFilter = _T("PNG (*.png)|*.png|")
						_T("JPG (*.jpg)|*.jpg|")
						_T("JPEG (*.jpeg)|*.jpeg|")
						_T("BMP (*.bmp)|*.bmp|");
	CFileDialog dialogFile(TRUE, NULL, NULL, OFN_HIDEREADONLY || OFN_FILEMUSTEXIST, pszFilter, AfxGetMainWnd());

	if (IDOK == dialogFile.DoModal())
	{
		auto fileName = dialogFile.GetPathName();
		Gdiplus::Image image(fileName);

		m_pBitmap = std::make_shared<Gdiplus::Bitmap>(fileName);
		
		Invalidate();
		UpdateWindow();

	}
}

CImageReaderDoc* CImageReaderView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageReaderDoc)));
	return (CImageReaderDoc*)m_pDocument;
}
#endif //_DEBUG

void CImageReaderView::Draw(CDC* pDC)
{
	if (m_pBitmap == nullptr)
	{
		return;
	}
	
	auto bound = GetContentBound();
	Gdiplus::Graphics graphics(pDC->GetSafeHdc());
	
	graphics.DrawImage(m_pBitmap.get(), bound.X, bound.Y, bound.Width, bound.Height);
}

Gdiplus::Rect CImageReaderView::GetContentBound() const
{
	CRect size;
	GetClientRect(&size);
	int windowWidth = size.Width();
	int windowHeight = size.Height();

	int contentWidth = m_pBitmap->GetWidth();
	int contentHeight = m_pBitmap->GetHeight();

	double coef = (double)contentWidth / (double)contentHeight;
	int x = (double)(windowWidth - contentWidth) / 2.0;
	int y = (double)(windowHeight - contentHeight) / 2.0;
	int width;
	int height;

	if (windowWidth < contentWidth && windowHeight >= contentHeight)
	{
		contentWidth = windowWidth;
		contentHeight = contentWidth / coef;
		x = 0;
	}
	else if (windowHeight < contentHeight && windowWidth >= contentWidth)
	{
		contentHeight = windowHeight;
		contentWidth = contentHeight * coef;
		y = 0;
	}
	else
	{
	
	}

	return { 0, 0, contentWidth, contentHeight };
}