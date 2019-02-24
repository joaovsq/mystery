#pragma once

#include "window/window.hpp"

#include <GLFW/glfw3.h>

namespace Mystery {

	class WindowsWindow : public Window {

	public:

		WindowsWindow(const WindowProps& windowProps);

		~WindowsWindow() override;

		void OnUpdate() override;

		inline unsigned int GetWidth() const override;

		inline unsigned int GetHeight() const override;

		inline void SetEventCallback(const EventCallbackFn & callback) override;

		void SetVSync(bool enabled) override;

		bool IsVSync() const override;

		void* GetNativeWindow() const override;

	//	static WindowsWindow* Create(const WindowProps & windowProps = WindowProps());

	private:
		bool m_VSync;
		WindowProps m_Props;
		GLFWwindow* m_Window;

		void Init();
	};

}