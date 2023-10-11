#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Emerald {
	class EMERALD_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core logging macros
#define EMERALD_CORE_TRACE(...)   ::Emerald::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EMERALD_CORE_INFO(...)    ::Emerald::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EMERALD_CORE_WARN(...)    ::Emerald::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EMERALD_CORE_ERROR(...)   ::Emerald::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EMERALD_CORE_FATAL(...)   ::Emerald::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client logging macros
#define EMERALD_TRACE(...)   ::Emerald::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EMERALD_INFO(...)    ::Emerald::Log::GetClientLogger()->info(__VA_ARGS__)
#define EMERALD_WARN(...)    ::Emerald::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EMERALD_ERROR(...)   ::Emerald::Log::GetClientLogger()->error(__VA_ARGS__)
#define EMERALD_FATAL(...)   ::Emerald::Log::GetClientLogger()->fatal(__VA_ARGS__)
