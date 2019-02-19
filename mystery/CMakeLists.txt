cmake_minimum_required (VERSION 3.8)

# Compiler definitions / preprocessor defs
add_compile_definitions(MYSTERY_BUILD_DLL)

include_directories(${CMAKE_SOURCE_DIR}/mystery/src)

# mystery source files
set(MYSTERY_SRC 
	src/log.cpp
	src/log.hpp
	src/core.cpp
	src/core.hpp
	src/mystery.cpp
	src/mystery.hpp
)

# mystery include files (public api)
set(MYSTERY_INCLUDE 
	mystery_app.hpp
)

# Add source to this project's executable.
add_library (Mystery SHARED
			${MYSTERY_SRC}
			${MYSTERY_INCLUDE}
)

install(TARGETS Mystery DESTINATION ${INSTALL_FOLDER})

