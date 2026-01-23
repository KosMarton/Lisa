#pragma once

#include "Lisa/Core/Base.h"
#include "Lisa/Core/Log.h"
#include <filesystem>

#ifdef LS_ENABLE_ASSERTS

	#define LS_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { LS##type##ERROR(msg, __VA_ARGS__); LS_DEBUGBREAK(); } }
	#define LS_INTERNAL_ASSERT_WITH_MSG(type, check, ...) LS_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define LS_INTERNAL_ASSERT_NO_MSG(type, check) LS_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failet at {1}:{2}", LS_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define LS_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define LS_INTERNAL_ASSERT_GET_MACRO(...) LS_EXPAND_MACRO ( LS_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, LS_INTERNAL_ASSERT_WITH_MSG, LS_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define LS_ASSERT(...) LS_EXPAND_MACRO( LS_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define LS_CORE_ASSERT(...) LS_EXPAND_MACRO( LS_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define LS_ASSERT(...)
	#define LS_CORE_ASSERT(...)
#endif