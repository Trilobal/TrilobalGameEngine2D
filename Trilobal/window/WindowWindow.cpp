#include "tlpch.h"
#include "WindowsWindow.h"

namespace Trilobal {

	static bool s_GLFWInitialized = false;

	/*
	window* window::createWindow(const windowProps& props){
		return new WindowsWindow(props);
	}
	*/
	WindowsWindow::WindowsWindow(const windowProps& props){
		init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::init(const windowProps& props)
	{
		m_data.title = props.title;
		m_data.width = props.m_width;
		m_data.height = props.m_height;

		TL_CORE_INFO("Createing window {0} ({1} {2})", props.title, props.m_width, props.m_height);

		if (s_GLFWInitialized)
		{
			int success = glfwInit();
			//TL_CORE_ASSERT(success,"Could not initialize GLFW!");
			s_GLFWInitialized = true;
		}

		m_window = glfwCreateWindow((int)props.m_width, (int)props.m_height, props.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		//glfwSetFramebufferSizeCallback(m_window,&m_data);
		setVSync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void WindowsWindow::setVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval((int)enabled);
		else
			glfwSwapInterval((int)enabled);
	}

	bool WindowsWindow::IsVSync() const
	{
		return false;
	}
}