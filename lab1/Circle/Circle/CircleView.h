#pragma once

class CircleView
{
public:
	CircleView(int width = 0, int height = 0)
		: m_width(width)
		, m_height(height)
	{};

	~CircleView() = default;

	void SetWidth(int width);
	void SetHeight(int height);
	void Draw(CPaintDC& dc, int centerX, int centerY, int radius, COLORREF borderColor, COLORREF fillColor);

private:
	bool InContainer(int x, int y) const;
	void DrawBorder(CPaintDC& dc, int centerX, int centerY, int radius, COLORREF borderColor);
	
	int m_width;
	int m_height;
};
