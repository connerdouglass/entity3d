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

void Node::_render(RenderContext& ctx) const {

    // Push to the render stack
    RenderContextLayer* layer = ctx.push();
    // layer->modelViewMatrix = e3d::utils::mat::mat4_translate(layer->modelViewMatrix, this->position);
    layer->modelViewMatrix = layer->modelViewMatrix * e3d::utils::mat::mat4_create_translation(this->position.x(), this->position.y(), this->position.z());
    // layer->modelViewMatrix = e3d::utils::mat::mat4_rotate_yxz(layer->modelViewMatrix, this->rotation);

    layer->modelViewMatrix = e3d::utils::mat::mat4_create_rotation_y(this->rotation.y()) * layer->modelViewMatrix;

    // Use the program
    if (layer->shaderProgram) {

        // Use the shader program
        layer->shaderProgram->activate();

        // Set the model view matrix
        glUniformMatrix4fv(
            layer->shaderProgram->mvp_uniform,
            1,
            GL_FALSE,
            (const GLfloat*) layer->modelViewMatrix.data
        );

    }

    // Render the node
    this->render(layer);

    // Loop through the children
    for (auto &childPtr : this->children) {

        // Render the child
        childPtr->_render(ctx);

    }

    // Pop from the stack
    ctx.pop();

}