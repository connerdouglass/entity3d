#pragma once

#include <string>
#include <glad/gl.h>

class ShaderProgram {
public:

    /**
     * The shader program handle
     */
    GLuint handle;

    /**
     * Handles for each of the shaders in the program
     */
    GLuint vert_handle;
    GLuint frag_handle;

    /**
     * The attribute locations exported from the program
     */
    GLint mvp_uniform;
    GLint position_attrib;
    GLint color_attrib;

    ShaderProgram();
    ~ShaderProgram();

    void compile(
        const char* vert,
        const char* frag,
        const char* mvp_uniform_name,
        const char* pos_attrib_name,
        const char* color_attrib_name);

    void activate();

};
