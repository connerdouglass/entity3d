#include "window.h"
#include <string>
#include <cstdint>
#include <GLFW/glfw3.h>

#define WIN_DEFAULT_WIDTH 800
#define WIN_DEFAULT_HEIGHT 600
#define WIN_DEFAULT_TITLE "My Window"

static int x = 100;

Window::Window() {

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


