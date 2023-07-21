#include "tlpch.h"

#include "Application.h"

#include "events/ApplicationEvent.h"
#include "log.h"

namespace Trilobal {

	Application::Application() {

	}

	Application::~Application()
	{

	}

	void Application::isRun() {
		WindowResizeEvent e(1280, 768);
		if (e.IsInCategory(EventCategoryApplication))
			TL_CLIENT_TRACE(e);

		while (true);
	}

}