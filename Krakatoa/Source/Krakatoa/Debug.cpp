#include "Debug.hpp"

namespace Krakatoa
{
	std::shared_ptr<spdlog::logger> Debug::s_coreDebugger;
	std::shared_ptr<spdlog::logger> Debug::s_clientDebugger;

	void Debug::init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_coreDebugger = spdlog::stdout_color_mt("Krakatoa");
		s_coreDebugger->set_level(spdlog::level::trace);

		s_clientDebugger = spdlog::stdout_color_mt("Client");
		s_clientDebugger->set_level(spdlog::level::trace);
	}
}