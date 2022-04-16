#pragma once

#include <windows.h>

std::shared_ptr<IShape> SetLetterD(Color color, PointD bias);
std::shared_ptr<IShape> SetLetterA(Color color, PointD bias);
std::shared_ptr<CSlide> CreateSlide();

LRESULT CALLBACK WindowProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_QUIT:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}

bool RegisterWndClass(HINSTANCE hInstance)
{
	WNDCLASSEX wndClass = {
		sizeof(wndClass),
		CS_HREDRAW | CS_VREDRAW,
		&WindowProc,
		0,
		0,
		hInstance,
		NULL,
		LoadCursor(NULL, IDC_ARROW),
		reinterpret_cast<HBRUSH>(COLOR_WINDOW),
		NULL,
		L"title",
		NULL,
	};

	return RegisterClassEx(&wndClass) != FALSE;
}

HWND CreateMainWindow(HINSTANCE hInstance)
{
	HWND hMainWindow = CreateWindowEx(
		0,
		L"title",
		L"Initials",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		nullptr,
		NULL,
		hInstance,
		NULL);

	return hMainWindow;
}