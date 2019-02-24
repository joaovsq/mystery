#include "core.hpp"
#include "windows_window.hpp"

namespace Mystery {


	void Mystery::WindowsWindow::Init()
	{

	}

	void Mystery::WindowsWindow::OnUpdate()
	{
	}

	inline unsigned int Mystery::WindowsWindow::GetWidth() const
	{
		return;
	}

	inline unsigned int Mystery::WindowsWindow::GetHeight() const
	{
		return 0;
	}

	void Mystery::WindowsWindow::SetEventCallback(const EventCallbackFn & callback)
	{
	}

	void Mystery::WindowsWindow::SetVSync(bool enabled)
	{
	}

	bool Mystery::WindowsWindow::IsVSync() const
	{
		return false;
	}

	void *Mystery::WindowsWindow::GetNativeWindow() const
	{
		return nullptr;
	}


}