#pragma once
#include "../KIDD_ENGINE_UNIT/KIDD_WIN/KIDD_WIN_CLASSES/KIDD_FRAME_WIN.h"

int main()
{
	using namespace KIDD_WINDOW;
	
	KIDD_FRAME_WIN KIDDO;
	KIDDO.Init();
	if (KIDDO.IsInitialized())
	{
		KIDDO.Run();
	}

	return 0;
}