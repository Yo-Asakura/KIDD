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
		KIDD_OUTPUT_WIN(HWND hWnd, HINSTANCE hInstance, LONG x, LONG y, LONG width, LONG height, const wchar_t* name);
		~KIDD_OUTPUT_WIN() = default;
	public:
		void InitConsole();
	private:
		LRESULT CALLBACK KIDD_WINDOW_PROC(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)override;
	private:
		HWND chWnd;
		HINSTANCE chInstance;
		char* ioStream;
	};
}


   