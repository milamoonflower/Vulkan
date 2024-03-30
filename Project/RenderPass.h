#pragma once
#include "vulkan/vulkan_core.h"
#include <vector>

class RenderPass final
{
public:
	RenderPass(VkDevice device, VkFormat swapchainImageFormat);
	~RenderPass();

	RenderPass(RenderPass&&) = delete;
	RenderPass(const RenderPass&) = delete;
	RenderPass& operator=(RenderPass&&) = delete;
	RenderPass& operator=(const RenderPass&) = delete;

	void Begin(const std::vector<VkFramebuffer>& swapChainFrameBuffers, uint32_t imageIndex, const VkExtent2D& swapChainExtent, VkCommandBuffer commandBuffer);
	void End(VkCommandBuffer commandBuffer);

	inline VkRenderPass GetRenderPass() const { return m_RenderPass; }

private:
	VkDevice m_Device;
	VkRenderPass m_RenderPass{};
};
