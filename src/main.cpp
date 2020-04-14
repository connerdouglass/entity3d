#include <iostream>
#include "window.h"

int main(int argc, char** argv) {

    // Create the window
    Window win;
    win.setTitle("Hey there");
    win.setResolution(800, 600);

    // Add our scene to the root node
    // ...

    // Run the event loop
    win.loop();

}