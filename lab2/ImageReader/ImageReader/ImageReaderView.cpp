#include "pch.h"
#include "framework.h"
#ifndef SHARED_HANDLERS
#include "ImageReader.h"
#endif

#include "ImageReaderDoc.h"
#include "ImageReaderView.h"

namespace
{
void DrawBackground(Gdiplus::Graphics& graphics, const Gdiplus::Rect& bound)
{
	Gdiplus::SolidBrush firstPen(Gdiplus::Color::AliceBlue);
	Gdiplus::SolidBrush secondPen(Gdiplus::Color::LightCoral);

	for (int posY = bound.Y; posY <= bound.Height + bound.Y; posY += 20)
	{
		for (int posX = bound.X; posX <= bound.Width + bound.X; posX += 20)
		{
			int width = 20;
			int height = 20;
			
			if (bound.Width + bound.X - posX < width)
			{
				width = bound.Width + bound.X - posX;
			}
			if (bound.Height + bound.Y - posY < height)
			{
				height = bound.Height + bound.Y - posY;
			}

			graphics.FillRectangle(((posX + posY) / 20 % 2 == 0) ? &firstPen : &secondPen, posX, posY, width, height);
		}
	}
}
}


IMPLEMENT_DYNCREATE(CImageReaderView, CView)

BEGIN_MESSAGE_MAP(CImageReaderView, CView)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

CImageReaderView::CImageReaderView() noexcept
{
}

CImageReaderView::~CImageReaderView()
{
}

BOOL CImageReaderView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

void CImageReaderView::OnDraw(CDC* pDC)
{
	CImageReaderDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	Draw(pDC);
}

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
		m_contentFitManager.SetContentSize(m_pBitmap->GetWidth(), m_pBitmap->GetHeight());
		m_pBackBuffer = std::make_shared<Gdiplus::Bitmap>(m_pBitmap->GetWidth(), m_pBitmap->GetHeight()); 
		
		Invalidate();
		UpdateWindow();
	}
}

BOOL CImageReaderView::OnEraseBkgnd(CDC* pDC)
{
	return 0;
}

CImageReaderDoc* CImageReaderView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageReaderDoc)));
	return (CImageReaderDoc*)m_pDocument;
}
#endif //_DEBUG

void CImageReaderView::Draw(CDC* pDC)
{
	RedrawBackBuffer();
	if (m_pBackBuffer.get())
	{
		Gdiplus::Graphics graphics(pDC->GetSafeHdc());
		graphics.DrawImage(m_pBackBuffer.get(), 0, 0);
	}
}

void CImageReaderView::RedrawBackBuffer()
{
	Gdiplus::Graphics graphics(m_pBackBuffer.get());

	graphics.Clear(Gdiplus::Color::White);
	auto bound = GetContentBound();

	DrawBackground(graphics, bound);
	graphics.DrawImage(m_pBitmap.get(), bound.X, bound.Y, bound.Width, bound.Height);
}

Gdiplus::Rect CImageReaderView::GetContentBound()
{
	CRect size;
	GetClientRect(&size);
	m_contentFitManager.CalculateContentBounds(size.Width(), size.Height());
	auto bounds = m_contentFitManager.GetContentBounds();
	
	return { bounds.x, bounds.y, bounds.width, bounds.height };
}