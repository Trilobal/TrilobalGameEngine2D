#pragma once

#include "events/event.h"

namespace Trilobal {
	class KeyEvent : public event
	{
	public:
		inline int getKeyCode() const {	//定义一个内联函数getKeyCode，用于获取键代码，且只读并不修改
			return m_KeyCode;
		}

		//调用Event_class_category宏返回类别，call functions: GetCategoryFlags() {return category;}
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)	//
	protected:
		KeyEvent(int keycode) : m_KeyCode(keycode) {}
		int m_KeyCode;
	};

	class  KeyPressendEvent :public KeyEvent
	{
	public:
		KeyPressendEvent(int keycode,int repeatCount) : KeyEvent(keycode),m_RepeatCount(repeatCount){	//构造函数，初始化参数表
		}

		inline int GetRepeatCount(int repeatCount) const { return m_RepeatCount; }

		string ToString() const override
		{
			stringstream ss;
			ss << "KeyPressEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	protected:
		int m_RepeatCount;	//重复计数变量
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode){}

		string ToString() const override {
			stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}