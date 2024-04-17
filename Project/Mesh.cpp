#include "Mesh.h"

Mesh2D::Mesh2D()
{

}

void Mesh2D::DestroyMesh(const VkDevice& device, const VkDescriptorSetLayout& layout)
{

}

/*
void Mesh2D::Draw(const VkPipelineLayout & pipelineLayout, const VkCommandBuffer & commandBuffer)
{
	/ *m_VertexBuffer->BindAsVertexBuffer(commandBuffer);
	m_IndexBuffer->BindAsIndexBuffer(commandBuffer);
	vkCmdPushConstants(
		commandBuffer,
		pipelineLayout,
		VK_SHADER_STAGE_VERTEX_BIT,
		0,
		sizeof(MeshData),
		&m_VertexConstant);

	vkCmdDrawIndexed(commandBuffer, static_cast<uint32_t>(m_Indexes.size()), 1, 0, 0, 0);* /
}*/

void Mesh2D::Draw(const VkPipelineLayout& pipelineLayout, const VkCommandBuffer& commandBuffer) const
{
	/*VkBuffer vertexBuffers[] = { *m_pVertexBuffer };
	VkDeviceSize offsets[] = { 0 };
	vkCmdBindVertexBuffers(commandBuf, 0, 1, vertexBuffers, offsets);
	vkCmdBindIndexBuffer(commandBuf, *m_pIndexBuffer, 0, VK_INDEX_TYPE_UINT32);

	vkCmdDrawIndexed(commandBuf, m_NumIndices, 1, 0, 0, 0);*/
}
