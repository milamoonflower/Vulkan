#pragma once
#include <vulkan/vulkan_core.h>
#include <vector>
#include <string>
#include <array>

class Shader
{
public:
	Shader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
	~Shader() = default;

	void Initialize(const VkDevice& vkDevice);
	std::vector<VkPipelineShaderStageCreateInfo>& GetShaderStages() { return m_ShaderStages; };
	void DestroyShaderModules(const VkDevice& vkDevice);

	VkPipelineShaderStageCreateInfo createFragmentShaderInfo(const VkDevice& vkDevice);
	VkPipelineShaderStageCreateInfo createVertexShaderInfo(const VkDevice& vkDevice);
	VkPipelineVertexInputStateCreateInfo createVertexInputStateInfo();
	VkPipelineInputAssemblyStateCreateInfo createInputAssemblyStateInfo();

private:
	
	VkShaderModule createShaderModule(const VkDevice& vkDevice, const std::vector<char>& code);

	std::string m_VertexShaderFile;
	std::string m_FragmentShaderFile;
	std::vector<VkPipelineShaderStageCreateInfo> m_ShaderStages;

	VkVertexInputBindingDescription m_BindingDescription;
	std::array<VkVertexInputAttributeDescription, 2> m_AttributeDescriptions;
};