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
		m_Window = glfwCreateWindow(GetWidth(), GetHeight(), m_Props.Title.c_str(), NULL, NULL);

		if (!m_Window)
		{
			this->~WindowsWindow();
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(m_Window);

		// TODO: check if this is necessary
		//glfwSwapInterval(1);
	}

	void WindowsWindow::OnUpdate()
	{
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

	void WindowsWindow::SetVSync(bool enabled)
	{
		// @todo
	}

	bool WindowsWindow::IsVSync() const
	{
		return false;
	}

	void* WindowsWindow::GetNativeWindow() const
	{
		return m_Window;
	}

}