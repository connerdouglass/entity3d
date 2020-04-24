#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <iostream>
#include <memory>
#include <e3dmath/e3dmath.h>
#include "window.h"
#include "geometry/triangle_node.h"

int main(int argc, const char** argv) {

    // Create the window
    Window win;
    win.setTitle("Hey there");
    win.setResolution(800, 600);
    // win.enterFullscreen();

    // Add our scene to the root node
    std::shared_ptr<TriangleNode> node (new TriangleNode());
    node->position = e3d::Vec4((float[]){ 0, 0, -5, 0 });
    win.getRootNode()->addChild(node);

    // Run the event loop
    win.loop();

}