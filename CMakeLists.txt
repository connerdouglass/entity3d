cmake_minimum_required(VERSION 3.10)

# Define our project
project(GameEngine VERSION 1.0)

# Use C++17 for the build
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(EXECUTABLE_OUTPUT_PATH "out")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Add library directories
add_subdirectory("${PROJECT_SOURCE_DIR}/deps/glfw")

# Create the GameEngine executable target
add_executable(
    GameEngine
    deps/glfw/deps/glad_gl.c
    src/main.cpp
    src/monitor.cpp
    src/node.cpp
    src/render_context.cpp
    src/root_node.cpp
    src/shader_program.cpp
    src/timing.cpp
    src/window.cpp
)

# Link all dependencies to the GameEngine
target_link_libraries(GameEngine glfw)

# Add the include directories to the GameEngine
target_include_directories(
    GameEngine PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/deps/glfw/include"
    "${PROJECT_SOURCE_DIR}/deps/glfw/deps"
    "${PROJECT_SOURCE_DIR}/deps/entity3d-math/include"
)
