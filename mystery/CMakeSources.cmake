
# mystery source files
set(MYSTERY_SRC 
	main.cpp
	src/log.cpp
	src/core.cpp
	src/mystery.cpp
	src/platform/keyboard.cpp
	src/platform/monitor.cpp
	src/platform/mouse.cpp
	src/platform/window.cpp
	src/graphics/vulkan/vk_graphics.cpp
	src/graphics/vulkan/vk_instance.cpp
	src/graphics/vulkan/vk_logical_device.cpp
	src/graphics/vulkan/vk_physical_device.cpp
	src/graphics/vulkan/vk_surface.cpp
)

set(MYSTERY_HEADERS
	src/log.hpp
	src/core.hpp
	src/mystery.hpp
	src/events/Event.hpp
	src/platform/keyboard.cpp
	src/platform/monitor.cpp
	src/platform/mouse.cpp
	src/platform/window.cpp
	src/graphics/vulkan/vk_graphics.hpp
	src/graphics/vulkan/vk_instance.hpp
	src/graphics/vulkan/vk_logical_device.hpp
	src/graphics/vulkan/vk_physical_device.hpp
	src/graphics/vulkan/vk_surface.hpp
)

# mystery include files (public api)
set(MYSTERY_INCLUDE 
	mystery_app.hpp
)