#include "pch.h"
#include "KIDD_WINDOW_MANAGER.h"
#include "KIDD_WIN_CLASSES/KIDD_FRAME_WIN.h"
#include "KIDD_WIN_CLASSES/KIDD_WINDOW_CONTROLS.h"
#include "KIDD_WIN_CLASSES/KIDD_OUTPUT_WIN.h"
#include "KIDD_WIN_CLASSES/KIDD_RENDER_WIN.h"



namespace KIDD_WINDOW
{
	KIDD_WINDOW_MANAGER::KIDD_WINDOW_MANAGER(HWND hWnd, HINSTANCE hInstance)
	{
		std::vector<std::unique_ptr<KIDD_ABSTRACT_WIN>> window;

		window.emplace_back(std::make_unique<KIDD_FRAME_WIN>(
			hWnd, hInstance, 0, 0, GetSystemMetrics(SM_CXSCREEN),
			GetSystemMetrics(SM_CYSCREEN), L"KIDD FRAME WINDOW"));

	}

}
