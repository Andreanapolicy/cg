#include <tchar.h>
#include <windows.h>

int WINAPI WinMain(
	HINSTANCE /*hInstance*/,
	HINSTANCE /*hPrevInstance*/,
	LPSTR /*lpCmdLine*/,
	int /*nCmdShow*/)
{
	MessageBox(NULL, _T("Hello world"), _T("My first windows program"), MB_OK | MB_ICONINFORMATION);
	return 0;
}
