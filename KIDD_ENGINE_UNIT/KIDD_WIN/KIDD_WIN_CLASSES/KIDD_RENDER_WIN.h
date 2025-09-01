#pragma once
#include "../../KIDD_PCH//KIDD_ENGINE_MIN.h"
#include "KIDD_ABSTRACT_WIN.h"

namespace KIDD_WINDOW
{
	class ENGINE_UNIT_API KIDD_RENDER_WIN : public KIDD_ABSTRACT_WIN
	{
	public:
		KIDD_RENDER_WIN(HWND hWnd, HINSTANCE hInstance, LONG x, LONG y, LONG width, LONG height, const wchar_t* name = L"KIDD_RENDER_WINDOW");
		~KIDD_RENDER_WIN() = default;

	public:
		void InitRenderWindow();

	private:
		LRESULT CALLBACK KIDD_WINDOW_PROC(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)override;

	private:
		HWND hRWnd;
		HINSTANCE hRInstance;
	};
}


