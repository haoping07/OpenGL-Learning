#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
using namespace std;
void framebuffer_size_callback(GLFWwindow*, int, int);
void processInput(GLFWwindow*);

int main()
{
    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create glfw window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Learn", nullptr, nullptr);
    if (!window)
    {
        cout << "Failed to create window!" << endl;
        glfwTerminate();
        return -1;
    }

    // Set window to current context
    glfwMakeContextCurrent(window);

    // Let GLFW adjusts viewport size when resizing window 
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to init GLAD" << endl;
        return -1;
    }

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        // Process keypress for GLFW window closing
        processInput(window);

        // Set window color after clearing
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        // Clear the window color
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

// glViewport callback function
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    cout << width << " : " << height << endl;
}

// Keypress function
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}