cmake_minimum_required (VERSION 3.8)

# TODO: this should not be here
include_directories(mystery/dependencies/include)

# Build types available (Debug is the default):
# Debug and Release
IF(NOT CMAKE_BUID_TYPE)
	set(CMAKE_BUID_TYPE Debug)
ENDIF()

set(INSTALL_FOLDER ${CMAKE_SOURCE_DIR}/build/bin CACHE INTERNAL "Default install folder")

# This will move all static libraries to the output folder 
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${INSTALL_FOLDER})

IF(NOT WIN32)
	message("Mystery only supports Windows platform, wait for it...")
ENDIF()

project ("mystery")

# Include sub-projects.
add_subdirectory ("mystery")

# TODO: decide what to do with the sandbox
#add_subdirectory ("sandbox")