//
//  main.cpp
//  VulkanDemo
//
//  Created by star03 on 2022/8/31.
//

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>

#include "physics/Physic.h"
#include "TestTriangle.h"


//int main() {
//    glfwInit();
//
//    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
//    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);
//
//    uint32_t extensionCount = 0;
//    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
//
//    std::cout << extensionCount << " extensions supported\n";
//
//    glm::mat4 matrix;
//    glm::vec4 vec;
//    auto test = matrix * vec;
//
//    while(!glfwWindowShouldClose(window)) {
//        glfwPollEvents();
//
////        vkCmdDraw(<#VkCommandBuffer commandBuffer#>, 0, 0, 0, 0);
//
//
//    }
//
//    glfwDestroyWindow(window);
//    glfwTerminate();
//
//    return 0;
//}

int main() {
    TestTriangle app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
