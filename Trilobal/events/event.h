#pragma once

#include "core/core.h"

using namespace std;

namespace Trilobal {
	enum class eventType {	//�¼�����
		None = 0,
		WindowClose,WindowResize,WindowFocus,WindowLostFocus,WindowMoved,	//���ڹرգ����ڵ�����С�����ڽ��㣬����ʧȥ���㣬�����ƶ�
		AppTick,AppUpdate,AppRender,	//��ʾ�����£���Ⱦ
		KeyPressed,KeyReleased,			//������ס�������ͷ�
		MouseButtonPressed,MouseButtonReleased,MouseMoved,MouseScrolled		//��갴����ס����갴���ͷţ�����ƶ���������
	};

	enum eventCatgory {	//�¼������
		None = 0,
		EventCategoryApplication = BIT(0),	//�¼����Ӧ��
		EventCategoryInput = BIT(1),		//�¼��������
		EventCategoryKeyboard = BIT(2),		//�¼�������
		EventCategoryMouse = BIT(3),		//�¼�������
		EventCategoryMouseButton = BIT(4)	//�¼������갴ť
	};

//���Event_Class_Type(type)�е�type = None����ô�ͷ���ֵ��EventType::None;
#define EVENT_CLASS_TYPE(type) static eventType GetStaticType() {return eventType::type;}\
								virtual eventType GetEventType() const override {return GetStaticType();}\
								virtual const char* GetName() const override {return #type;}
//2.����override������д�˺�����ͬʱ��ȡEventType::##type�ķ���ֵ
//3.����override������д�˺���,ͬʱ���ý�������ַ�������

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}
										//����һ����ȡ���Flags�ĺ�����ͬʱ������д����override����Ŀ�ķ���һ�����

	class TRILOBAL_API event {
	public:
		virtual ~event() = default;

		bool Handled = false;

		virtual eventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(eventCatgory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher {
	public:
		EventDispatcher(event& event) : m_event(event){}

		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_event.GetEventType() == T::GetStaticType())
			{
				m_event.Handled |= func(static_cast<T&>(m_event));
				return true;
			}
			return false;
		}
	private:
		event& m_event;
	};

	inline ostream& operator << (ostream& os, const event& e)
	{
		return os << e.ToString();
	}
}