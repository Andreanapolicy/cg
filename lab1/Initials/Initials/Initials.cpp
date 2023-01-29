#include <windows.h>
#include <windowsx.h>
#include <tchar.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
bool RegisterWndClass(HINSTANCE hInstance);
HWND CreateMainWindow(HINSTANCE hInstance);
void OnDestroy(HWND hwnd);
void OnPaint(HWND hwnd);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
	if (!RegisterWndClass(hInstance))
	{
		return 1;
	}

	// Создаем главное окно приложения
	HWND hMainWindow = CreateMainWindow(hInstance);
	if (hMainWindow == NULL)
	{
		return 1;
	}

	// Показываем главное окно приложения
	ShowWindow(hMainWindow, nCmdShow);
	UpdateWindow(hMainWindow);

	return 0;
}

HWND CreateMainWindow(HINSTANCE hInstance)
{
	HWND hMainWindow = CreateWindowEx(
		0, // DWORD dwExStyle;
		L"Initials class",
		L"Initials",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		nullptr,
		NULL,
		hInstance,
		NULL
	);

	return hMainWindow;
}

LRESULT CALLBACK WindowProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (uMsg)
	{
		HANDLE_MSG(hwnd, WM_DESTROY, OnDestroy);
		HANDLE_MSG(hwnd, WM_PAINT, OnPaint);
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}
// GDI / GDI+
// использовать матрицу для отрисовки букв(задаем матрицу для сдвига букв перед рисованием, тем самым мы можем управлять положением буквы не изменяя положения в коде) 
// какие событие обрабатывает SFML

bool RegisterWndClass(HINSTANCE hInstance)
{
	WNDCLASSEX wndClass = {
		sizeof(wndClass), // UINT cbSize;
		CS_HREDRAW | CS_VREDRAW, // UINT style;
		&WindowProc, // WNDPROC lpfnWndProc;
		0, // int cbClsExtra;
		0, // int cbWndExtra;
		hInstance, // HINSTANCE hInstance;
		NULL, // HICON hIcon;
		LoadCursor(NULL, IDC_ARROW), // HCURSOR hCursor;
		reinterpret_cast<HBRUSH>(COLOR_WINDOW), // HBRUSH hbrBackground;
		NULL, // LPCTSTR lpszMenuName;
		L"Initials class",
		NULL, // HICON hIconSm;
	};

	return RegisterClassEx(&wndClass) != FALSE;
}

void OnDestroy(HWND /*hwnd*/)
{
	PostQuitMessage(0);
}

void OnPaint(HWND hwnd)
{
	PAINTSTRUCT ps;
	HDC dc = BeginPaint(hwnd, &ps);
	Ellipse(dc, 100, 50, 250, 150);
	EndPaint(hwnd, &ps);
}