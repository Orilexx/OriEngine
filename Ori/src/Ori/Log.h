#pragma once

#include <memory>
#include "Core.h"
#include <spdlog/spdlog.h>


namespace Ori {
	class ORI_API Log
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

//CORE LOGGER MACROS
#define ORI_CORE_CRITICAL(...) ::Ori::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define ORI_CORE_ERROR(...)    ::Ori::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ORI_CORE_WARN(...)     ::Ori::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ORI_CORE_INFO(...)     ::Ori::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ORI_CORE_TRACE(...)    ::Ori::Log::GetCoreLogger()->trace(__VA_ARGS__)

//CLIENT LOGGER MACROS
#define ORI_CRITICAL(...) ::Ori::Log::GetClientLogger()->critical(__VA_ARGS__)
#define ORI_ERROR(...)    ::Ori::Log::GetClientLogger()->error(__VA_ARGS__)
#define ORI_WARN(...)     ::Ori::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ORI_INFO(...)     ::Ori::Log::GetClientLogger()->info(__VA_ARGS__)
#define ORI_TRACE(...)    ::Ori::Log::GetClientLogger()->trace(__VA_ARGS__)

//NEED TO SCRAP CORE MACROS IN BUILDS