#include "vk_instance.hpp"
#include "vk_graphics.hpp"
#include "platform/window.hpp"

#ifndef VK_EXT_DEBUG_UTILS_EXTENSION_NAME
#define VK_EXT_DEBUG_UTILS_EXTENSION_NAME "VK_EXT_debug_utils"
#endif

namespace Mystery
{
	const std::vector<const char *> VulkanInstance::ValidationLayers = { "VK_LAYER_LUNARG_standard_validation" }; // "VK_LAYER_RENDERDOC_Capture"
	const std::vector<const char *> VulkanInstance::InstanceExtensions = { VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME };
	const std::vector<const char *> VulkanInstance::DeviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME }; // VK_AMD_SHADER_IMAGE_LOAD_STORE_LOD_EXTENSION_NAME,
	// VK_KHR_DESCRIPTOR_UPDATE_TEMPLATE_EXTENSION_NAME, VK_KHR_PUSH_DESCRIPTOR_EXTENSION_NAME

	VKAPI_ATTR VkBool32 VKAPI_CALL CallbackDebug(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode,
		const char *pLayerPrefix, const char *pMessage, void *pUserData)
	{
		LOG_ERROR("Vulkan error: {0}", pMessage);
		return static_cast<VkBool32>(false);
	}

	VkResult VulkanInstance::FvkCreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT *pCreateInfo, const VkAllocationCallbacks *pAllocator,
		VkDebugReportCallbackEXT *pCallback)
	{
		auto func = reinterpret_cast<PFN_vkCreateDebugReportCallbackEXT>(vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT"));

		if (func != nullptr)
		{
			return func(instance, pCreateInfo, pAllocator, pCallback);
		}

		return VK_ERROR_EXTENSION_NOT_PRESENT;
	}

	void VulkanInstance::FvkDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks *pAllocator)
	{
		auto func = reinterpret_cast<PFN_vkDestroyDebugReportCallbackEXT>(vkGetInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT"));

		if (func != nullptr)
		{
			func(instance, callback, pAllocator);
		}
	}

	void VulkanInstance::FvkCmdPushDescriptorSetKHR(VkDevice device, VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set,
		uint32_t descriptorWriteCount, const VkWriteDescriptorSet *pDescriptorWrites)
	{
		auto func = reinterpret_cast<PFN_vkCmdPushDescriptorSetKHR>(vkGetDeviceProcAddr(device, "vkCmdPushDescriptorSetKHR"));

		if (func != nullptr)
		{
			func(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
		}
	}

	uint32_t VulkanInstance::FindMemoryTypeIndex(const VkPhysicalDeviceMemoryProperties *deviceMemoryProperties, const VkMemoryRequirements *memoryRequirements,
		const VkMemoryPropertyFlags &requiredProperties)
	{
		for (uint32_t i = 0; i < deviceMemoryProperties->memoryTypeCount; ++i)
		{
			if (memoryRequirements->memoryTypeBits & (1 << i))
			{
				if ((deviceMemoryProperties->memoryTypes[i].propertyFlags & requiredProperties) == requiredProperties)
				{
					return i;
				}
			}
		}

		throw std::runtime_error("Couldn't find a proper memory type");
		return std::numeric_limits<uint32_t>::max();
	}

	VulkanInstance::VulkanInstance() :
		m_debugReportCallback(VK_NULL_HANDLE),
		m_instance(VK_NULL_HANDLE)
	{
		SetupLayers();
		SetupExtensions();
		CreateInstance();
		CreateDebugCallback();
	}

	VulkanInstance::~VulkanInstance()
	{
		FvkDestroyDebugReportCallbackEXT(m_instance, m_debugReportCallback, nullptr);
		vkDestroyInstance(m_instance, nullptr);
	}

	void VulkanInstance::SetupLayers()
	{
		uint32_t instanceLayerPropertyCount;
		vkEnumerateInstanceLayerProperties(&instanceLayerPropertyCount, nullptr);
		std::vector<VkLayerProperties> instanceLayerProperties(instanceLayerPropertyCount);
		vkEnumerateInstanceLayerProperties(&instanceLayerPropertyCount, instanceLayerProperties.data());

#if defined(MYSTERY_DEBUG)
		LogVulkanLayers(instanceLayerProperties);
#endif

		// Sets up the layers.
#if defined(MYSTERY_DEBUG)
		for (const auto &layerName : ValidationLayers)
		{
			bool layerFound = false;

			for (const auto &layerProperties : instanceLayerProperties)
			{
				if (strcmp(layerName, layerProperties.layerName) == 0)
				{
					layerFound = true;
					break;
				}
			}

			if (!layerFound)
			{
				LOG_ERROR("Vulkan validation layer not found: {0}", layerName);
			}

			m_instanceLayers.emplace_back(layerName);
		}
#endif

		for (const auto &layerName : DeviceExtensions)
		{
			m_deviceExtensions.emplace_back(layerName);
		}
	}

	void VulkanInstance::SetupExtensions()
	{
		// Sets up the extensions.
		auto instanceExtensions = Window::Get()->GetInstanceExtensions();

		for (uint32_t i = 0; i < instanceExtensions.second; i++)
		{
			m_instanceExtensions.emplace_back(instanceExtensions.first[i]);
		}

		for (const auto &instanceExtension : InstanceExtensions)
		{
			m_instanceExtensions.emplace_back(instanceExtension);
		}

#if defined(MYSTERY_DEBUG) 
		m_instanceExtensions.emplace_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
		m_instanceExtensions.emplace_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
#endif
	}

	void VulkanInstance::CreateInstance()
	{
		VkApplicationInfo applicationInfo = {};
		applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		applicationInfo.pApplicationName = "Mystery Game";
		applicationInfo.applicationVersion = VK_MAKE_VERSION(0, 1, 0);
		applicationInfo.pEngineName = "Mysyery Engine";
		applicationInfo.engineVersion = VK_MAKE_VERSION(0, 11, 2);
		applicationInfo.apiVersion = VK_MAKE_VERSION(1, 1, 0);

		VkInstanceCreateInfo instanceCreateInfo = {};
		instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		instanceCreateInfo.pApplicationInfo = &applicationInfo;
		instanceCreateInfo.enabledLayerCount = static_cast<uint32_t>(m_instanceLayers.size());
		instanceCreateInfo.ppEnabledLayerNames = m_instanceLayers.data();
		instanceCreateInfo.enabledExtensionCount = static_cast<uint32_t>(m_instanceExtensions.size());
		instanceCreateInfo.ppEnabledExtensionNames = m_instanceExtensions.data();
		
		VulkanGraphics::CheckVk(vkCreateInstance(&instanceCreateInfo, nullptr, &m_instance));
	}

	void VulkanInstance::CreateDebugCallback()
	{
#if defined(MYSTERY_DEBUG)
		VkDebugReportCallbackCreateInfoEXT debugReportCallbackCreateInfo = {};
		debugReportCallbackCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
		debugReportCallbackCreateInfo.pNext = nullptr;
		debugReportCallbackCreateInfo.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT | VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT;
		debugReportCallbackCreateInfo.pfnCallback = &CallbackDebug;
		debugReportCallbackCreateInfo.pUserData = nullptr;
		
		VulkanGraphics::CheckVk(FvkCreateDebugReportCallbackEXT(m_instance, &debugReportCallbackCreateInfo, nullptr, &m_debugReportCallback));
#endif
	}

	void VulkanInstance::LogVulkanLayers(const std::vector<VkLayerProperties> &layerProperties)
	{
		LOG_INFO("-- VulkanInstance --\n");
		LOG_INFO("Layers: ");

		for (const auto &layer : layerProperties)
		{
			LOG_INFO("{0}, ", layer.layerName);
		}

		LOG_INFO("\n-- Done --\n");
	}
}
