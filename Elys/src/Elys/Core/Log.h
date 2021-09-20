#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Elys {

	class ELYS_API Log
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
#define ELYS_CORE_TRACE(...)    ::Elys::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ELYS_CORE_INFO(...)     ::Elys::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ELYS_CORE_WARN(...)     ::Elys::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ELYS_CORE_ERROR(...)    ::Elys::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ELYS_CORE_FATAL(...)    ::Elys::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define ELYS_TRACE(...)	        ::Elys::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ELYS_INFO(...)	        ::Elys::Log::GetClientLogger()->info(__VA_ARGS__)
#define ELYS_WARN(...)	        ::Elys::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ELYS_ERROR(...)	        ::Elys::Log::GetClientLogger()->error(__VA_ARGS__)
#define ELYS_FATAL(...)	        ::Elys::Log::GetClientLogger()->fatal(__VA_ARGS__)