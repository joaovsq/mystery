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
		
		void OnEvent();
		void Run();

	private:
		bool m_Running;

		std::unique_ptr<Window> m_MainWindow;
	};

}