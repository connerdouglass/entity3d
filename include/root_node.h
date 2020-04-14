#pragma once

#include "node.h"

class RootNode : public Node {

public:

    void updateAll(float dt);
    void renderAll() const;

};
