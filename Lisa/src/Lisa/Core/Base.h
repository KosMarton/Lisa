#pragma once

#include <memory>

#include "Lisa/Core/PlatformDetection.h"

#ifdef LS_DEBUG
	#if defined(LS_PLATFORM_WINDOWS)
		#define LS_DEBUGBREAK() __debugbreak()
	#elif defined(LS_PLATFORM_LINUX)
		#include <signal.h>
		#define LS_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define LS_ENABLE_ASSERTS
#else
	#define LS_DEBUGBREAK()
#endif

#ifdef LS_ENABLE_ASSERTS
	#define LS_ASSERT(x, ...) { if(!(x)) { LS_ERROR("Assertion failed: {0}", __VA_ARGS__); LS_DEBUGBREAK(); } }
	#define LS_CORE_ASSERT(x, ...) { if(!(x)) { LS_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); LS_DEBUGBREAK(); } }
#else
	#define LS_ASSERT(x, ...)
	#define LS_CORE_ASSERT(x, ...)
#endif
 
#define BIT(x) (1 << x)

#define LS_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Lisa {

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