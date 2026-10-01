#include <stdio.h>

#include "opengl.h"

#include "utils/retcodes.h"
#include "utils/callbacks.h"
#include "core/processing.h"

int main()
{
    // Set callback to trap errors
    glfwSetErrorCallback(error_callback);
    
    // Initialize GLFW
    if (!glfwInit())
    {
        return ERROR;        
    }

    // Set OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    
    // Set OpenGL profile
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    // Create a windowed mode window (and, implicitly, its OpenGL context)
    GLFWwindow* window = glfwCreateWindow(800, 600, "First Window", NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return ERROR;
    }

    // Assign the created context to this thread
    glfwMakeContextCurrent(window);
    
    // Tell OpenGL how to render in the window (viewport), and add a handler for when the window is resized
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Life loop
    while(!glfwWindowShouldClose(window))
    {
        // Process input
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Once we exit the loop, clean up
    glfwTerminate();

    // Return with no errors
    return SUCCESS;
}