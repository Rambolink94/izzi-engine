#pragma once

#include "Core.h"

namespace Izzi
{
	class IZZI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

