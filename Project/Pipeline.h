#pragma once
#include "vulkan/vulkan_core.h"
#include <vector>
#include <stdexcept>
#include <memory>

class Pipeline2D final
{
public:
	Pipeline2D();
	Pipeline2D(VkDevice device, VkRenderPass renderPass);
	~Pipeline2D();

	void Draw(class CommandBuffer& commandBuffer, const VkExtent2D& swapChainExtent) const;
	void AddMesh(class Mesh2D&& mesh);

	inline VkPipeline GetPipeline() const { return m_Pipeline; }

private:
	VkDevice m_Device{};
	VkPipeline m_Pipeline{};
	VkPipelineLayout m_Layout{};

	VkRenderPass m_RenderPass{};

	std::unique_ptr<class Shader> m_pShader = nullptr;
	std::vector<class Mesh2D> m_Meshes;

	void DrawScene(VkCommandBuffer commandBuffer) const;
};
