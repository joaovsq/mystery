#pragma once

#include "core.hpp"
#include "events/event.hpp"

namespace Mystery {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		// Default window setup, this may change in the future
		WindowProps(const std::string& title = "Mystery Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height) { }

	};

	// Interface representing a desktop system based Window
	class MYSTERY_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		// this may change depending on the platform
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& windowProps = WindowProps());
	};

}
