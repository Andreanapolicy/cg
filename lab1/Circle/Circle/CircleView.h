#pragma once

class CircleView
{
public:
	CircleView(){};
	~CircleView() = default;

	void Draw(CPaintDC& dc, int centerX, int centerY, int radius, COLORREF borderColor, COLORREF fillColor);

private:
	void DrawBorder(CPaintDC& dc, int centerX, int centerY, int radius, COLORREF borderColor);
};
