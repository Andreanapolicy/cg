#pragma once
#include "Point.h"

class TruckDrawing
{
public:
	TruckDrawing() {};
	~TruckDrawing() {};

	void Draw(CPaintDC& dc, const Point& point);

private:
	void DrawRoad(CPaintDC& dc, const Point& point);
	void DrawCabin(CPaintDC& dc, const Point& point);
	void DrawSemitrailer(CPaintDC& dc, const Point& point);
	void DrawWheel(CPaintDC& dc, const Point& point, int radius);

};
