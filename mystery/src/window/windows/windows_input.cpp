#include "windows_input.hpp"

bool Mystery::WindowsInput::IsKeyPressedImpl(int keycode)
{
	return false;
}

bool Mystery::WindowsInput::IsMouseButtonPressedImpl(int button)
{
	return false;
}

std::pair<float, float> Mystery::WindowsInput::GetMousePositionImpl()
{
	return std::pair<float, float>();
}

float Mystery::WindowsInput::GetMouseXImpl()
{
	return 0.0f;
}

float Mystery::WindowsInput::GetMouseYImpl()
{
	return 0.0f;
}
