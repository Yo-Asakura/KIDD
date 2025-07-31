#pragma once

#ifdef KIDD_ENGINE_UNIT_EXPORTS
#define ENGINE_UNIT_API __declspec(dllexport)
#else
#define ENGINE_UNIT_API __declspec(dllimport)
#endif // KIDD_ENGINE_UNIT
