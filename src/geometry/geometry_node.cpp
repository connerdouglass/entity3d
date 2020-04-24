#include "geometry/geometry_node.h"

GeometryNode::GeometryNode() {

    // Initialize the buffer to zero
    this->vertex_buffer = 0;
    this->vertices_count = 0;

}

void GeometryNode::update(float dt) {

    // Initialize the vertex buffer
    

}

void GeometryNode::render(RenderContext& ctx) const {
std::cout << "Render geometry" << std::endl;
    // If there is a vertex buffer
    if (this->vertex_buffer != 0) {

        // Bind the vertex buffer
        glBindBuffer(GL_ARRAY_BUFFER, this->vertex_buffer);

        // Draw the buffer data
        glDrawArrays(GL_TRIANGLES, 0, this->vertices_count);
    
    }

}
