#include "pch.h"
#include "KIDD_RENDER_WIN.h"


namespace KIDD_WINDOW
{
	KIDD_RENDER_WIN::KIDD_RENDER_WIN(HWND hWnd, HINSTANCE hInstance, LONG x, LONG y, LONG width, LONG height, const wchar_t* name)
		:
		KIDD_ABSTRACT_WIN(hWnd, hInstance, x, y, width, height, name)
	{
		WNDCLASSEXW wc = {};
		wc.cbSize = sizeof(wc);
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpfnWndProc = DefWindowProcW;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = hRInstance;
		wc.lpszMenuName = NULL;
		wc.lpszClassName = KIDD_ABSTRACT_WIN::GetName();
		wc.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(128, 128, 128)));

		if (RegisterClassExW(&wc))
			std::wcout << L"RENDER WINDOW REGISTRATION : SUCCESS\n";
		else
			std::wcout << L"RENDER WINDOW REGISTRATION : FAILED\n";
	}

	void KIDD_RENDER_WIN::InitRenderWindow()
	{
		hRWnd = CreateWindowExW(
			0,
			KIDD_ABSTRACT_WIN::GetName(), L"KIDDO",
			WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
			KIDD_ABSTRACT_WIN::GetRectXPos(), KIDD_ABSTRACT_WIN::GetRectYPos(),
			KIDD_ABSTRACT_WIN::GetRectWidth() - KIDD_ABSTRACT_WIN::GetRectXPos(),
			KIDD_ABSTRACT_WIN::GetRectHeight() - KIDD_ABSTRACT_WIN::GetRectYPos(),
			hRWnd, nullptr, hRInstance, this);
		if (!hRWnd)
			std::wcout << L"KIDD RENDER WINDOW CREATION: FAILED\n";
		else
			std::wcout << L"RENDER WINDOW CREATION: SUCCESS\n";

		ShowWindow(hRWnd, SW_SHOW);
		UpdateWindow(hRWnd);
		
	}

	LRESULT KIDD_RENDER_WIN::KIDD_WINDOW_PROC(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		default:
			return DefWindowProcW(hWnd, uMsg, wParam, lParam);
		}
	}

}