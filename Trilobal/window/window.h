#pragma once

//Public File
#include "tlpch.h"

#include "core/log.h"
#include "core/core.h"
#include "events/event.h"

namespace Trilobal
{
	class windowProps
	{
	public:
		windowProps(const string& windowTitle = "Defailt Window [Trilobal Engine]", unsigned int width = 1280, unsigned int height = 720) : title(windowTitle), m_width(width), m_height(height) {}
	public:
		string title;

		unsigned int m_width;
		unsigned int m_height;
	};

	class TRILOBAL_API window
	{
	public:
		using eventCallbackFun = function<void(event&)>;

		virtual ~window(){}

		virtual void OnUpdate() = 0;
		
		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		virtual void setEventCallback(const eventCallbackFun& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static window* createWindow(const windowProps& props = windowProps());
	};
}