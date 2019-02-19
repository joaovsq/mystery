cmake_minimum_required (VERSION 3.8)

# dependencies
include_directories(${CMAKE_SOURCE_DIR}/mystery)

# sandbox source files
set(SANDBOX_SRC
	src/sandbox.cpp
	src/sandbox.hpp
)

# Add source to this project's executable.
add_executable (Sandbox ${SANDBOX_SRC})

# TODO: find a better way to link this dependency
target_link_libraries(Sandbox ${INSTALL_FOLDER}/mystery.lib)

install(TARGETS Sandbox DESTINATION ${INSTALL_FOLDER})
