#pragma once

#include "Core.hpp"

namespace Krakatoa
{
	class KRAKATOA_API Application
	{
		public:
		Application();
		virtual ~Application();

		void run();
	};

	//define by client
	Application* createApplication();
}

