#pragma once

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Trilobal {
	class TRILOBAL_API log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define TL_CORE_TRACE(...)		::Trilobal::log::getCoreLogger()->trace(__VA_ARGS__)
#define TL_CORE_INFO(...)		::Trilobal::log::getCoreLogger()->info(__VA_ARGS__)
#define TL_CORE_WARN(...)		::Trilobal::log::getCoreLogger()->warn(__VA_ARGS__)
#define TL_CORE_ERROR(...)		::Trilobal::log::getCoreLogger()->error(__VA_ARGS__)
#define TL_CORE_FATAL(...)		::Trilobal::log::getCoreLogger()->fatal(__VA_ARGS__)


// Client log macros
#define TL_CLIENT_TRACE(...)         Trilobal::log::getClientLogger()->trace(__VA_ARGS__)
#define TL_CLIENT_INFO(...)          ::Trilobal::log::getClientLogger()->info(__VA_ARGS__)
#define TL_CLIENT_WARN(...)          ::Trilobal::log::getClientLogger()->warn(__VA_ARGS__)
#define TL_CLIENT_ERROR(...)         ::Trilobal::log::getClientLogger()->error(__VA_ARGS__)
#define TL_CLIENT_CRITICAL(...)      ::Trilobal::log::getClientLogger()->critical(__VA_ARGS__)