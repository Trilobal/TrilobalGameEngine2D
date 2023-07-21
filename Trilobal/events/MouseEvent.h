#pragma once

#include "events/event.h"

namespace Trilobal {
	class TRILOBAL_API MouseMoveEvent : public event
	{
	public:
		MouseMoveEvent(float x,float y) : m_MouseX(x),m_MouseY(y){}

		inline float getX() const { return m_MouseX; }
		inline float getY() const { return m_MouseY; }

		string ToString() const override{
			stringstream ss;
			ss << "MouseMoveEvent: " << m_MouseX << " , " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};

	class TRILOBAL_API MouseScroolledEvent : public event
	{
	public:
		MouseScroolledEvent(float xOffset,float yOffset) : m_xOffset(xOffset),m_yOffset(m_yOffset){}

		inline float getXOffset() const { return m_xOffset;}
		inline float getYOffset() const { return m_yOffset;}

		string ToString() const override {
			stringstream ss;
			ss << "MouseScroolledEvent: " << m_xOffset << " , " << m_yOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_xOffset, m_yOffset;
	};

	class TRILOBAL_API MouseButtonEvent : public event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button) : m_Button(button){}
		int m_Button;
	};

	class TRILOBAL_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button){}

		string ToString() const override {
			stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class TRILOBAL_API MouseButtonReleaseEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleaseEvent(int button) : MouseButtonEvent(button) {}

		string ToString() const override {
			stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}

