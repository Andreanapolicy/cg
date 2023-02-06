#include "pch.h"
#include "TruckDrawing.h"

void TruckDrawing::Draw(CPaintDC& dc, const Point& point)
{
	CBrush brushFirst(RGB(0, 255, 0));
	CBrush brushThird(RGB(0, 0, 255));

	DrawSemitrailer(dc, point);
	DrawCabin(dc, point);

	CBrush* pOldBrush = dc.SelectObject(&brushFirst);

	dc.SelectObject(pOldBrush);
}

void TruckDrawing::DrawCabin(CPaintDC& dc, const Point& point)
{
	CBrush cabinBrush(RGB(192, 214, 228));

	auto pOldBrush = dc.SelectObject(&cabinBrush);
	dc.Rectangle(50 + point.x, 50 + point.y, 120 + point.x, 150 + point.y);
	dc.Rectangle(60 + point.x, 100 + point.y, 110 + point.x, 140 + point.y);
	
	CBrush windowBrush(RGB(250, 250, 250));
	pOldBrush = dc.SelectObject(&windowBrush);
	dc.Rectangle(60 + point.x, 55 + point.y, 110 + point.x, 100 + point.y);

	CBrush doorKnobBrush(RGB(0, 0, 0));
	pOldBrush = dc.SelectObject(&doorKnobBrush);
	dc.Rectangle(90 + point.x, 105 + point.y, 100 + point.x, 110 + point.y);

	CBrush platformBrush(RGB(137, 137, 137));
	pOldBrush = dc.SelectObject(&platformBrush);
	dc.Rectangle(120 + point.x, 130 + point.y, 340 + point.x, 150 + point.y);

	DrawWheel(dc, {point.x + 80, point.y + 120}, 30);
	DrawWheel(dc, {point.x + 200, point.y + 120}, 30);

	dc.SelectObject(pOldBrush);
}

void TruckDrawing::DrawSemitrailer(CPaintDC& dc, const Point& point)
{
	CBrush semitrailerBrush(RGB(234, 209, 220));

	auto pOldBrush = dc.SelectObject(&semitrailerBrush);
	dc.Rectangle(120 + point.x, 20 + point.y, 420 + point.x, 130 + point.y);
	DrawWheel(dc, { point.x + 350, point.y + 120 }, 30);

	dc.SelectObject(pOldBrush);
}

void TruckDrawing::DrawWheel(CPaintDC& dc, const Point& point, int radius)
{
	CBrush tireBrush(RGB(81, 81, 81));
	auto pOldBrush = dc.SelectObject(&tireBrush);
	dc.Ellipse(0 + point.x, 0 + point.y, radius * 2 + point.x, radius * 2 + point.y);

	CBrush disksBrush(RGB(237, 237, 237));
	pOldBrush = dc.SelectObject(&disksBrush);
	dc.Ellipse(radius / 2 + point.x, radius / 2 + point.y, radius * 3 / 2 + point.x, radius * 3 / 2 + point.y);

	dc.SelectObject(pOldBrush);
}
