#pragma once

#include "core.hpp"
#include "window/window.hpp"

namespace Mystery {

	class WindowsWindow : public Window {

	public:
		void OnUpdate() override;

		inline unsigned int GetWidth() const override;

		inline unsigned int GetHeight() const override;

		inline void SetEventCallback(const EventCallbackFn & callback) override;

		void SetVSync(bool enabled) override;

		bool IsVSync() const override;

		void * GetNativeWindow() const override;

	private:


	};

}