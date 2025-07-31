#pragma once
#include <Windows.h>
#include "../KIDD_PCH/KIDD_ENGINE_MIN.h"

namespace KIDD_WINDOW
{
	class ENGINE_UNIT_API KIDD_ABSTRACT_WIN
	{
	public:
		KIDD_ABSTRACT_WIN() = default;
		virtual ~KIDD_ABSTRACT_WIN() = default;

	protected:
		virtual LRESULT CALLBACK KIDD_WINDOW_PROC(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
		static LRESULT CALLBACK MessageHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK MessageThunk(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	};
}
