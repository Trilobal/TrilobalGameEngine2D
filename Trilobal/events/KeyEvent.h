#pragma once

#include "events/event.h"

namespace Trilobal {
	class KeyEvent : public event
	{
	public:
		inline int getKeyCode() const {	//����һ����������getKeyCode�����ڻ�ȡ�����룬��ֻ�������޸�
			return m_KeyCode;
		}

		//����Event_class_category�귵�����call functions: GetCategoryFlags() {return category;}
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)	//
	protected:
		KeyEvent(int keycode) : m_KeyCode(keycode) {}
		int m_KeyCode;
	};

	class  KeyPressendEvent : KeyEvent
	{
	public:
		KeyPressendEvent(int keycode,int repeatCount) : KeyEvent(keycode),m_RepeatCount(repeatCount){	//���캯������ʼ��������
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
		int m_RepeatCount;	//�ظ���������
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