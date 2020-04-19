#include <GLFW/glfw3.h>
#include <vector>
#include "monitor.h"

std::vector<Monitor> Monitor::all() {

    // Get the monitors
    int count;
    GLFWmonitor** mons = glfwGetMonitors(&count);

    // Create the vector
    std::vector<Monitor> monitors;

    // Loop through the count
    for (int i = 0; i < count; i++) {

        // Get the monitor
        monitors.push_back(Monitor(mons[i]));

    }

    // Return the vector
    return monitors;

}

Monitor Monitor::primary() {

    // Get the primary monitor
    GLFWmonitor* primary = glfwGetPrimaryMonitor();

    // Create a Monitor wrapper
    return Monitor(primary);

}

Monitor::Monitor(GLFWmonitor* handle) {

    // Save the handle
    this->handle = handle;

}
