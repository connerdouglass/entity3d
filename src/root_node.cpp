#include "root_node.h"
#include "render_context.h"

void RootNode::updateAll(float dt) {

    // Call the update function
    this->_update(dt);

}

void RootNode::renderAll() const {

    // Create a rendering context for this pass
    RenderContext ctx;

    // Push a layer for the root
    RenderContextLayer* layer = ctx.push();

    // Call the render function
    this->_render(ctx);

    // Pop the layer
    ctx.pop();

}
