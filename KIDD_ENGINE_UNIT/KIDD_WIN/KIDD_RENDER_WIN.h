#pragma once
#include "../KIDD_PCH/KIDD_ENGINE_MIN.h"

namespace KIDD_WINDOW
{
	class ENGINE_UNIT_API KIDD_RENDER_WIN
	{
	public:
		KIDD_RENDER_WIN(HWND parentHwnd, HINSTANCE hInstance);
		~KIDD_RENDER_WIN() = default;

	public:
		void InitRenderWindow(UINT startX, UINT startY);
		inline static const wchar_t* GetName()noexcept { return name; }

	public:
		LRESULT RenderProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	private:
		static constexpr const wchar_t* name = L"KIDD_RENDER_WINDOW";
		HWND hRWnd;
		HINSTANCE hRInstance;
		UINT width{ 1400 };
		UINT height{ 700 };
		UINT xStart{ 0 };
		UINT yStart{ 30 };
	};
}


