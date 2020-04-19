#include <string>
#include <cstdint>
#include <iostream>
#include <GLFW/glfw3.h>
#include "window.h"
#include "node.h"
#include "timing.h"

#define WIN_DEFAULT_WIDTH 800
#define WIN_DEFAULT_HEIGHT 600
#define WIN_DEFAULT_TITLE "My Window"

Window::Window() {

    // Initialize GLFW
    glfwInit();

    // Set the handle to null
    this->handle = NULL;
    
    // Create the window
    this->handle = glfwCreateWindow(
        WIN_DEFAULT_WIDTH,
        WIN_DEFAULT_HEIGHT,
        WIN_DEFAULT_TITLE,
        NULL,
        NULL
    );
    
}

Window::~Window() {

    // If there is a window
    if (this->handle) {

        // Destroy the window
        glfwDestroyWindow(this->handle);
        this->handle = NULL;

    }

    // Terminate GLFW
    glfwTerminate();

}

void Window::setTitle(std::string title) {

    // If there isn't a handle, break out
    if (!this->handle) return;

    // Set the window title
    glfwSetWindowTitle(this->handle, title.c_str());

}

void Window::setResolution(uint16_t width, uint16_t height) {

    // If there isn't a handle, break out
    if (!this->handle) return;

    // Set the window size
    glfwSetWindowSize(this->handle, (int)width, (int)height);

}

void Window::getResolution(uint16_t* width, uint16_t* height) const {

    // If there isn't a handle, break out
    if (!this->handle) return;

    // Get the window size
    int w, h;
    glfwGetWindowSize(this->handle, &w, &h);

    // Cast and set the values
    *width = uint16_t(w);
    *height = uint16_t(h);

}

Node* Window::getRootNode() {

    // Return a pointer to the node
    return &this->rootNode;

}

void Window::loop() {

    // The timestamp on the previous iteration
    long lastTimestampMs = get_system_time_ms();

    // Loop while the window is open
    while (!glfwWindowShouldClose(this->handle)) {

        // Poll events (mouse, keyboard, resize)
        glfwPollEvents();

        // Get the timestamp now
        long nowMs = get_system_time_ms();

        // Figure out the delta
        long dt = float(nowMs - lastTimestampMs) / 1000.0f;

        // Update the root node
        this->rootNode.updateAll(dt);

        // Render the root node
        this->rootNode.renderAll();

        // Push the last timestamp
        lastTimestampMs = nowMs;

        // Swap the buffers (double-buffering)
        glfwSwapBuffers(this->handle);

        if (glfwGetKey(this->handle, GLFW_KEY_SPACE) == GLFW_PRESS) {
            break;
        } else if (!this->isFullscreen() && glfwGetKey(this->handle, GLFW_KEY_UP) == GLFW_PRESS) {
            this->enterFullscreen();
        } else if (glfwGetKey(this->handle, GLFW_KEY_DOWN) == GLFW_PRESS) {
            this->exitFullscreen(20, 20, 600, 400);
        }

    }

}

bool Window::isFullscreen() const {

    // Get the monitor for the window
    GLFWmonitor* monitor = glfwGetWindowMonitor(this->handle);

    // NULL indicates not fullscreen, non-NULL is fullscreen
    return monitor != NULL;

}

void Window::enterFullscreen() {

    // If there is no handle
    if (!this->handle) return;

    // Get the primary monitor
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();

    // Get the video mode
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    // Make the window fill the monitor
    glfwSetWindowMonitor(
        this->handle,
        monitor,
        0,
        0,
        mode->width,
        mode->height,
        mode->refreshRate);

}

void Window::exitFullscreen(
    uint16_t x,
    uint16_t y,
    uint16_t width,
    uint16_t height) {

    // If there is no handle
    if (!this->handle) return;

    // Exit fullscreen
    glfwSetWindowMonitor(
        this->handle,
        NULL,
        int(x),
        int(y),
        int(width),
        int(height),
        GLFW_DONT_CARE);

}

bool Window::isKeyPressed(int key) const {
    return glfwGetKey(this->handle, key) == GLFW_PRESS;
}
