#pragma once

#include <vector>
#include <memory>
#include <e3dmath/e3dmath.h>
#include "render_context.h"

class Node {

    /**
     * The parent node in the hierarchy. Parents own children.
     */
    Node* parent;

    /**
     * The child nodes in the hierarchy
     */
    std::vector< std::shared_ptr<Node> > children;

    /**
     * The position of the node, relative to its parent
     */
    e3d::Vec4 position;

    /**
     * The rotation of the node on each axis
     */
    e3d::Vec3 rotation;

protected:

    void _update(float dt);
    void _render(RenderContext& ctx) const;

public:

    void addChild(std::shared_ptr<Node> child);

    void update(float dt) {};
    void render(RenderContext& ctx) const {};

};
