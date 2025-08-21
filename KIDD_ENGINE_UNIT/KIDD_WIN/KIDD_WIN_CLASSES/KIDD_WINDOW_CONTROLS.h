#pragma once
#include "../KIDD_PCH/KIDD_ENGINE_MIN.h"
#include <string>
#include <vector>
#include <unordered_map>

namespace KIDD_WINDOW
{
	class ENGINE_UNIT_API KIDD_WINDOW_CONTROLS
	{
	public:
		KIDD_WINDOW_CONTROLS(HWND parentHWND, HINSTANCE hInstance);
		~KIDD_WINDOW_CONTROLS() = default;
	private:
		HWND MakeButton(int id, const std::wstring& text, int x, int y, int width, int height, DWORD additionalStyles = 0);
	public:
		HWND InitCustomButton(int id, const std::wstring& text, int x, int y, int width, int height);
		bool InitCloseButton(int id, int width = 45, int height = 30);
		bool InitMinButton(int id, int width = 45, int height = 30);
		bool InitMaxButton(int id, int width = 45, int height = 30);
		HWND GetControl(int id)const;
	private:
		HWND phWnd;
		HINSTANCE hInstance;
		std::unordered_map<int, HWND>controls;

	};
}



