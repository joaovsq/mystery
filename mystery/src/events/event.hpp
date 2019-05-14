#pragma once

#include "core.hpp"

namespace Mystery {

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowMoved,
		AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// this is necessary if we need to enconde multiple flags in a single variable
	enum EventCategory
	{
		NONE = 0,
		APPLICATION = BIT(0),
		INPUT = BIT(1),
		KEYBOARD = BIT(2),
		MOUSE = BIT(3),
		MOUSE_BUTTON = BIT(4)
	};

	class MYSTERY_API Event {
	public:
		bool m_Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual int GetCategoryFlags() const = 0;
		
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	template<typename T>
	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}
	
		// @TODO: REMEMBER TO FIX THIS, THIS IS AN UNSAFE CALLBACK CALL, 
		// because we can't known if the callback event is the same received in the constructor
		bool Dispatch(std::function<bool(T&)> func)
		{
			//	m_Event.Handled = func(*(T*)&m_Event);
			return true;
		}

	private:
		Event& m_Event;
	};

}