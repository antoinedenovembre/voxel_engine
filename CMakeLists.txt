cmake_minimum_required(VERSION 3.20)
project(voxels C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Sources
file(GLOB_RECURSE SOURCES src/*.c)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Includes
target_include_directories(${PROJECT_NAME} PRIVATE
    inc/
    lib/glad/
    lib/stb/
)

# Flags
target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall -Wextra -Werror
    -O3 -march=native -ffast-math
)

# Dépendances système
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    OpenGL::GL
)