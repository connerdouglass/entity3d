#pragma once

#include "geometry_node.h"
#include <glad/gl.h>

class TriangleNode : public GeometryNode {

public:

    void update(float dt) override;

};
