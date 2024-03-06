#pragma once

#include "memory"
#include "Core.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Krakatoa
{
	class KRAKATOA_API Debug
	{
		public:
		static void init();
		inline static std::shared_ptr<spdlog::logger>& getCoreDebugger() { return s_coreDebugger; }
		inline static std::shared_ptr<spdlog::logger>& getClientDebugger() { return s_clientDebugger; }

		private:
		static std::shared_ptr<spdlog::logger> s_coreDebugger;
		static std::shared_ptr<spdlog::logger> s_clientDebugger;
	};
}

#ifndef NDEBUG
	#define KRAKATOA_CORE_INFO(...)     ::Krakatoa::Debug::getCoreDebugger()->info(__VA_ARGS__)
	#define KRAKATOA_CORE_WARN(...)     ::Krakatoa::Debug::getCoreDebugger()->warn(__VA_ARGS__)
	#define KRAKATOA_CORE_ERROR(...)    ::Krakatoa::Debug::getCoreDebugger()->error(__VA_ARGS__)
	#define KRAKATOA_CORE_TRACE(...)    ::Krakatoa::Debug::getCoreDebugger()->trace(__VA_ARGS__)
	#define KRAKATOA_CORE_CRITICAL(...) ::Krakatoa::Debug::getCoreDebugger()->critical(__VA_ARGS__)

	#define KRAKATOA_INFO(...)          ::Krakatoa::Debug::getClientDebugger()->info(__VA_ARGS__)
	#define KRAKATOA_WARN(...)          ::Krakatoa::Debug::getClientDebugger()->warn(__VA_ARGS__)
	#define KRAKATOA_ERROR(...)         ::Krakatoa::Debug::getClientDebugger()->error(__VA_ARGS__)
	#define KRAKATOA_TRACE(...)         ::Krakatoa::Debug::getClientDebugger()->trace(__VA_ARGS__)
	#define KRAKATOA_CRITICAL(...)      ::Krakatoa::Debug::getClientDebugger()->critical(__VA_ARGS__)
#else
	#define KRAKATOA_CORE_INFO
	#define KRAKATOA_CORE_WARN
	#define KRAKATOA_CORE_ERROR
	#define KRAKATOA_CORE_TRACE
	#define KRAKATOA_CORE_CRITICAL

	#define KRAKATOA_INFO
	#define KRAKATOA_WARN
	#define KRAKATOA_ERROR
	#define KRAKATOA_TRACE
	#define KRAKATOA_CRITICAL
#endif