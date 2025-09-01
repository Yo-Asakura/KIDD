#pragma once
#include "../../KIDD_PCH//KIDD_ENGINE_MIN.h"
#include "KIDD_ABSTRACT_WIN.h"
#include <optional>
#include <memory>

namespace KIDD_WINDOW
{
	class ENGINE_UNIT_API KIDD_FRAME_WIN : public KIDD_ABSTRACT_WIN
	{
	public:
		KIDD_FRAME_WIN(HWND hWnd, HINSTANCE hInstance, LONG x, LONG y, LONG width, LONG height, const wchar_t* name);
		~KIDD_FRAME_WIN() = default;

	public:
		int Run();// FOR NOW
		void Init(COLORREF titleBarColor);
		inline bool IsInitialized()const noexcept { return init; };

	// GETTERS
	public:
		inline HINSTANCE GetInstance()const noexcept { return hInstance; }
		inline HWND GetHWND()const noexcept { return hWnd; }
	protected:
		std::optional<int> WinLoop();

	private:
		inline COLORREF GetTitleBarColor(HWND hWnd)const noexcept { return (COLORREF)GetWindowLongPtrW(hWnd, GWLP_USERDATA); };
		LRESULT CALLBACK KIDD_WINDOW_PROC(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)override;
	
	private:
		HINSTANCE hInstance{ nullptr };
		HWND hWnd{ nullptr };
		bool init{ false };
	};
}