#pragma once

#include "core.hpp"
#include "log.hpp"
#include "window/window.hpp"

namespace Mystery {

	class MYSTERY_API MysteryApplication
	{
	public:
		MysteryApplication();
		virtual	~MysteryApplication();
		void Run();

	private:
		bool m_IsRunning;

		std::unique_ptr<Window> m_MainWindow;
	};

}