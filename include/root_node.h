#pragma once

#include "node.h"

class RootNode : public Node {

public:

    void updateAll(float dt);
    void renderAll(e3d::Mat4& p, ShaderProgram* sp) const;

};
