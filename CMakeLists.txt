cmake_minimum_required(VERSION 3.20)
project(voxels)

# ======================================================
# CMAKE VARIABLES
# ======================================================
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ======================================================
# THIRD-PARTY DEPENDENCIES
# ======================================================
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

# ======================================================
# DEFINE PROJECT
# ======================================================
# Sources
set(SRC_FOLDER src)
set(UTILS_FOLDER ${SRC_FOLDER}/utils)
set(CORE_FOLDER ${SRC_FOLDER}/core)
set(SOURCES
    ${SRC_FOLDER}/main.c
    ${UTILS_FOLDER}/callbacks.c
    ${CORE_FOLDER}/processing.c
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Includes
target_include_directories(${PROJECT_NAME} PRIVATE
    inc/
)

# Flags
target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall -Wextra -Werror
    -O3 -march=native -ffast-math
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    OpenGL::GL
)