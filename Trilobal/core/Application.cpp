#include "tlpch.h"

#include "Application.h"

#include "events/ApplicationEvent.h"
#include "log.h"

namespace Trilobal {

#define BIND_EVENT_FN(x) bind(&Application::x, this, placeholders::_1)

	Application::Application() {
		WindowProps wd;
		wd.title = "Engine Window";
		wd.width = 800;
		wd.height = 600;

		m_window = unique_ptr<window>(window::create(wd));
		m_window->setEventCallback(BIND_EVENT_FN(onEvent));
	}

	Application::~Application()
	{

	}

	void Application::onEvent(event& e)
	{
		TL_CORE_INFO("{0}", e);
	}

	void Application::isRun() {
		while (m_Running)
		{
			m_window->setBackgroundColor();
			m_window->OnUpdate();
		}
	}
}