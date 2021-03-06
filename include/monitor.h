#pragma once

#include <vector>
#include <GLFW/glfw3.h>

class Monitor {

    GLFWmonitor* handle;

public:

    static std::vector<Monitor> all();
    static Monitor primary();

    Monitor(GLFWmonitor* handle);

};
