#pragma once

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

#include "Lisa/Core/Base.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)


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

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
	return os << glm::to_string(quaternion);
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