#pragma once

#include "core.hpp"

namespace Mystery {

	enum class EventType
	{
		NONE = 0,
		WINDOW_CLOSE, WINDOW_RESIZE, WINDOW_FOCUS, WINDOW_LOST_FOCUS, WINDOW_MOVED,
		APP_TICK, APP_UPDATE, APP_RENDER,
		KEY_PRESSED, KEY_RELEASED, KEY_TYPED,
		MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED, kMOUSE_MOVED, MOUSE_SCROLLED
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
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	template<typename T>
	class EventDispatcher
	{
		// event callback 
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}
		// TODO: REMEMBER TO FIX THIS, THIS IS AN UNSAFE CALLBACK CALL, 
		// because we can't known if the callback event is the same received in the constructor
		bool Dispatch(EventFn<T> func)
		{
			m_Event.Handled = func(*(T*)&m_Event);
			return true;
		}

	private:
		Event& m_Event;
	};

}