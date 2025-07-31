#include "pch.h"
#include "KIDD_MAIN_WIN.h"
#include "../KIDD_RESOURCES/resource.h"

namespace KIDD_WINDOW
{
	KIDD_MAIN_WIN::KIDD_MAIN_WIN()
		:
		hInstance(GetModuleHandleW(TEXT(L"KIDD_ENGINE_UNIT.dll")))
	{
		width = GetSystemMetrics(SM_CXSCREEN);
		height = GetSystemMetrics(SM_CYSCREEN);

		WNDCLASSEXW wc = {};
		wc.cbSize = sizeof(wc);
		wc.style = CS_OWNDC;
		wc.lpfnWndProc = KIDD_ABSTRACT_WIN::MessageHandler;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = GetInstance();
		wc.hIcon = (HICON)LoadImageW(GetInstance(), MAKEINTRESOURCEW(IDI_ICON1), IMAGE_ICON, 32, 32, 0);
		wc.hCursor = (HCURSOR)LoadCursor(NULL, IDC_CROSS);
		wc.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(0, 0, 0)));
		wc.lpszMenuName = NULL;
		wc.lpszClassName = GetName();
		wc.hIconSm = (HICON)LoadImageW(GetInstance(), MAKEINTRESOURCEW(IDI_ICON1), IMAGE_ICON, 32, 32, 0);
	
		if (RegisterClassExW(&wc))
			std::wcout << L"CLASS REGISTRATION : SUCCESS\n";
	}

	int KIDD_MAIN_WIN::Run()
	{
		while (IsInitialized())
		{
			if (const auto& e = WinLoop())
			{
				return *e;
			}
		}return 0;
	}

	void KIDD_MAIN_WIN::Init()
	{
		RECT recti = {};
		recti.left = 150;
		recti.top = 150;
		recti.right = recti.left + width;
		recti.bottom = recti.top + height;

		hWnd = CreateWindowExW(
			0,
			GetName(), L"KIDD_ENGINE_UNIT",
			WS_OVERLAPPEDWINDOW,
			recti.left, recti.top, recti.right, recti.bottom,
			nullptr, nullptr, GetInstance(), this);

		HMONITOR monitor = MonitorFromWindow(hWnd, MONITOR_DEFAULTTONEAREST);
		MONITORINFO mi = { sizeof(mi) };
		if (GetMonitorInfo(monitor, &mi)) {
			int width = mi.rcMonitor.right - mi.rcMonitor.left;
			int height = mi.rcMonitor.bottom - mi.rcMonitor.top;
			SetWindowPos(hWnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, width, height, SWP_NOZORDER | SWP_FRAMECHANGED);
		}

		if (hWnd)
		{
			std::wcout << L"WINDOW CREATION : SUCCESS\n";
			init = true;
			ShowWindow(hWnd, SW_SHOW);
		}
	}

	std::optional<int> KIDD_MAIN_WIN::WinLoop()
	{
		MSG msg = { 0 };
		while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				return (int)msg.wParam;
			}
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
		return {};
	}

	LRESULT KIDD_MAIN_WIN::KIDD_WINDOW_PROC(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_CLOSE:
			PostQuitMessage(0);
			return 0;
		default:
			return DefWindowProcW(hWnd, uMsg, wParam, lParam);
		}
	}
}