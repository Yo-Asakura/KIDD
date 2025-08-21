#include "pch.h"
#include "KIDD_OUTPUT_WIN.h"

namespace KIDD_WINDOW
{
	KIDD_OUTPUT_WIN::KIDD_OUTPUT_WIN(HWND parentHwnd, HINSTANCE hInstance)
		:
		chWnd(parentHwnd),
		chInstance(hInstance)
	{
		WNDCLASSEXW wc = {};
		wc.cbSize = sizeof(wc);
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpfnWndProc = KIDD_ABSTRACT_WIN::MessageHandler;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = chInstance;
		wc.lpszMenuName = NULL;
		wc.lpszClassName = GetName();
		wc.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(128, 128, 128)));

		if (RegisterClassExW(&wc))
			std::wcout << L"DEBUG WINDOW REGISTRATION : SUCCESS\n";
		else
			std::wcout << L"DEBUG WINDOW REGISTRATION : FAILED\n";
	}

	void KIDD_OUTPUT_WIN::IbitConsole(UINT startX, UINT startY)
	{



	}

	LRESULT KIDD_OUTPUT_WIN::KIDD_WINDOW_PROC(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{

		default:
			return DefWindowProcW(hWnd, uMsg, wParam, lParam);
		}
	}

	

}
