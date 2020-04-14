#pragma once

#include <vector>
#include <memory>

class Node {

    /**
     * The parent node in the hierarchy. Parents own children.
     */
    Node* parent;

    /**
     * The child nodes in the hierarchy
     */
    std::vector< std::shared_ptr<Node> > children;

protected:

    void _update(float dt);
    void _render() const;

public:

    void addChild(std::shared_ptr<Node> child);

    void update(float dt) {};
    void render() const {};

};
