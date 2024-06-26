# Source files
set(SHADER_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/shaders")
set(SHADER_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/shaders")

file(GLOB_RECURSE GLSL_SOURCE_FILES
    "${SHADER_SOURCE_DIR}/*.frag"
    "${SHADER_SOURCE_DIR}/*.vert"
)

foreach(GLSL ${GLSL_SOURCE_FILES})
    get_filename_component(FILE_NAME ${GLSL} NAME)
    set(SPIRV "${SHADER_BINARY_DIR}/${FILE_NAME}.spv")
    add_custom_command(
        OUTPUT ${SPIRV}
        COMMAND ${Vulkan_GLSLC_EXECUTABLE} ${GLSL} -o ${SPIRV}
        DEPENDS ${GLSL}
    )
    list(APPEND SPIRV_BINARY_FILES ${SPIRV})
endforeach(GLSL)

add_custom_target(
    Shaders 
    DEPENDS ${SPIRV_BINARY_FILES}
)


set(SOURCES
    "main.cpp"
    "vulkanbase/VulkanBase.h" 
    "vulkanbase/VulkanUtil.h"
    "vulkanbase/VulkanUtil.cpp"
    # Add other source files here
    
    "labwork/Week02.cpp" 
     
     
    "labwork/Week05.cpp"
    "labwork/Week06.cpp"
 "Shader.h" "Shader.cpp")

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${GLSL_SOURCE_FILES}  "Vertex.h" "glm/glm/glm.hpp" "Mesh.h" "Mesh.cpp"  "CommandBuffer.h" "CommandBuffer.cpp"   "Camera.h" "RenderPass.h" "RenderPass.cpp" "Pipeline.h"  "vulkanbase/VulkanBase.cpp" "Pipeline.cpp" "Swapchain.h" "Swapchain.cpp")
add_dependencies(${PROJECT_NAME} Shaders)
# Link libraries
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Vulkan_LIBRARIES} glfw)