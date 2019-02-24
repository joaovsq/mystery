#pragma once

#include "core.hpp"
#include "events/event.hpp"

namespace Mystery {

	// Interface representing a desktop system based Window
	class MYSTERY_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		// Default window setup, this may change in the future
		Window(const std::string& mTitle = "Mystery Engine",
			unsigned int mWidth = 1280,
			unsigned int mHeight = 720)
			: title(mTitle), width(mWidth), height(mHeight) { }

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		// this may change depending on the platform
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

	private:
		std::string title;
		unsigned int width;
		unsigned int height;


	};

}
