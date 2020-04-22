#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <iostream>
#include <memory>
#include "window.h"
// #include <e3dmath/e3dmath.h>

int main(int argc, char** argv) {

    // Create the window
    Window win;
    win.setTitle("Hey there");
    win.setResolution(800, 600);
    // win.enterFullscreen();

    // Add our scene to the root node
    // ...
    // std::shared_ptr<Node> node (new Node());
    // win.getRootNode()->addChild(node);

    // Run the event loop
    win.loop();

}