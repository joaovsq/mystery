#pragma once

// We check if this is being built by the engine or a client application
// if it is by the engine we need to export the dll, otherwise we need to import it 
#ifdef MYSTERY_BUILD_DLL
#define MYSTERY_API __declspec(dllexport)
#else
#define MYSTERY_API __declspec(dllimport)
#endif

namespace mystery {
	void initialize();

	void start();
}

