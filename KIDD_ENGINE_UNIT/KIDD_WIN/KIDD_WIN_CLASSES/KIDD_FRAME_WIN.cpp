#include "pch.h"
#include "KIDD_FRAME_WIN.h"
#include "../KIDD_RESOURCES/resource.h"

#define IDC_CLOSEBTN    1001
#define IDC_MAXBTN      1002
#define IDC_MINBTN      1003

namespace KIDD_WINDOW
{
	KIDD_FRAME_WIN::KIDD_FRAME_WIN(LONG x, LONG y, LONG width, LONG height, const wchar_t* name)
		:
		KIDD_ABSTRACT_WIN(x, y, width, height, name),
		hInstance(GetModuleHandleW(TEXT(L"KIDD_ENGINE_UNIT.dll")))
	{
		recti.left = x;
		recti.top = y;
		recti.right = x + width;
		recti.bottom = y + height;

		WNDCLASSEXW wc = {};
		wc.cbSize = sizeof(wc);
		wc.style = CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = KIDD_ABSTRACT_WIN::MessageHandler;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = GetInstance();
		wc.hIcon = (HICON)LoadImageW(GetInstance(), MAKEINTRESOURCEW(IDI_ICON3), IMAGE_ICON, 32, 32, 0);
		wc.hCursor = (HCURSOR)LoadCursor(NULL, IDC_CROSS);
		wc.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(0, 0, 0)));
		wc.lpszMenuName = NULL;
		wc.lpszClassName = GetName();
		wc.hIconSm = (HICON)LoadImageW(GetInstance(), MAKEINTRESOURCEW(IDI_ICON2), IMAGE_ICON, 32, 32, 0);
	
		if (RegisterClassExW(&wc))
			std::wcout << L"FRAME WINDOW REGISTRATION : SUCCESS\n";
	}

	int KIDD_FRAME_WIN::Run()
	{
		while (IsInitialized())
		{
			if (const auto& e = WinLoop())
			{
				return *e;
			}
		}return 0;
	}

	void KIDD_FRAME_WIN::Init(COLORREF titleBarColor)
	{
		hWnd = CreateWindowExW(
			WS_EX_APPWINDOW,
			GetName(), L"KIDD_ENGINE_UNIT",
			WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
			recti.left, recti.top, recti.right - recti.left, recti.bottom - recti.top,
			nullptr, nullptr, GetInstance(), this);
        if (!hWnd)
            std::wcout << L"FRAME WINDOW CREATION : FAILED\n";
		else
			std::wcout << L"FRAME WINDOW CREATION: SUCCESS\n";

		DwmSetWindowAttribute(hWnd, DWMWA_CAPTION_COLOR, &titleBarColor, sizeof(titleBarColor));

        ShowWindow(hWnd, SW_SHOW);
        UpdateWindow(hWnd);
		init = true;
	}

	std::optional<int> KIDD_FRAME_WIN::WinLoop()
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

    LRESULT KIDD_FRAME_WIN::KIDD_WINDOW_PROC(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch (uMsg)
        {
			case WM_CLOSE:
			{
				PostQuitMessage(0);
				return 0;
			}
			case WM_DRAWITEM:
			{
				LPDRAWITEMSTRUCT pDraw = (LPDRAWITEMSTRUCT)lParam;
				HDC hdc = pDraw->hDC;
				RECT rc = pDraw->rcItem;

				HBRUSH bgBrush = CreateSolidBrush(GetTitleBarColor(hWnd));
				FillRect(hdc, &rc, bgBrush);
				DeleteObject(bgBrush);

				HPEN pen = CreatePen(PS_SOLID, 1, RGB(128, 144, 168));
				HPEN oldPen = (HPEN)SelectObject(hdc, pen);

				int cx = rc.right - rc.left;
				int cy = rc.bottom - rc.top;
				int centerX = rc.left + cx / 2;
				int centerY = rc.top + cy / 2;

				if (pDraw->CtlID == IDC_CLOSEBTN)
				{
					int x1 = centerX - 5;
					int y1 = centerY - 5;
					int x2 = centerX + 5;
					int y2 = centerY + 5;

					MoveToEx(hdc, x1, y1, NULL);
					LineTo(hdc, x2 + 1, y2 + 1);  

					MoveToEx(hdc, x2, y1, NULL);
					LineTo(hdc, x1 - 1, y2 + 1);
				}
				else if (pDraw->CtlID == IDC_MINBTN)
				{
					MoveToEx(hdc, centerX - 5, centerY + 3, NULL);
					LineTo(hdc, centerX + 5, centerY + 3);
				}
				else if (pDraw->CtlID == IDC_MAXBTN)
				{
					Rectangle(hdc, centerX - 5, centerY - 5, centerX + 5, centerY + 5);
				}

				SelectObject(hdc, oldPen);
				DeleteObject(pen);
				return TRUE;
			}
			case WM_COMMAND:
			{
				int id = LOWORD(wParam);
				if (id == IDC_CLOSEBTN) 
					SendMessage(hWnd, WM_CLOSE, 0, 0);
				
				else if (id == IDC_MAXBTN) 
					ShowWindow(hWnd, IsZoomed(hWnd) ? SW_RESTORE : SW_MAXIMIZE);
				
				else if (id == IDC_MINBTN) 
					ShowWindow(hWnd, SW_MINIMIZE);
				
				break;
			}
			case WM_PAINT:
			{
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hWnd, &ps);

				// DRAW TITLE BAR
				RECT titleBar = { recti.left, recti.top, recti.right - recti.left, recti.bottom - recti.top };
				FillRect(hdc, &titleBar, CreateSolidBrush(GetTitleBarColor(hWnd)));

				// DRAW TITLE
				SetBkMode(hdc, TRANSPARENT);
				SetTextColor(hdc, RGB(255, 255, 255));
				DrawTextW(hdc, L"KIDD ENGINE", -1, &titleBar, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

				// DRAW ICON
				DrawIconEx(hdc, 0, 0, (HICON)LoadImageW(GetInstance(), MAKEINTRESOURCEW(IDI_ICON3), IMAGE_ICON, 32, 32, 0), 32, 32, 0, NULL, DI_NORMAL);

				EndPaint(hWnd, &ps);
				break;
			}
			case WM_NCCALCSIZE:
			{
				if (wParam)
				{
					NCCALCSIZE_PARAMS* params = reinterpret_cast<NCCALCSIZE_PARAMS*>(lParam);
					params->rgrc[0].top += 1;
					params->rgrc[0].right -= 1;
					params->rgrc[0].bottom -= 1;
					params->rgrc[0].left += 1;
					return 0;
				}
				break;
			}
			default:
				return DefWindowProcW(hWnd, uMsg, wParam, lParam);
        }
        return 0;
    }
}

