#pragma once

#include <glad/glad.h>
#include <glfw64/glfw3.h>

#include "window/window.h"

#pragma comment(lib,"glfw3.lib")

namespace Trilobal {
	class windowsWindow : public window
	{
	public:
		windowsWindow(const WindowProps& props);
		virtual ~windowsWindow();
	public:
		inline unsigned int getWidth() const override { return m_data.width; };
		inline unsigned int getHeight() const  override { return m_data.height; };

		void OnUpdate() override;

		inline void setEventCallback(const eventCallbackFun& callback) override { m_data.eventCallback = callback; }
		void setVSync(bool enabled) override;
		bool IsVSync() const override;
	public:
		virtual void Init(const WindowProps& props);	//��ʼ������
		virtual void Shutdown();
	public:
		void setBackgroundColor(float r = 255.0f, float b = 255.0f, float g = 255.0f, float a = 1.0f) override;
	private:
		struct WindowData
		{
			string title;
			unsigned int width, height;
			bool VSync;

			eventCallbackFun eventCallback;	//�¼��ص�����
		};
	private:
		GLFWwindow* m_window;
		WindowData m_data;
	};
}
