#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <stdio.h>

#include "opengl.h"

// GLFW error callback
void error_callback(int code, const char *description);

// GLFW resize callback
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

#endif // CALLBACKS_H