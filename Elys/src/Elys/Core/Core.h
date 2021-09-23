#pragma once

#include <memory>

#include "Elys/Core/PlatformDetection.h"

// DLL support
#ifdef ELYS_PLATFORM_WINDOWS
	#if ELYS_DYNAMIC_LINK
		#ifdef ELYS_BUILD_DLL
			#define ELYS_API __declspec(dllexport)
		#else
			#define ELYS_API __declspec(dllimport)
		#endif
	#else
		#define ELYS_API
	#endif
#else
	#error Elys only supports Windows!
#endif // End of DLL support

#ifdef ELYS_DEBUG
	#if defined(ELYS_PLATFORM_WINDOWS)
		#define ELYS_DEBUGBREAK() __debugbreak()
	#elif defined(ELYS_PLATFORM_LINUX)
		#include <signal.h>
		#define ELYS_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define ELYS_ENABLE_ASSERTS
#else
#define ELYS_DEBUGBREAK()
#endif

#ifdef ELYS_ENABLE_ASSERTS
	#define ELYS_ASSERT(x, ...) { if(!(x)) { ELYS_ERROR("Assertion Failed: {0}", __VA_ARGS__); ELYS_DEBUGBREAK(); } }
	#define ELYS_CORE_ASSERT(x, ...) { if(!(x)) { ELYS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); ELYS_DEBUGBREAK(); } }
#else
	#define ELYS_ASSERT(x, ...)
	#define ELYS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define PI (3.14159265358979323846264338327950288)

#define ELYS_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Elys {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}
