#include "mystery.hpp"

namespace Mystery {


	// lets initialize all the essentials components
	MysteryApplication::MysteryApplication() {
		Log::Init();
		LOG_INFO("Starting Mystery Engine components...");

		m_MainWindow = std::unique_ptr<Window>(Window::Create());
	}

	MysteryApplication::~MysteryApplication() {

	}

	void MysteryApplication::Run() {
		std::cin.get();
	}



}

