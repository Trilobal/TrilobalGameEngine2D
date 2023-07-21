#pragma once

#include "core/core.h"

using namespace std;

namespace Trilobal {
	enum class eventType {	//事件类型
		None = 0,
		WindowClose,WindowResize,WindowFocus,WindowLostFocus,WindowMoved,	//窗口关闭，窗口调整大小，窗口焦点，窗口失去焦点，窗口移动
		AppTick,AppUpdate,AppRender,	//提示，更新，渲染
		KeyPressed,KeyReleased,			//按键按住，按键释放
		MouseButtonPressed,MouseButtonReleased,MouseMoved,MouseScrolled		//鼠标按键按住，鼠标按键释放，鼠标移动，鼠标滚动
	};

	enum eventCatgory {	//事件类别定义
		None = 0,
		EventCategoryApplication = BIT(0),	//事件类别应用
		EventCategoryInput = BIT(1),		//事件类别输入
		EventCategoryKeyboard = BIT(2),		//事件类别键盘
		EventCategoryMouse = BIT(3),		//事件类别鼠标
		EventCategoryMouseButton = BIT(4)	//事件类别鼠标按钮
	};

//如果Event_Class_Type(type)中的type = None，那么就返回值：EventType::None;
#define EVENT_CLASS_TYPE(type) static eventType GetStaticType() {return eventType::type;}\
								virtual eventType GetEventType() const override {return GetStaticType();}\
								virtual const char* GetName() const override {return #type;}
//2.定义override方便重写此函数，同时获取EventType::##type的返回值
//3.定义override方便重写此函数,同时作用将宏变量字符化返回

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}
										//定义一个获取类别Flags的函数，同时方便重写定义override，其目的返回一个类别

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