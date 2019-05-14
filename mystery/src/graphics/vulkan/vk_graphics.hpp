#pragma once

#include <vulkan/vulkan.h>
#include "core.hpp"

namespace Mystery {

	class VulkanGraphics
	{
	public:
		VulkanGraphics();
		~VulkanGraphics();


		static std::string StringifyResultVk(const VkResult &result);
		static void CheckVk(const VkResult &result);

	private:
	
	};

}