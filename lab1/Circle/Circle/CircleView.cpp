#include "pch.h"
#include "CircleView.h"

void CircleView::SetWidth(int width)
{
	m_width = width;
}

void CircleView::SetHeight(int height)
{
	m_height = height;
}

void CircleView::Draw(CPaintDC& dc, int centerX, int centerY, int radius, COLORREF borderColor, COLORREF fillColor)
{
	DrawBorder(dc, centerX, centerY, radius, borderColor);
	radius--;
	for (auto newRadius = radius; newRadius > 0; newRadius -= 1)
	{
		DrawBorder(dc, centerX, centerY, newRadius, fillColor);
	}
}

bool CircleView::InContainer(int x, int y) const
{
	return y <= m_height && y >= 0 && x <= m_width && x >= 0;
}

void CircleView::DrawBorder(CPaintDC& dc, int centerX, int centerY, int radius, COLORREF borderColor)
{
	int x = 0;
	int y = radius;
	int delta = 1 - 2 * radius;
	int error = 0;
	while (y >= x)
	{
		InContainer(centerX + x, centerY + y) && dc.SetPixel(centerX + x, centerY + y, borderColor);
		InContainer(centerX + x, centerY - y) && dc.SetPixel(centerX + x, centerY - y, borderColor);
		InContainer(centerX - x, centerY + y) && dc.SetPixel(centerX - x, centerY + y, borderColor);
		InContainer(centerX - x, centerY - y) && dc.SetPixel(centerX - x, centerY - y, borderColor);
		InContainer(centerX + y, centerY + x) && dc.SetPixel(centerX + y, centerY + x, borderColor);
		InContainer(centerX + y, centerY - x) && dc.SetPixel(centerX + y, centerY - x, borderColor);
		InContainer(centerX - y, centerY + x) && dc.SetPixel(centerX - y, centerY + x, borderColor);
		InContainer(centerX - y, centerY - x) && dc.SetPixel(centerX - y, centerY - x, borderColor);

		error = 2 * (delta + y) - 1;

		if (delta < 0 && error <= 0)
		{
			x++;
			delta += 2 * x + 1;
			continue;
		}
		if ((delta > 0) && (error > 0))
		{
			y--;
			delta -= 2 * y + 1;
			continue;
		}
		x++;
		y--;
		delta += 2 * (x - y);
	}
		
}
