#pragma once

#include <memory>

#ifdef ELYS_PLATFORM_WINDOWS
#if ELYS_DYNAMIC_LINK
	#ifdef ELYS_BUILD_DLL
		#define Elys_API __declspec(dllexport)
	#else
		#define Elys_API __declspec(dllimport)
	#endif
#else
#define Elys_API
#endif
#else
	#error Elys only supports Windows!
#endif

#ifdef ELYS_DEBUG
	#define ELYS_ENABLE_ASSERTS
#endif

#ifdef ELYS_ENABLE_ASSERTS
	#define ELYS_ASSERT(x, ...) { if(!(x)) { ELYS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ELYS_CORE_ASSERT(x, ...) { if(!(x)) { ELYS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ELYS_ASSERT(x, ...)
	#define ELYS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define ELYS_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Elys {

	template<typename T>
	using Escope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;
}
