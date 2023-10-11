#pragma once

#ifdef EMERALD_PLATFORM_WINDOWS
	#ifdef EMERALD_BUILD_DLL
		#define EMERALD_API __declspec(dllexport)
	#else
		#define EMERALD_API __declspec(dllimport)
	#endif
#else
	#error Emerald only supports Windows!
#endif