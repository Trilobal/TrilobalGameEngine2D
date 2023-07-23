#pragma once

//Public File
#include "tlpch.h"

#include "core/log.h"
#include "core/core.h"
#include "events/event.h"

namespace Trilobal
{
	struct WindowProps
	{
		string title;
		unsigned int width;
		unsigned int height;

		WindowProps(const string WindowTitle = "Default Engine Window", int wd = 1280, int hg = 768) : title(WindowTitle), width(wd), height(hg) {}
	};

	class TRILOBAL_API window
	{
	public:
		using eventCallbackFun = function<void(event&)>;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		virtual void OnUpdate() = 0;
		virtual void setEventCallback(const eventCallbackFun& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
		virtual void setBackgroundColor(float r = 255.0f, float b = 255.0f, float g = 255.0f, float a = 1.0f) = 0;

		static window* create(const WindowProps& props = WindowProps());
	};
}