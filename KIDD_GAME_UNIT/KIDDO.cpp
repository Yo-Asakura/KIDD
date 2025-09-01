#pragma once
#include "../KIDD_ENGINE_UNIT/KIDD_WIN/KIDD_WINDOW_MANAGER.h"

HWND hWnd;
HINSTANCE hInstance;


int main()
{
	using namespace KIDD_WINDOW;
	
	KIDD_WINDOW_MANAGER KIDDO(hWnd, hInstance);
	
	return 0;
}