cmake_minimum_required(VERSION 3.10)

# Define our project
project(GameEngine VERSION 1.0)

# Use C++17 for the build
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(EXECUTABLE_OUTPUT_PATH "out")

# Add library directories
add_subdirectory("${PROJECT_SOURCE_DIR}/deps/glfw")

# Create the GameEngine executable target
add_executable(
    GameEngine
    src/main.cpp
    # src/math/matrix.cpp
    src/monitor.cpp
    src/node.cpp
    src/render_context.cpp
    src/root_node.cpp
    src/timing.cpp
    src/window.cpp
)

# Link all dependencies to the GameEngine
target_link_libraries(GameEngine PUBLIC glfw)

# Add the include directories to the GameEngine
target_include_directories(
    GameEngine PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/deps/glfw/include"
    "${PROJECT_SOURCE_DIR}/deps/entity3d-math/include"
)
