#include "physics/physics_node.h"

PhysicsNode::PhysicsNode() {

    // Initialize the values to zero
    this->velocity = e3d::Vec4::zeros();
    this->angular_velocity = e3d::Vec3::zeros();

}

void PhysicsNode::update(float dt) {

    // Update the position
    this->position = this->position + this->velocity * dt;

    // Update the rotation
    this->rotation = this->rotation + this->angular_velocity * dt;

}
