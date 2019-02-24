#include "core.hpp"
#include "windows_window.hpp"

namespace Mystery {


	void WindowsWindow::Init()
	{

	}

	void WindowsWindow::OnUpdate()
	{
	}

	inline unsigned int WindowsWindow::GetWidth() const
	{
		return m_Width;
	}

	inline unsigned int WindowsWindow::GetHeight() const
	{
		return m_Height;
	}

	void WindowsWindow::SetEventCallback(const EventCallbackFn & callback)
	{
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
	}

	bool WindowsWindow::IsVSync() const
	{
		return false;
	}

	void* WindowsWindow::GetNativeWindow() const
	{
		return nullptr;
	}


}