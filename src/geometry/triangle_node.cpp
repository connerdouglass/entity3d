#include "geometry/triangle_node.h"

struct Vertex {
    float x, y, z;
    float r, g, b;
};

/**
 * The vertex data used for all triangles rendered
 */
static Vertex TRIANGLE_VERTICES[] = {
    { -0.6f, -0.4f, 0.0f, 1.0f, 0.0f, 0.0f },
    {  0.6f, -0.4f, 0.0f, 0.0f, 1.0f, 0.0f },
    {  0.0f,  0.6f, 0.0f, 0.0f, 0.0f, 1.0f }
};

/**
 * Use the same vertex buffer across all triangles
 */
static GLuint TRIANGLE_VB = 0;

void TriangleNode::update(float dt) {

    // If there is not yet a vertex buffer handle
    if (TRIANGLE_VB == 0) {

        // Create the vertex buffer
        glGenBuffers(1, &TRIANGLE_VB);

        // Bind the buffer
        glBindBuffer(GL_ARRAY_BUFFER, TRIANGLE_VB);

        // Add the vertex data to the buffer
        glBufferData(GL_ARRAY_BUFFER, sizeof(TRIANGLE_VERTICES), TRIANGLE_VERTICES, GL_STATIC_DRAW);

    }

    // If the vertex buffer is zero
    if (this->vertex_buffer == 0) {

        // Save the vertex buffer on this object
        this->vertex_buffer = TRIANGLE_VB;

        // The count of vertices is three
        this->vertices_count = 3;

    }

}
