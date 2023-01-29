#include <windows.h>
#include <windowsx.h>
#include <tchar.h>

struct Point
{
	int x = 0;
	int y = 0;
};

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
bool RegisterWndClass(HINSTANCE hInstance);
HWND CreateMainWindow(HINSTANCE hInstance);
void OnDestroy(HWND hwnd);
void OnPaint(HWND hwnd);
int MainLoop();
void PaintLetterD(HDC dc, const Point& point);
void PaintLetterA(HDC dc, const Point& point);

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

	return MainLoop();
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
	PaintLetterD(dc, { 100, 100 });
	PaintLetterA(dc, { 200, 100 });
	PaintLetterA(dc, { 300, 100 });
	EndPaint(hwnd, &ps);
}

int MainLoop()
{
	MSG message;
	BOOL result;
	while ((result = GetMessage(&message, NULL, 0, 0)) != 0)
	{
		if (result == -1)
		{
			break;
		}
		
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}

void PaintLetterD(HDC dc, const Point& point)
{
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); 

	LOGBRUSH brushInfo; 

	brushInfo.lbStyle = BS_SOLID; 
	brushInfo.lbColor = RGB(255, 255, 0); 
	brushInfo.lbHatch = 0; 

	HBRUSH brush = CreateBrushIndirect(&brushInfo); 
	HPEN oldPen = SelectPen(dc, pen); 

	HBRUSH oldBrush = SelectBrush(dc, brush); 
	
	Rectangle(dc, 100 + point.x, 50 + point.y, 110 + point.x, 100 + point.y);
	Rectangle(dc, 110 + point.x, 50 + point.y, 150 + point.x, 60 + point.y);
	Rectangle(dc, 150 + point.x, 50 + point.y, 160 + point.x, 100 + point.y);
	Rectangle(dc, 90 + point.x, 100 + point.y, 170 + point.x, 110 + point.y);

	Rectangle(dc, 90 + point.x, 100 + point.y, 100 + point.x, 140 + point.y);
	Rectangle(dc, 160 + point.x, 100 + point.y, 170 + point.x, 140 + point.y);


}

void PaintLetterA(HDC dc, const Point& point)
{
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); 

	LOGBRUSH brushInfo; 

	brushInfo.lbStyle = BS_SOLID; 
	brushInfo.lbColor = RGB(255, 0, 255);
	brushInfo.lbHatch = 0; 

	HBRUSH brush = CreateBrushIndirect(&brushInfo); 
	HPEN oldPen = SelectPen(dc, pen); 

	HBRUSH oldBrush = SelectBrush(dc, brush); 
	Rectangle(dc, 100 + point.x, 50 + point.y, 110 + point.x, 160 + point.y);
	Rectangle(dc, 110 + point.x, 50 + point.y, 150 + point.x, 60 + point.y);
	Rectangle(dc, 150 + point.x, 50 + point.y, 160 + point.x, 160 + point.y);
	Rectangle(dc, 100 + point.x, 100 + point.y, 160 + point.x, 110 + point.y);
}