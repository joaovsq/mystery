#include "mystery.hpp"

#include <iostream>

namespace mystery {


	MysteryApplication::MysteryApplication() {
		Log::Init();
	}

	MysteryApplication::~MysteryApplication() {

	}

	void MysteryApplication::Run() {
		LOG_INFO("Mystery Engine starting...");
		std::cin.get();
	}


}

