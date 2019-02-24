#include "mystery.hpp"

namespace Mystery {


	// lets initialize all the essentials components
	MysteryApplication::MysteryApplication() {
		Log::Init();
		LOG_INFO("Starting Mystery Engine components...");

		m_MainWindow = std::unique_ptr<Window>(Window::Create());
		
		m_Running = true;
	}

	MysteryApplication::~MysteryApplication() {

	}

	void MysteryApplication::OnEvent() {

	}

	void MysteryApplication::Run() {
		while (m_Running) {
			m_MainWindow->OnUpdate();
		}
	}

}

