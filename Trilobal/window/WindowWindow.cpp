#include "tlpch.h"
#include "WindowsWindow.h"

namespace Trilobal {

	static bool s_GLFWInitialized = false;

	window* window::create(const WindowProps& props)
	{
		return new windowsWindow(props);
	}

	windowsWindow::windowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	windowsWindow::~windowsWindow()
	{
		Shutdown();
	}

	void windowsWindow::Init(const WindowProps& props)
	{
		m_data.title = props.title;
		m_data.width = props.width;
		m_data.height = props.height;

		TL_CORE_INFO("Createing window : {0} ({1} {2})", props.title, props.width, props.height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			TL_CORE_ASSERT(success, "Could not initialize GLFW");

			s_GLFWInitialized = true;
		}

		m_window = glfwCreateWindow((int)props.width, (int)props.height, props.title.c_str() , nullptr, nullptr);
		if (m_window)
			TL_CORE_INFO("Create Window Successfully");
		else
			TL_CORE_ERROR("Failed to create window");
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_data);
		setVSync(true);

		if (glfwInit() != GLFW_TRUE)
			cout << "Failed to initialize GLFW" << endl;
	}

	void windowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_window);
	}

	void windowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	//是否使用垂直同步
	void windowsWindow::setVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval((int)enabled);
		else
			glfwSwapInterval((int)enabled);

		m_data.VSync = enabled;
	}

	bool windowsWindow::IsVSync() const
	{
		return m_data.VSync;
	}

	void windowsWindow::setBackgroundColor(float r, float b, float g, float a)
	{
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}