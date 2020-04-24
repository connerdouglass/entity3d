#include "render_context.h"

RenderContext::RenderContext() {

    // Default to the topmost being NULL
    this->top = NULL;

}

RenderContext::~RenderContext() {

    // Pop all the layers until everything is deleted
    while (this->top != NULL) this->pop();

}

RenderContextLayer* RenderContext::push() {

    // Create a new render context
    RenderContextLayer* newTop = new RenderContextLayer();

    // If there is already a top
    if (this->top != NULL) {

        // Copy the parent matrix as the starting point for this one
        newTop->modelViewMatrix = e3d::Mat4(this->top->modelViewMatrix);

        // Copy the pointer to the shader program
        newTop->shaderProgram = this->top->shaderProgram;

    } else {

        // Default to the identity matrix
        newTop->modelViewMatrix = e3d::Mat4::identity();

        // Set the shader program to null
        newTop->shaderProgram = NULL;

    }

    // Move the new layer to the top
    newTop->parent = this->top;
    this->top = newTop;

    // Return the new layer
    return newTop;
    
}

void RenderContext::pop() {

    // If there is no top layer, return here
    if (this->top == NULL) return;

    // Get the parent of the top layer
    RenderContextLayer* parent = this->top->parent;

    // Delete the top layer
    delete this->top;

    // Make the parent the new topmost layer
    this->top = parent;
    
}
