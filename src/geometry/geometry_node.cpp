#include "geometry/geometry_node.h"

GeometryNode::GeometryNode() {

    // Initialize the buffer to zero
    this->vertex_buffer = 0;
    this->vertices_count = 0;

}

void GeometryNode::update(float dt) {

    // Initialize the vertex buffer
    

}

void GeometryNode::render(RenderContextLayer* layer) const {

    if (this->vertex_buffer != 0) {

        // Bind the vertex buffer
        glBindBuffer(GL_ARRAY_BUFFER, this->vertex_buffer);

        
        // These below sections must happen while a buffer is bound

        glEnableVertexAttribArray(layer->shaderProgram->position_attrib);
        glVertexAttribPointer(
            layer->shaderProgram->position_attrib,
            3,
            GL_FLOAT,
            GL_FALSE,
            sizeof(float) * 6,
            (void *) 0
        );

        glEnableVertexAttribArray(layer->shaderProgram->color_attrib);
        glVertexAttribPointer(
            layer->shaderProgram->color_attrib,
            3,
            GL_FLOAT,
            GL_FALSE,
            sizeof(float) * 6,
            (void *)(sizeof(float) * 2)
        );

        // Draw the buffer data
        glDrawArrays(GL_TRIANGLES, 0, this->vertices_count);

    }

}
