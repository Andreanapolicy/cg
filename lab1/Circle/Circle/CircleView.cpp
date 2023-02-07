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
	int x1 = 0;
	int y1 = radius;
	int yk = 0;
	int sigma = 0;
	int delta = 2 * (1 - radius);
	int f = 0;

	do
	{
		InContainer(centerX + x1, centerY + y1) && dc.SetPixel(centerX + x1, centerY + y1, borderColor);
		InContainer(centerX - x1, centerY + y1) && dc.SetPixel(centerX - x1, centerY + y1, borderColor);
		InContainer(centerX + x1, centerY - y1) && dc.SetPixel(centerX + x1, centerY - y1, borderColor);
		InContainer(centerX - x1, centerY - y1) && dc.SetPixel(centerX - x1, centerY - y1, borderColor);

		f = 0;
		if (y1 < yk)
		{
			break;
		}
		if (delta < 0)
		{
			sigma = 2 * (delta + y1) - 1;

			if (sigma <= 0)
			{
				x1++;
				delta += 2 * x1 + 1;
				f = 1;
			}
		}
		else if (delta > 0)
		{
			sigma = 2 * (delta - x1) - 1;
			if (sigma > 0)
			{
				y1--;
				delta += 1 - 2 * y1;
				f = 1;
			}
		}
		if (!f)
		{
			x1++;
			y1--;
			delta += 2 * (x1 - y1 - 1);
		}

	} while (1);
}
