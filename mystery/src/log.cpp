#include "log.hpp"

namespace Mystery {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;


	void Log::Init() {
		spdlog::set_pattern("%^ %c -[%n] [%l] - %$ %v");

		// first we need to initialize the loggers
		s_CoreLogger = spdlog::stdout_color_mt("MYSTERY");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("GAME");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}
