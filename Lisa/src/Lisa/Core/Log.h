#pragma once

#include "Lisa/Core/Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Lisa {

	class Log
	{	
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define LS_CORE_TRACE(...)    ::Lisa::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LS_CORE_INFO(...)     ::Lisa::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LS_CORE_WARN(...)     ::Lisa::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LS_CORE_ERROR(...)    ::Lisa::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LS_CORE_CRITICAL(...) ::Lisa::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define LS_TRACE(...)         ::Lisa::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LS_INFO(...)          ::Lisa::Log::GetClientLogger()->info(__VA_ARGS__)
#define LS_WARN(...)          ::Lisa::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LS_ERROR(...)         ::Lisa::Log::GetClientLogger()->error(__VA_ARGS__)
#define LS_CRITICAL(...)      ::Lisa::Log::GetClientLogger()->critical(__VA_ARGS__)