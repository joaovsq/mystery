#pragma once

#include <core.hpp>

namespace mystery {
	namespace events {

		enum class EventType
		{
			NONE = 0,
			WINDOW_CLOSE, WINDOW_RESIZE, WINDOW_FOCUS, WINDOW_LOST_FOCUS, WINDOW_MOVED,
			APP_TICK, APP_UPDATE, APP_RENDER,
			KEY_PRESSED, KEY_RELEASED, KEY_TYPED,
			MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED, MOUSE_MOVED, MOUSE_SCROLLED
		};

		enum EventCategory
		{
			NONE = 0,
			APPLICATION = BIT(0),
			INPUT = BIT(1),
			KEYBOARD = BIT(2),
			MOUSE = BIT(3),
			MOUSE_BUTTON = BIT(4)
		};


	}
}