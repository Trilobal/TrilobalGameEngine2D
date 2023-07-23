#include "tlpch.h"
#include "WindowsWindow.h"

namespace Trilobal {

	static bool s_GLFWInitialized = false;
	static void GLFWErrorCallback(int error_code, const char* description)	//Params:错误代码，描述
	{
		TL_CORE_ERROR("GLFW Error (Code:{0} , Description:{1})", error_code, description);
	}

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
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_window = glfwCreateWindow((int)props.width, (int)props.height, props.title.c_str(), nullptr, nullptr);
		if (m_window)
			TL_CORE_INFO("Create Window Successfully");
		else
			TL_CORE_ERROR("Failed to create window");
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_data);
		setVSync(true);

		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			WindowResizeEvent event(width, height);
			data.eventCallback(event);
		});

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.eventCallback(event);
		});

		glfwSetKeyCallback(m_window,[](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressendEvent event(key, 0);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressendEvent event(key, 1);
					data.eventCallback(event);
					break;
				}
			}
			//键盘按键回调
		});

		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			switch (action)
			{
			case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleaseEvent event(button);
					data.eventCallback(event);
					break;
				}
			}
			//鼠标按键回调
		});

		glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScroolledEvent event((float)xoffset,(float)yoffset);
			data.eventCallback(event);
			//滑轮回调
		});

		glfwSetCursorPosCallback(m_window,[](GLFWwindow* window,double xpos, double ypos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMoveEvent event((float)xpos, (float)ypos);

			data.eventCallback(event);
			//光标回调
		});

		//Initialize GLAD and color;
		if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			cout << "Initialize GLAD successfully!" << endl;
		else
			cout << "Failed to initialize glad...\nInfo:" << glad_glGetError() << endl;
	}

	void windowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_window);
	}

	void windowsWindow::OnUpdate()
	{
		glfwPollEvents();

		setBackgroundColor();

		glfwSwapBuffers(m_window);
	}

	//Setup VSync
	void windowsWindow::setVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval((int)enabled);
		else
			glfwSwapInterval((int)enabled);

		m_data.VSync = enabled;
	}

	//Get the current VSync of status.
	bool windowsWindow::IsVSync() const
	{
		return m_data.VSync;
	}

	//Setup event callback
	inline void windowsWindow::setEventCallback(const eventCallbackFun& callback)
	{
		m_data.eventCallback = callback;
		TL_CORE_TRACE("[SetEventCallback]	(Called)");
	}

	//Setup the background color of the OpenGL window.
	void windowsWindow::setBackgroundColor(float r, float b, float g, float a)
	{
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}