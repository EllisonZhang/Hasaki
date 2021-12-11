#pragma once
#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/pattern_formatter.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace HSK {

	class HSK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}


// Core log macros
#define HSK_CORE_TRACE(...)  ::HSK::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HSK_CORE_INFO(...) ::HSK::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HSK_CORE_WARN(...) HSK::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HSK_CORE_ERROR(...) ::HSK::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HSK_CORE_FATAL(...) ::HSK::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HSK_CLIENT_TRACE(...) ::HSK::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HSK_CLIENT_INFO(...) ::HSK::Log::GetClientLogger()->info(__VA_ARGS__)
#define HSK_CLIENT_WARN(...) ::HSK::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HSK_CLIENT_ERROR(...) ::HSK::Log::GetClientLogger()->error(__VA_ARGS__)
#define HSK_CLIENT_FATAL(...) ::HSK::Log::GetClientLogger()->fatal(__VA_ARGS__)

