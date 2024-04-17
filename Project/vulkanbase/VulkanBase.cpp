#include "VulkanBase.h"

VulkanBase::VulkanBase()
{

}

void VulkanBase::run()
{
	initWindow();
	initVulkan();
	mainLoop();
	cleanup();
}

void VulkanBase::initWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	m_pWindow = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
}

void VulkanBase::initVulkan()
{
	// week 06
	createInstance();
	setupDebugMessenger();
	createSurface();

	// week 05
	pickPhysicalDevice();
	createLogicalDevice();

	//createRenderPass();
	m_pRenderPass = new RenderPass(device, m_pSwapchain->GetImageFormat());
	//createGraphicsPipeline();
	m_pGraphicsPipeline = new Pipeline2D(device, m_pRenderPass->GetRenderPass());
	m_pSwapchain->createFramebuffers(m_pRenderPass->GetRenderPass());
	// week 02

	QueueFamilyIndices queueFamilyIndices = findQueueFamilies(physicalDevice);
	m_pCommandBuffer = new CommandBuffer();
	m_pCommandBuffer->Initialize(device, queueFamilyIndices.graphicsFamily.value());
	createVertexBuffer();

	// week 06
	createSyncObjects();
}

void VulkanBase::mainLoop()
{
	while (!glfwWindowShouldClose(m_pWindow))
	{
		glfwPollEvents();
		// week 06
		drawFrame();
	}
	vkDeviceWaitIdle(device);
}

void VulkanBase::cleanup()
{
	vkDestroySemaphore(device, renderFinishedSemaphore, nullptr);
	vkDestroySemaphore(device, imageAvailableSemaphore, nullptr);
	vkDestroyFence(device, inFlightFence, nullptr);

	//vkDestroyPipeline(device, graphicsPipeline.GetPipeline(), nullptr);
	//vkDestroyPipelineLayout(device, pipelineLayout, nullptr);
	//vkDestroyRenderPass(device, renderPass.GetRenderPass(), nullptr);

	if (enableValidationLayers)
	{
		DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
	}

	vkDestroyDevice(device, nullptr);

	vkDestroySurfaceKHR(instance, surface, nullptr);
	vkDestroyInstance(instance, nullptr);

	vkDestroyBuffer(device, vertexBuffer, nullptr);
	vkFreeMemory(device, vertexBufferMemory, nullptr);

	glfwDestroyWindow(m_pWindow);
	glfwTerminate();
}

void VulkanBase::createSurface()
{
	if (glfwCreateWindowSurface(instance, m_pWindow, nullptr, &surface) != VK_SUCCESS)
	{
		throw std::runtime_error("failed to create window surface!");
	}
}

void VulkanBase::drawScene()
{
	VkBuffer vertexBuffers[] = { vertexBuffer };
	VkDeviceSize offsets[] = { 0 };
	vkCmdBindVertexBuffers(m_pCommandBuffer->GetCommandBuffer(), 0, 1, vertexBuffers, offsets);

	vkCmdDraw(m_pCommandBuffer->GetCommandBuffer(), static_cast<uint32_t>(vertices.size()), 1, 0, 0);
}