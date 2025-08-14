#include "pch.h"
#include "KIDD_WINDOW_CONTROLS.h"

namespace KIDD_WINDOW
{
	KIDD_WINDOW_CONTROLS::KIDD_WINDOW_CONTROLS(HWND parentHWND, HINSTANCE hInstance)
		:
		phWnd(parentHWND),
		hInstance(hInstance)
	{
	}

	HWND KIDD_WINDOW_CONTROLS::MakeButton(int id, const std::wstring& text, int x, int y, int width, int height, DWORD additionalStyles)
	{
		HWND hButton = CreateWindowExW(
			0,
			L"BUTTON", text.c_str(),
			WS_VISIBLE | WS_CHILD | BS_FLAT | additionalStyles,
			x, y, width, height,
			phWnd, reinterpret_cast<HMENU>(id), hInstance, NULL);
			
		SetWindowTheme(hButton, L"", L"");
		if (hButton)
		{
			controls[id] = hButton;
			SendMessageW(hButton, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);
		}
		return hButton;
	}

	HWND KIDD_WINDOW_CONTROLS::InitCustomButton(int id, const std::wstring& text, int x, int y, int width, int height)
	{
		return MakeButton(id, text, x, y, width, height, BS_OWNERDRAW);
	}

	bool KIDD_WINDOW_CONTROLS::InitCloseButton(int id, int width, int height)
	{
		RECT rc;
		GetClientRect(phWnd, &rc);

		HWND hBtn = MakeButton(id, L"X", rc.right - width, 0, width, height, BS_OWNERDRAW);
		return hBtn != NULL;
	}

	bool KIDD_WINDOW_CONTROLS::InitMinButton(int id, int width, int height)
	{
		RECT rc;
		GetClientRect(phWnd, &rc);

		HWND hBtn = MakeButton(id, L"_", rc.right - width * 3, 0, width, height, BS_OWNERDRAW);
		return hBtn != NULL;
	}

	bool KIDD_WINDOW_CONTROLS::InitMaxButton(int id, int width, int height)
	{
		RECT rc;
		GetClientRect(phWnd, &rc);

		HWND hBtn = MakeButton(id, L"[]", rc.right - width * 2, 0, width, height, BS_OWNERDRAW);
		return hBtn != NULL;
	}
	
	HWND KIDD_WINDOW_CONTROLS::GetControl(int id) const
	{
		auto it = controls.find(id);
		return it != controls.end() ? it->second : NULL;
	}

}

