#pragma once
#include "../../KIDD_PCH//KIDD_ENGINE_MIN.h"
#include <Windows.h>


namespace KIDD_WINDOW
{
	class ENGINE_UNIT_API KIDD_ABSTRACT_WIN
	{
	public:
		KIDD_ABSTRACT_WIN(LONG x, LONG y, LONG width, LONG height, const wchar_t* name);
		virtual ~KIDD_ABSTRACT_WIN() = default;

	// GETTERS
	public:
		inline const wchar_t* GetName()const noexcept { return kName; }
		inline const LONG GetWinWidth()const noexcept { return kWidth; }
		inline const LONG GetWinHeight()const noexcept { return kHeight; }
		inline const LONG GetWinXStartPos()const noexcept { return xPos; }
		inline const LONG GetWinYStartPos()const noexcept { return yPos; }

	// SETTERS
	public:
		inline void SetWindName(const wchar_t* name)noexcept;
		inline void SetWinWidth(const LONG width)noexcept;
		inline void SetWinHeight(const LONG height)noexcept;
		inline void SetWinXStartPos(const LONG xpos)noexcept;
		inline void SetWinYStartPos(const LONG ypos)noexcept;

	protected:
		virtual LRESULT CALLBACK KIDD_WINDOW_PROC(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
		static LRESULT CALLBACK MessageHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK MessageThunk(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	private:			
		const wchar_t* kName = L"ABSTRACT WIN";
		LONG kWidth;
		LONG kHeight;
		LONG xPos;
		LONG yPos;
	};
}
