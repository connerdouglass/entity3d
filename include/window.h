#pragma once

#include <cstdint>
#include <string>
#include <GLFW/glfw3.h>
#include "root_node.h"

class Window {

    GLFWwindow* handle;
    RootNode rootNode;

public:

    Window();
    ~Window();

    void setTitle(std::string title);
    void setResolution(uint16_t width, uint16_t height);
    void getResolution(uint16_t* width, uint16_t* height) const;

    Node* getRootNode();
    void loop();

    void enterFullscreen();
    void exitFullscreen(
        uint16_t x,
        uint16_t y,
        uint16_t width,
        uint16_t height,
        uint16_t refreshRate
    );

};