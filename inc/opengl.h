#ifndef OPENGL_H
#define OPENGL_H

#if defined(__APPLE__)
    // Apple's OpenGL framework exports every OpenGL 4.1 core function directly
    #define GL_SILENCE_DEPRECATION
    #include <OpenGL/gl3.h>
#else
    // Mesa's libGL exports modern functions, the prototypes just need to be enabled
    #define GL_GLEXT_PROTOTYPES
    #include <GL/gl.h>
    #include <GL/glext.h>
#endif

// Stop GLFW from including its own OpenGL header on top of ours
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#endif // OPENGL_H
