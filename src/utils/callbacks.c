#include "utils/callbacks.h"

void error_callback(int code, const char *description)
{
    fprintf(stderr, "GLFW error %d: %s\n", code, description);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // Ignore the Wunused parameter 'window'
    (void)window;
    glViewport(0, 0, width, height);
}