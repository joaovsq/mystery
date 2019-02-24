#include "mystery.hpp"

namespace Mystery {


	MysteryApplication::MysteryApplication() {
		// initializes all components
		initialize();
	}

	MysteryApplication::~MysteryApplication() {

	}

	void MysteryApplication::Run() {
		LOG_INFO("Mystery Engine starting...");
		std::cin.get();
	}


}

