#pragma once
#include "../KIDD_PCH//KIDD_ENGINE_MIN.h"
#include "KIDD_WIN_CLASSES/KIDD_ABSTRACT_WIN.h"
#include <vector>

namespace KIDD_WINDOW
{
	class ENGINE_UNIT_API KIDD_WINDOW_MANAGER
	{
	public:
		KIDD_WINDOW_MANAGER() = default;
		~KIDD_WINDOW_MANAGER() = default;
	
	public:
		void BuildWindowSkelet();

	private:
		std::vector<std::unique_ptr<KIDD_ABSTRACT_WIN>> window;
	};
}


