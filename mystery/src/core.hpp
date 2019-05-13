#pragma once

// We check if this is being built by the engine or a client application
// if it is by the engine we need to export the dll, otherwise we need to import it 
#ifdef MYSTERY_BUILD_EXE
#define MYSTERY_API
#else
#ifdef MYSTERY_BUILD_DLL
#define MYSTERY_API __declspec(dllexport)
#else
#define MYSTERY_API __declspec(dllimport)
#endif
#endif

#define BIT(x) (1 << x)

#ifdef MYSTERY_PLATFORM_WINDOWS
#endif

// all project essentials includes
#include "myspch.hpp"

namespace Mystery {
}

