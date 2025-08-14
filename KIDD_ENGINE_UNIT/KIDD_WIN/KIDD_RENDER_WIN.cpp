#include "pch.h"
#include "KIDD_RENDER_WIN.h"


namespace KIDD_WINDOW
{
	KIDD_RENDER_WIN::KIDD_RENDER_WIN(HWND parentHwnd, HINSTANCE hInstance)
		:
		hRWnd(parentHwnd),
		hRInstance(hInstance)
	{
		WNDCLASSEXW wc = {};
		wc.cbSize = sizeof(wc);
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpfnWndProc = DefWindowProcW;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = hRInstance;
		wc.lpszMenuName = NULL;
		wc.lpszClassName = GetName();
		wc.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(128, 128, 128)));

		if (RegisterClassExW(&wc))
			std::wcout << L"RENDER WINDOW REGISTRATION : SUCCESS\n";
		else
			std::wcout << L"RENDER WINDOW REGISTRATION : FAILED\n";
	}

	void KIDD_RENDER_WIN::InitRenderWindow(UINT startX, UINT startY)
	{
		xStart = startX;
		yStart = startY;

		hRWnd = CreateWindowExW(
			0,
			GetName(), L"KIDDO",
			WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
			xStart, yStart, width, height,
			hRWnd, nullptr, hRInstance, this);
		if (!hRWnd)
			std::wcout << L"KIDD RENDER WINDOW CREATION: FAILED\n";
		else
			std::wcout << L"RENDER WINDOW CREATION: SUCCESS\n";

		ShowWindow(hRWnd, SW_SHOW);
		UpdateWindow(hRWnd);
		
	}

	LRESULT KIDD_RENDER_WIN::RenderProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		default:
			return DefWindowProcW(hWnd, uMsg, wParam, lParam);
		}
	}

}