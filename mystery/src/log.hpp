#pragma once

#include <spdlog/spdlog.h>
#include <memory>

#include "core.hpp"


namespace mystery {

	class MYSTERY_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	};

}

// core log macros
#define LOG_INFO(...)		  ::mystery::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)		  ::mystery::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)        ::mystery::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...)        ::mystery::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// app log macros
#define APP_LOG_INFO(...)     ::mystery::Log::GetClientLogger()->info(__VA_ARGS__)
#define APP_LOG_WARN(...)     ::mystery::Log::GetClientLogger()->warn(__VA_ARGS__)
#define APP_LOG_ERROR(...)    ::mystery::Log::GetClientLogger()->error(__VA_ARGS__)
#define APP_LOG_FATAL(...)    ::mystery::Log::GetClientLogger()->fatal(__VA_ARGS__)
