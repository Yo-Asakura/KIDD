#pragma once
#include "../KIDD_PCH/KIDD_ENGINE_MIN.h"
#include "KIDD_ABSTRACT_WIN.h"
#include "KIDD_WINDOW_CONTROLS.h"
#include "KIDD_RENDER_WIN.h"
#include <optional>
#include <memory>

namespace KIDD_WINDOW
{
	class ENGINE_UNIT_API KIDD_MAIN_WIN : public KIDD_ABSTRACT_WIN
	{
	public:
		KIDD_MAIN_WIN();
		~KIDD_MAIN_WIN() = default;

	public:
		int Run();// FOR NOW
		void Init();
		inline bool IsInitialized()const noexcept { return init; };

	// GETTERS
	public:
		inline HINSTANCE GetInstance()const noexcept { return hInstance; }
		inline static const wchar_t* GetName()noexcept { return name; }
		inline HWND GetHWND()const noexcept { return hWnd; }
	protected:
		std::optional<int> WinLoop();

	private:
		LRESULT CALLBACK KIDD_WINDOW_PROC(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)override;
	
	private:
		std::unique_ptr<KIDD_RENDER_WIN> kRenderWin;
		std::unique_ptr<KIDD_WINDOW_CONTROLS> kControls;
		RECT recti{};
		static constexpr const wchar_t* name = L"KIDD_JOLLY_WINDOW";
		HINSTANCE hInstance;
		HWND hWnd;
		COLORREF titleBarColor = RGB(20, 20, 25);
		LONG width;
		LONG height;
		LONG tbYEnd{ 30 };
		bool init{ false };
	};
}