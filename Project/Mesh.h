#pragma once
#include "Vertex.h"
#include <vector>

class Mesh2D final
{
public:
	Mesh2D();
	~Mesh2D() = default;

	void DestroyMesh(const VkDevice& device, const VkDescriptorSetLayout& layout);
	void Draw(const VkPipelineLayout& pipelineLayout, const VkCommandBuffer& commandBuffer) const;
	void AddVertex(glm::vec2 pos, glm::vec3 color);
	void Initialize(const VkPhysicalDevice& physicalDevice, const VkDevice& device, const std::vector<Vertex2D> vertices, std::vector<uint16_t> indices);

private:
	VkBuffer m_VkBuffer;
	VkDeviceMemory m_VkDeviceMemory;

	std::vector<Vertex2D> m_Vertices{};
	std::vector<uint32_t> m_Indices{};
	int m_IndicesCount{};
	int m_VerticesCount{};
};
