#pragma once
#include "../../KIDD_PCH//KIDD_ENGINE_MIN.h"
#include "KIDD_ABSTRACT_WIN.h"

#define STRING_BUFFER_SIZE 1024
#define STRING_MAX_BUFFER_SIZE 16384

namespace KIDD_WINDOW
{
	class ENGINE_UNIT_API KIDD_OUTPUT_WIN : public KIDD_ABSTRACT_WIN
	{
	public:
		KIDD_OUTPUT_WIN(HWND parentHwnd, HINSTANCE hInstance);
		~KIDD_OUTPUT_WIN() = default;
	public:
		void IbitConsole(UINT startX, UINT startY);
		inline static const wchar_t* GetName()noexcept { return name; }

	private:
		LRESULT CALLBACK KIDD_WINDOW_PROC(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)override;
	private:

		static constexpr const wchar_t* name = L"KIDD_DEBUG_WINDOW";
		HWND chWnd;
		HINSTANCE chInstance;
		char* ioStream;
	};
}


   