#pragma once

#include "window/window.h"

#include <glfw64/glfw3.h>

#pragma comment(lib,"glfw3.lib")

namespace Trilobal
{
	class WindowsWindow : public window
	{
	public:
		WindowsWindow(const windowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int getWidth() const override { return m_data.width; }
		inline unsigned int getHeight() const override { return m_data.height; }

		inline void setEventCallback(const eventCallbackFun& callback) override { m_data.eventCallback = callback; }
		void setVSync(bool enabled) override = 0;
		bool IsVSync() const override = 0;
	private:
		virtual void init(const windowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_window;

		struct windowData
		{
			string title;
			unsigned int width,height;
			bool VSync;

			eventCallbackFun eventCallback;
		};

		windowData m_data;
	};


}
