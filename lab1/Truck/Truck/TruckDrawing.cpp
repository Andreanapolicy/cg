#include "pch.h"
#include "TruckDrawing.h"

void TruckDrawing::Draw(CPaintDC& dc, const Point& point)
{
	CBrush brushFirst(RGB(0, 255, 0));
	CBrush brushSecond(RGB(255, 0, 0));
	CBrush brushThird(RGB(0, 0, 255));

	// Выбираем их в контекст устройства
	CBrush* pOldBrush = dc.SelectObject(&brushFirst);

	dc.SelectObject(pOldBrush);
}

void TruckDrawing::DrawCabin(CPaintDC& dc, const Point& point)
{
}

void TruckDrawing::DrawSemitrailer(CPaintDC& dc, const Point& point)
{
}

void TruckDrawing::DrawWheel(CPaintDC& dc, const Point& point)
{
}

void CTruckDlg::PaintLetterD(CPaintDC& dc, const Point& point)
{
	dc.Rectangle(100 + point.x, 50 + point.y, 110 + point.x, 100 + point.y);
	dc.Rectangle(110 + point.x, 50 + point.y, 150 + point.x, 60 + point.y);
	dc.Rectangle(150 + point.x, 50 + point.y, 160 + point.x, 100 + point.y);
	dc.Rectangle(90 + point.x, 100 + point.y, 170 + point.x, 110 + point.y);
	dc.Rectangle(90 + point.x, 100 + point.y, 100 + point.x, 140 + point.y);
	dc.Rectangle(160 + point.x, 100 + point.y, 170 + point.x, 140 + point.y);
}