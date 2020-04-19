#pragma once

#include <stack>

struct RenderContextLayer {

    /**
     * The parent layer to this one. These layers form a
     * singly-linked list which can be traversed by parents.
     */
    RenderContextLayer* parent;

};

class RenderContext {

    /**
     * The top context config in the stack
     */
    RenderContextLayer* top;

public:

    RenderContext();
    ~RenderContext();

    /**
     * Pushes a new render context to the top, and returns a pointer
     * to it. The caller is responsible for calling pop() when it's done
     * with the layer pointer, to free its associated memory. Failing to call
     * pop() will result in rendering issues, not just memory leaks.
     */
    RenderContextLayer* push();

    /**
     * Pops the topmost render context from the stack
     */
    void pop();

};