#pragma once
#include "KIDD_ABSTRACT_WIN.h"
#include "../PCH_FILES/KIDD_ENGINE_MIN.h"
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
		inline HINSTANCE GetInstance()const noexcept { return hInstance; }
		inline static const wchar_t* GetName()noexcept { return name; }
		inline bool IsInitialized()const noexcept { return init; };

	protected:
		std::optional<int> WinLoop();

	private:
		LRESULT CALLBACK KIDD_WINDOW_PROC(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)override;
	
	private:
		static constexpr const wchar_t* name = L"KIDD_JOLLY_WINDOW";
		HINSTANCE hInstance;
		HWND hWnd;
		UINT width;
		UINT height;
		bool init{ false };
	};
}