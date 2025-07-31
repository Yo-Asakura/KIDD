#include "pch.h"
#include "KIDD_ABSTRACT_WIN.h"

namespace KIDD_WINDOW
{
	LRESULT KIDD_ABSTRACT_WIN::MessageHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		if (uMsg == WM_NCCREATE) // Message WM_NCCREATE is sent before a window is actually created
		{
			const CREATESTRUCTW* const kk = reinterpret_cast<CREATESTRUCTW*>(lParam); // casting lParam, which contains pointer to bigger data, in that case we can shell out a CREATESTRUCTW, which will be crussial later
			KIDD_ABSTRACT_WIN* kw = reinterpret_cast<KIDD_ABSTRACT_WIN*>(kk->lpCreateParams); // now the goal is to load lpCreateParams from CREATESTRUCTW structure, becouse it holds a pointer(this) to object that creates window 
			SetWindowLongPtrW(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(kw)); // safe this, to GWLP_USERDATA(at this momentthis is empty), so we can assign a value later on i MessageThunk 
			SetWindowLongPtrW(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&MessageThunk)); // change a windowproc, so what is going on right now is we are stepping into a MessageThunk Function, 
			return kw->KIDD_WINDOW_PROC(hWnd, uMsg, wParam, lParam); // return abs windproc
		}
		return DefWindowProcW(hWnd, uMsg, wParam, lParam);
	}

	LRESULT KIDD_ABSTRACT_WIN::MessageThunk(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		KIDD_ABSTRACT_WIN* const kw = reinterpret_cast<KIDD_ABSTRACT_WIN*>(GetWindowLongPtrW(hWnd, GWLP_USERDATA)); // assign this(which is finally different than nullptr) to a ABSTRACT window class, can be easily acces due to poli
		return kw->KIDD_WINDOW_PROC(hWnd, uMsg, wParam, lParam); // redirect to class window proc
	}
}