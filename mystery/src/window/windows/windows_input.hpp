#pragma once

#include "window/input.hpp"

namespace Mystery {

	// Defines all specific input implementation for the Windows platform
	class WindowsInput : public Input {

		bool IsKeyPressedImpl(int keycode) override;

		bool IsMouseButtonPressedImpl(int button) override;

		std::pair<float, float> GetMousePositionImpl() override;

		float GetMouseXImpl() override;

		float GetMouseYImpl() override;

	};

}