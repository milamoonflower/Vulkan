#pragma once
#include <vector>
#include "glm\glm\glm.hpp"
#include "vulkanbase/VulkanBase.h"

class Swapchain
{
public:
	Swapchain(VkDevice device, VkSurfaceKHR surface, const glm::ivec2& surfaceSize);
	void createFramebuffers(VkRenderPass renderPass);

	~Swapchain();

	inline VkExtent2D GetExtent() const { return m_Extent; }
	inline std::vector<VkFramebuffer> GetFramebuffers() const { return m_Framebuffers; }

	inline uint32_t GetImageCount() const {}
	inline VkFormat GetImageFormat() const { return m_ImageFormat; }
	inline VkSwapchainKHR GetSwapchain() const { return m_Swapchain; }

private:

	struct SwapChainSupportDetails
	{
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	VkDevice m_Device;
	VkPhysicalDevice m_PhysicalDevice;
	VkSwapchainKHR m_Swapchain;
	std::vector<VkImage> m_Images;
	std::vector<VkImageView> m_ImageViews;
	VkFormat m_ImageFormat;
	VkExtent2D m_Extent;
	std::vector<VkFramebuffer> m_Framebuffers;

	SwapChainSupportDetails querySwapChainSupport(VkSurfaceKHR surface);
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities, const glm::ivec2& surfaceSize);
	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	void createSwapchain(VkSurfaceKHR surface, const glm::ivec2& surfaceSize);
	void createImageViews();
};
