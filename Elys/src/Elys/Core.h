#pragma once

#ifdef ELYS_PLATFORM_WINDOWS
	#ifdef ELYS_BUILD_DLL
		#define ELYS_API __declspec(dllexport)
	#else
		#define ELYS_API __declspec(dllimport)
	#endif
#else
	#error Elys only support Windows!
#endif // ELYS_PLATFORM_WINDOWS

#define BIT(x) (1 << x)