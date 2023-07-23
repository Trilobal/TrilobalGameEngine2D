#include "tlpch.h"

#include "Application.h"

#include "events/ApplicationEvent.h"
#include "log.h"

namespace Trilobal {

	Application::Application() {
		m_window = unique_ptr<window>(window::create());
	}

	Application::~Application()
	{

	}

	void Application::isRun() {
		while (m_Running)
		{
			//m_window->setBackgroundColor();
			m_window->OnUpdate();
		}
	}
}