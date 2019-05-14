cmake_minimum_required (VERSION 3.8)

# Compiler definitions / preprocessor defs
add_compile_definitions(MYSTERY_BUILD_EXE)
add_compile_definitions(MYSTERY_DEBUG)

IF(WIN32)
add_compile_definitions(MYSTERY_PLATFORM_WINDOWS)	
ENDIF()


# dependencies setup, links are done in the end of this file
include_directories(${CMAKE_SOURCE_DIR}/mystery/src
					dependencies/include
)

set(GLFW_LIB ${CMAKE_SOURCE_DIR}/mystery/dependencies/libs/GLFW/glfw3.lib)

# Finds and loads Vulkan, env "VULKAN_SDK" must be set
find_package(Vulkan REQUIRED)

# This uses target_sources to define its headers & source files
include(CMakeSources.cmake)

set(PRECOMPILED_HEADER StdAfx.hpp)
set(PRECOMPILED_SOURCE StdAfx.cpp)

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

# mystery engine 
add_executable (Mystery
			${MYSTERY_SRC}
			${MYSTERY_INCLUDE}
)

# link all necessary libraries
target_link_libraries(Mystery PRIVATE 
							${GLFW_LIB}
							Vulkan::Vulkan
)

# install targets
install(TARGETS Mystery DESTINATION ${INSTALL_FOLDER})

