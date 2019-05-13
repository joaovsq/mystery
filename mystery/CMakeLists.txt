cmake_minimum_required (VERSION 3.8)

# Compiler definitions / preprocessor defs
add_compile_definitions(MYSTERY_BUILD_EXE)

IF(WIN32)
add_compile_definitions(MYSTERY_PLATFORM_WINDOWS)	
ENDIF()

# dependencies setup, links are done in the end of this file
include_directories(${CMAKE_SOURCE_DIR}/mystery/src)
include_directories(dependencies/include)
set(GLFW_LIB ${CMAKE_SOURCE_DIR}/mystery/dependencies/libs/GLFW/glfw3.lib)

# mystery source files
set(MYSTERY_SRC 
	main.cpp
	src/log.cpp
	src/log.hpp
	src/core.cpp
	src/core.hpp
	src/mystery.cpp
	src/mystery.hpp
	
	src/events/Event.hpp

	src/platform/input.hpp
	src/platform/window.hpp
	src/platform/windows/windows_window.hpp
	src/platform/windows/windows_window.cpp
	src/platform/windows/windows_input.hpp
	src/platform/windows/windows_input.cpp
)

# mystery include files (public api)
set(MYSTERY_INCLUDE 
	mystery_app.hpp
)

set(PRECOMPILED_HEADER myspch.hpp)
set(PRECOMPILED_SOURCE myspch.cpp)

# precompiled headers setup
IF(MSVC)
    GET_FILENAME_COMPONENT(PrecompiledBasename ${PRECOMPILED_HEADER} NAME_WE)
    SET(PrecompiledBinary "${INSTALL_FOLDER}/${PrecompiledBasename}.pch")
    SET(Sources ${${MYSTERY_SRC}})

    SET_SOURCE_FILES_PROPERTIES(${PRECOMPILED_SOURCE}
                                PROPERTIES COMPILE_FLAGS "/Yc\"${PRECOMPILED_HEADER}\" /Fp\"${PrecompiledBinary}\""
                                           OBJECT_OUTPUTS "${PrecompiledBinary}")
    SET_SOURCE_FILES_PROPERTIES(${Sources}
                                PROPERTIES COMPILE_FLAGS "/Yu\"${PRECOMPILED_HEADER}\" /FI\"${PRECOMPILED_HEADER}\" /Fp\"${PrecompiledBinary}\""
                                           OBJECT_DEPENDS "${PrecompiledBinary}")  
    
	LIST(APPEND ${MYSTERY_SRC} ${PRECOMPILED_SOURCE})
ENDIF(MSVC)

# mystery engine library
add_executable (Mystery
			${MYSTERY_SRC}
			${MYSTERY_INCLUDE}
)

# link all necessary libraries
target_link_libraries(Mystery PRIVATE ${GLFW_LIB})

# install targets
install(TARGETS Mystery DESTINATION ${INSTALL_FOLDER})

