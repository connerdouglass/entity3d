#include "root_node.h"

void RootNode::updateAll(float dt) {

    // Call the update function
    this->_update(dt);

}

void RootNode::renderAll() const {

    // Call the render function
    this->_render();

}
