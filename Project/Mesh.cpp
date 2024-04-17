#include "Mesh.h"

Mesh2D::Mesh2D()
{

}

void Mesh2D::DestroyMesh(const VkDevice& device, const VkDescriptorSetLayout& layout)
{

}

void Mesh2D::Draw(const VkPipelineLayout& pipelineLayout, const VkCommandBuffer& commandBuffer) const
{
	VkBuffer vertexBuffers[] = { m_VkBuffer };
	VkDeviceSize offsets[] = { 0 };
	vkCmdBindVertexBuffers(commandBuffer, 0, 1, vertexBuffers, offsets);
	vkCmdDraw(commandBuffer, static_cast<uint32_t>(m_VerticesCount), 1, 0, 0);
}

void Mesh2D::Initialize(const VkPhysicalDevice& physicalDevice, const VkDevice& device, const std::vector<Vertex2D> vertices, std::vector<uint16_t> indices)
{

}
