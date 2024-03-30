#pragma once
#include "vulkan/vulkan_core.h"

class CommandBuffer final
{
public:
	CommandBuffer() = default;
	~CommandBuffer();

	void Initialize(VkDevice device, uint32_t queueFamilyIndex);
	VkCommandBuffer& GetCommandBuffer() { return m_CommandBuffer; }

	void Begin();
	void End();

private:
	static VkCommandPool commandPool;
	static uint32_t bufferCount;

	VkCommandBuffer m_CommandBuffer;
	VkDevice m_Device;
};
