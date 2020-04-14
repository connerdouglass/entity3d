#include <memory>
#include "node.h"

void Node::addChild(std::shared_ptr<Node> child) {

    this->children.push_back(child);
}

void Node::_update(float dt) {

    // Update this node
    this->update(dt);

    // Loop through all of the children
    for (auto &childPtr : this->children) {

        // Update the child
        childPtr->_update(dt);

    }
}

void Node::_render() const {

    // Render the node
    this->render();

    // Loop through the children
    for (auto &childPtr : this->children) {

        // Render the child
        childPtr->_render();

    }

}