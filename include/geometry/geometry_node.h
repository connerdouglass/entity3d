#pragma once

#include "node.h"
#include <glad/gl.h>

class GeometryNode : public Node {

protected:

    /**
     * The handle for the vertex buffer
     */
    GLuint vertex_buffer;

    /**
     * The number of vertices in the geometry
     */
    GLuint vertices_count;

public:

    GeometryNode();
    void update(float dt) override;
    void render(RenderContext& ctx) const override;

};
