#include "pch.h"
#include "TruckDrawing.h"

void TruckDrawing::Draw(CPaintDC& dc, const Point& point)
{
	CBrush brushFirst(RGB(0, 255, 0));
	CBrush brushThird(RGB(0, 0, 255));

	DrawCabin(dc, {});
	DrawSemitrailer(dc, {});
	DrawWheel(dc, {});
	DrawWheel(dc, {});
	DrawWheel(dc, {});
	DrawWheel(dc, {});


	// Выбираем их в контекст устройства
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
	
	dc.SelectObject(pOldBrush);
}

void TruckDrawing::DrawSemitrailer(CPaintDC& dc, const Point& point)
{
}

void TruckDrawing::DrawWheel(CPaintDC& dc, const Point& point)
{
}
