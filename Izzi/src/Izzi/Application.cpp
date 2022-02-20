#include "Application.h"

#include "Izzi/Events/ApplicationEvent.h"
#include "Izzi/Log.h"

namespace Izzi
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			IZ_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			IZ_TRACE(e);
		}

		while (true);
	}
}
