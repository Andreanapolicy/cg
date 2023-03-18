#include "pch.h"
#include "framework.h"
#ifndef SHARED_HANDLERS
#include "MiniPaint.h"
#endif

#include "MiniPaintDoc.h"
#include "MiniPaintView.h"


// CMiniPaintView

IMPLEMENT_DYNCREATE(CMiniPaintView, CView)

BEGIN_MESSAGE_MAP(CMiniPaintView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CMiniPaintView::OnFileOpen)
	ON_COMMAND(ID_FILE_NEW, &CMiniPaintView::OnFileNew)
END_MESSAGE_MAP()

// CMiniPaintView construction/destruction

CMiniPaintView::CMiniPaintView() noexcept
{
	// TODO: add construction code here

}

CMiniPaintView::~CMiniPaintView()
{
}

BOOL CMiniPaintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMiniPaintView drawing

void CMiniPaintView::OnDraw(CDC* pDC)
{
	CMiniPaintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	Draw(pDC);
}

BOOL CMiniPaintView::OnEraseBkgnd(CDC* pDC)
{
	return 0;
}

// CMiniPaintView printing

BOOL CMiniPaintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMiniPaintView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CMiniPaintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

#ifdef _DEBUG
void CMiniPaintView::AssertValid() const
{
	CView::AssertValid();
}

void CMiniPaintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMiniPaintDoc* CMiniPaintView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMiniPaintDoc)));
	return (CMiniPaintDoc*)m_pDocument;
}
#endif //_DEBUG

void CMiniPaintView::OnFileOpen()
{
	LPCTSTR pszFilter = _T("JPG (*.jpg)|*.jpg|")
						_T("JPEG (*.jpeg)|*.jpeg|")
						_T("BMP (*.bmp)|*.bmp|");
	CFileDialog dialogFile(TRUE, NULL, NULL, OFN_HIDEREADONLY || OFN_FILEMUSTEXIST, pszFilter, AfxGetMainWnd());

	if (IDOK == dialogFile.DoModal())
	{
		auto fileName = dialogFile.GetPathName();
		Gdiplus::Image image(fileName);

		CRect rcClient;
		GetClientRect(&rcClient);
		unsigned clientWidth = rcClient.Width();
		unsigned clientHeight = rcClient.Height();

		m_pBitmap = std::make_shared<Gdiplus::Bitmap>(fileName);
		m_contentFitManager.SetContentSize(m_pBitmap->GetWidth(), m_pBitmap->GetHeight());
		m_pBackBuffer = std::make_shared<Gdiplus::Bitmap>(clientWidth, clientHeight);

		Invalidate();
		UpdateWindow();
	}
}

void CMiniPaintView::Draw(CDC* pDC)
{
	RedrawBackBuffer();
	if (m_pBackBuffer.get())
	{
		Gdiplus::Graphics graphics(pDC->GetSafeHdc());
		Gdiplus::Pen pen(Gdiplus::Color::Black);
		graphics.DrawRectangle(&pen, 20, 20, 500, 200);
		graphics.DrawImage(m_pBackBuffer.get(), 0, 0);
	}
}

void CMiniPaintView::RedrawBackBuffer()
{
	Gdiplus::Graphics graphics(m_pBackBuffer.get());

	graphics.Clear(Gdiplus::Color::White);
	auto bound = GetContentBound();

	graphics.DrawImage(m_pBitmap.get(), bound.X, bound.Y, bound.Width, bound.Height);
}

Gdiplus::Rect CMiniPaintView::GetContentBound()
{
	CRect size;
	GetClientRect(&size);
	m_contentFitManager.CalculateContentBounds(size.Width(), size.Height());
	auto bounds = m_contentFitManager.GetContentBounds();

	return { bounds.x, bounds.y, bounds.width, bounds.height };
}

void CMiniPaintView::OnFileNew()
{
	CRect rcClient;
	GetClientRect(&rcClient);
	unsigned clientWidth = rcClient.Width();
	unsigned clientHeight = rcClient.Height();

	m_pBitmap.reset(new Gdiplus::Bitmap(clientWidth, clientHeight));
	Gdiplus::Graphics graphics(m_pBitmap.get());
	Gdiplus::Pen pen(Gdiplus::Color::Black);
	graphics.DrawRectangle(&pen, 20, 20, clientWidth - 20, clientHeight - 20);

	Invalidate();
	UpdateWindow();
}
