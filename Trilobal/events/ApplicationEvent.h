#pragma once

#include "tlpch.h"
#include "events/event.h"

namespace Trilobal {
	class WindowResizeEvent : public event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

		unsigned int GetWidth() const { return m_Width; }
		unsigned int GetHeight() const { return m_Height; }

		string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Width,m_Height;
	};

	class WindowCloseEvent : public event
	{
	public:
		WindowCloseEvent() = default;	//定义构造函数，用于CALL时初始化

		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppTickEvent : public event
	{
	public:
		AppTickEvent() = default;

		EVENT_CLASS_TYPE(AppTick)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppUpdateEvent : public event
	{
	public:
		AppUpdateEvent() = default;	//定义构造函数，用于CALL时初始化

		EVENT_CLASS_TYPE(AppUpdate)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppRenderEvent : public event
	{
	public:
		AppRenderEvent() = default;	//定义构造函数，用于CALL时初始化

		EVENT_CLASS_TYPE(AppRender);
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

}