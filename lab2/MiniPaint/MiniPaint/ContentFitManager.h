#pragma once

struct ContentBounds
{
	int x;
	int y;
	int width;
	int height;
};

class ContentFitManager
{
public:
	ContentFitManager() = default;
	~ContentFitManager() = default;

	void SetContentSize(int width, int height);

	void CalculateContentBounds(int boundWidth, int boundHeight);

	ContentBounds GetContentBounds() const;

private:
	int m_originalWidth;
	int m_originalHeight;
	double m_coef;

	ContentBounds m_contentBounds;
};
