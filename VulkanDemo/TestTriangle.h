//
//  TestTriangle.h
//  VulkanDemo
//
//  Created by star03 on 2022/9/8.
//

#ifndef TestTriangle_h
#define TestTriangle_h

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class TestTriangle {
public:
    void run();
    
private:
    void InitWindow ();
    void InitVulkan ();
    void mainLoop ();
    void CleanUp ();
    void CreateInstance();
    
    VkInstance m_instance;
    GLFWwindow* m_window;
};


#endif /* TestTriangle_h */
