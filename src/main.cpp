#include <iostream>
#include <GLFW/glfw3.h>
#include "window.h"

int main(int argc, char** argv) {

    // int x = 10;
    // uint8_t y = 10;
    // std::cout << "x: " << x << " y: " << y << std::endl;

    glfwInit();

    // std::cout << "Hello world" << std::endl;

    // Create the window
    Window win;
    win.setTitle("Hey there");
    win.setResolution(800, 600);

    // // Loop while the window is open
    // while (!glfwWindowShouldClose(window)) {

    //     // Poll events (mouse, keyboard, resize)
    //     glfwPollEvents();

    //     // Swap the buffers (double-buffering)
    //     glfwSwapBuffers(window);

    // }

    // glfwDestroyWindow(window);

    glfwTerminate();

}