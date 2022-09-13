//
//  TestTriangle.cpp
//  VulkanDemo
//
//  Created by star03 on 2022/9/8.
//
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <stdio.h>
#include <vector>

#include "TestTriangle.h"

void TestTriangle::CreateInstance() {
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

//    createInfo.enabledExtensionCount = glfwExtensionCount;
//    createInfo.ppEnabledExtensionNames = glfwExtensions;
//
//    createInfo.enabledLayerCount = 0;
//
//    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
//        throw std::runtime_error("failed to create instance!");
//    }
    //mac修正
    std::vector<const char*> requiredExtensions;

    for(uint32_t i = 0; i < glfwExtensionCount; i++) {
        requiredExtensions.emplace_back(glfwExtensions[i]);
    }

    requiredExtensions.emplace_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);

    createInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;

    createInfo.enabledExtensionCount = (uint32_t) requiredExtensions.size();
    createInfo.ppEnabledExtensionNames = requiredExtensions.data();

    if (vkCreateInstance(&createInfo, nullptr, &m_instance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance!");
    }
}

void TestTriangle::run() {
    InitWindow();
    //初始化环境
    InitVulkan();
    //?
    mainLoop();
    //清理？
    CleanUp();
}

void TestTriangle::InitWindow () {
    glfwInit();
    
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    m_window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
}

void TestTriangle::InitVulkan () {
    CreateInstance();
}

void TestTriangle::mainLoop () {
    while (!glfwWindowShouldClose(m_window)) {
        glfwPollEvents();
    }
}

void TestTriangle::CleanUp () {
    vkDestroyInstance(m_instance, nullptr);
    glfwDestroyWindow(m_window);
    glfwTerminate();
}
