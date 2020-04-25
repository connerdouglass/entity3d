#pragma once

#include <e3dmath/e3dmath.h>
#include "node.h"

class PhysicsNode : public Node {

public:

    PhysicsNode();

    e3d::Vec4 velocity;
    e3d::Vec3 angular_velocity;

    void update(float dt) override;

};
