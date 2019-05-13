#include "core.hpp"
#include "windows_window.hpp"


namespace Mystery {

	static bool s_GLFWInitialized = false;


	static void GLFWErrorCallback(int error, const char* description)
	{
		LOG_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	// @todo this should be implemented in different platforms, like a UbuntuWindow, etc
	Window* Window::Create(const WindowProps& windowProps)
	{
		return new WindowsWindow(windowProps);
	}

	WindowsWindow::WindowsWindow(const WindowProps& windowProps) {
		m_Props = windowProps;

		Init();
	}

	WindowsWindow::~WindowsWindow()
	{
		// @TODO close application
		glfwTerminate();
	}

	void WindowsWindow::Init()
	{
		LOG_INFO("Creating window {0} ({1}, {2})", m_Props.Title, m_Props.Width, m_Props.Height);

		if (!s_GLFWInitialized) {
			int success = glfwInit();
			assert(success);
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		/* Create a windowed mode window and its OpenGL context */
		m_Window = glfwCreateWindow(GetWidth(), GetHeight(), m_Props.Title.c_str(), nullptr, nullptr);

		if (!m_Window)
		{
			this->~WindowsWindow();
		}

		glfwMakeContextCurrent(m_Window);

		glfwSetWindowUserPointer(m_Window, &m_Props);
		SetVSync(true);

		// when the window size changes
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			auto props = *(WindowProps*)glfwGetWindowUserPointer(window);
			props.Width = width;
			props.Height = height;

			// @todo trigger a window rezise event
		});

		// when the window close
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			auto props = *(WindowProps*)glfwGetWindowUserPointer(window);

			// @todo trigger window close events
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			auto props = *(WindowProps*)glfwGetWindowUserPointer(window);

			// @todo

			switch (action)
			{
			case GLFW_PRESS:
			{

				// @todo
				break;
			}
			case GLFW_RELEASE:
			{

				break;
			}
			case GLFW_REPEAT:
			{

				break;
			}
			}
		});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
		{
			auto props = *(WindowProps*)glfwGetWindowUserPointer(window);

			// @todo
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			auto props = *(WindowProps*)glfwGetWindowUserPointer(window);

			// @todo
			switch (action)
			{
			case GLFW_PRESS:
			{

				break;
			}
			case GLFW_RELEASE:
			{

				break;
			}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			auto props = *(WindowProps*)glfwGetWindowUserPointer(window);

			//@todo
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			auto props = *(WindowProps*)glfwGetWindowUserPointer(window);

			//@todo
		});

	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	inline unsigned int WindowsWindow::GetWidth() const
	{
		return m_Props.Width;
	}

	inline unsigned int WindowsWindow::GetHeight() const
	{
		return m_Props.Height;
	}

	void WindowsWindow::SetEventCallback(const EventCallbackFn & callback)
	{
		// @todo
	}

	inline void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_VSync = enabled;
	}

	inline bool WindowsWindow::IsVSync() const
	{
		return m_VSync;
	}

	inline void* WindowsWindow::GetNativeWindow() const
	{
		return m_Window;
	}

}