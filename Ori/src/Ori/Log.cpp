#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Ori {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init() {

		//Logger pattern displayed (Color > Time > Log level > Logger name > Message)
		spdlog::set_pattern("%^[%T] [%l in %n] : %v%$");

		//Defining our CoreLogger with the name "ORI"
		s_CoreLogger = spdlog::stdout_color_mt("ORI");
		s_CoreLogger->set_level(spdlog::level::trace); //Logger prints all type of errors

		//Defining our CoreLogger with the name "Application"
		s_ClientLogger = spdlog::stdout_color_mt("APPLICATION");
		s_ClientLogger->set_level(spdlog::level::trace);
		

	}



}