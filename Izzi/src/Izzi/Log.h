#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Izzi
{
	class IZZI_API Log
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
#define IZ_CORE_TRACE(...) ::Izzi::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define IZ_CORE_INFO(...)  ::Izzi::Log::GetCoreLogger()->info(__VA_ARGS__)
#define IZ_CORE_WARN(...)  ::Izzi::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define IZ_CORE_ERROR(...) ::Izzi::Log::GetCoreLogger()->error(__VA_ARGS__)
#define IZ_CORE_FATAL(...) ::Izzi::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define IZ_TRACE(...) ::Izzi::Log::GetClientLogger()->trace(__VA_ARGS__)
#define IZ_INFO(...)  ::Izzi::Log::GetClientLogger()->info(__VA_ARGS__)
#define IZ_WARN(...)  ::Izzi::Log::GetClientLogger()->warn(__VA_ARGS__)
#define IZ_ERROR(...) ::Izzi::Log::GetClientLogger()->error(__VA_ARGS__)
#define IZ_FATAL(...) ::Izzi::Log::GetClientLogger()->fatal(__VA_ARGS__)