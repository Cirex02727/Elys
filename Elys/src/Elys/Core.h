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

#ifdef ELYS_ENABLE_ASSERTS
	#define ELYS_ASSERT(x, ...) { if(!(x)) { ELYS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ELYS_CORE_ASSERT(x, ...) { if(!(x)) { ELYS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ELYS_ASSERT(x, ...)
	#define ELYS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)