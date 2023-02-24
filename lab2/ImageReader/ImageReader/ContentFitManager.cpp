#include "pch.h"
#include "ContentFitManager.h"

void ContentFitManager::SetContentSize(int width, int height)
{
	m_originalWidth = width;
	m_originalHeight = height;
	m_coef = (double)m_originalWidth / (double)m_originalHeight;

	m_contentBounds.width = m_originalWidth;
	m_contentBounds.height = m_originalHeight;
}

void ContentFitManager::CalculateContentBounds(int boundWidth, int boundHeight)
{
	int windowWidth = boundWidth;
	int windowHeight = boundHeight;

	int contentWidth = m_contentBounds.width;
	int contentHeight = m_contentBounds.height;

	int x = (double)(windowWidth - contentWidth) / 2.0;
	int y = (double)(windowHeight - contentHeight) / 2.0;

	auto CalculateRelativeToHeight = [this, &contentHeight, &contentWidth, &windowHeight, &y]() {
		contentHeight = windowHeight;
		contentWidth = contentHeight * m_coef;
		y = 0;
	};

	auto CalculateRelativeToWidth = [this, &contentHeight, &contentWidth, &windowWidth, &x]() {
		contentWidth = windowWidth;
		contentHeight = contentWidth / m_coef;
		x = 0;
	};

	if (windowWidth < m_originalWidth && windowHeight >= m_originalHeight)
	{
		CalculateRelativeToWidth();
	}
	else if (windowHeight < m_originalHeight && windowWidth >= m_originalWidth)
	{
		CalculateRelativeToHeight();
	}
	else if (windowWidth < m_originalWidth && windowHeight < m_originalHeight)
	{
		if (min(windowWidth, windowHeight) == windowWidth)
		{
			if (contentWidth / m_coef <= windowHeight)
			{
				CalculateRelativeToWidth();
			}
			else
			{
				CalculateRelativeToHeight();
			}
		}
		else
		{
			if (windowHeight * m_coef > windowWidth)
			{
				CalculateRelativeToWidth();
			}
			else
			{
				CalculateRelativeToHeight();
			}
		}
	}
	else if (windowWidth >= m_originalWidth && windowHeight >= m_originalHeight)
	{
		contentWidth = m_originalWidth;
		contentHeight = m_originalHeight;
	}

	m_contentBounds = {x, y, contentWidth, contentHeight};
}

ContentBounds ContentFitManager::GetContentBounds() const
{
	return m_contentBounds;
}
