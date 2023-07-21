#include "tlpch.h"

#include "log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

void setConsoleTitle(const char* title) { while (true) { SetConsoleTitleA(title); break; } }

namespace Trilobal {
	std::shared_ptr<spdlog::logger> log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> log::s_ClientLogger;

	void log::Init()
	{
		setConsoleTitle("Trilobal Game Engine [Backend]");
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("TRILOBAL");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("SANDBOX");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}