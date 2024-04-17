#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include "VulkanUtil.h"

#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <optional>
#include <set>
#include <limits>
#include <algorithm>

#include "Shader.h"
#include "Vertex.h"
#include "CommandBuffer.h"
#include "RenderPass.h"
#include "Pipeline.h"
#include "Swapchain.h"

class Swapchain;
class Shader;

const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };

const std::vector<const char*> deviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };

class VulkanBase
{
public:
	VulkanBase();
	void run();

private:

	const std::vector<Vertex2D> vertices
	{
		{ {0.0f, -0.5f}, {1.0f, 1.0f, 1.0f} },
		{ {0.5f,  0.5f}, {0.0f, 1.0f, 0.0f} },
		{ {-0.5f, 0.5f}, {0.0f, 0.0f, 1.0f} }
	};

	void initVulkan();
	void mainLoop();
	void cleanup();
	void createSurface();

	uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties)
	{
		VkPhysicalDeviceMemoryProperties memProperties;
		vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memProperties);

		for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
			if ((typeFilter & (1 << i)) && (memProperties.memoryTypes[i].propertyFlags & properties) == properties)
			{
				return i;
			}
		}

		throw std::runtime_error("failed to find suitable memory type!");
	}

	GLFWwindow* m_pWindow = nullptr;

	CommandBuffer* m_pCommandBuffer = nullptr;
	VkPipelineLayout pipelineLayout;
	RenderPass* m_pRenderPass;
	Pipeline2D* m_pGraphicsPipeline;
	Shader* m_pShader;
	Swapchain* m_pSwapchain;
	//QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	VkBuffer vertexBuffer;
	VkDeviceMemory vertexBufferMemory;

	void drawFrame(uint32_t imageIndex);
	void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
	void createVertexBuffer();

	//void createFrameBuffers();
	//void createGraphicsPipeline();

	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkQueue graphicsQueue;
	VkQueue presentQueue;

	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;
	VkDevice device = VK_NULL_HANDLE;
	VkSurfaceKHR surface;

	VkSemaphore imageAvailableSemaphore;
	VkSemaphore renderFinishedSemaphore;
	VkFence inFlightFence;

	void initWindow();
	void drawScene();

	void pickPhysicalDevice();
	bool isDeviceSuitable(VkPhysicalDevice device);
	void createLogicalDevice();

	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	void setupDebugMessenger();
	std::vector<const char*> getRequiredExtensions();
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);
	void createInstance();

	void createSyncObjects();
	void drawFrame();

	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData) {
		std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;
		return VK_FALSE;
	}
};