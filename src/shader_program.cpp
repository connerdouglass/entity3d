#include "shader_program.h"

ShaderProgram::ShaderProgram() {

    // Initialize the handle to zero
    this->handle = 0;
    this->vert_handle = 0;
    this->frag_handle = 0;

}

ShaderProgram::~ShaderProgram() {

    // Delete the program handle
    if (this->handle) glDeleteProgram(this->handle);

    // Delete the shaders
    if (this->vert_handle) glDeleteShader(this->vert_handle);
    if (this->frag_handle) glDeleteShader(this->frag_handle);

}

void ShaderProgram::compile(
    const char* vert,
    const char* frag,
    const char* mvp_uniform_name,
    const char* pos_attrib_name,
    const char* color_attrib_name) {

    // Create the vertex shader
    this->vert_handle = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(this->vert_handle, 1, &vert, NULL);
    glCompileShader(this->vert_handle);

    // Create the fragment shader
    this->frag_handle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(this->frag_handle, 1, &frag, NULL);
    glCompileShader(this->frag_handle);

    // Create the program
    this->handle = glCreateProgram();
    glAttachShader(this->handle, this->vert_handle);
    glAttachShader(this->handle, this->frag_handle);
    glLinkProgram(this->handle);

    // Get the uniform and attribute locations
    this->mvp_uniform = glGetUniformLocation(this->handle, mvp_uniform_name);
    this->position_attrib = glGetAttribLocation(this->handle, pos_attrib_name);
    this->color_attrib = glGetAttribLocation(this->handle, color_attrib_name);

    glEnableVertexAttribArray(this->position_attrib);
    glVertexAttribPointer(
        this->position_attrib,
        2,
        GL_FLOAT,
        GL_FALSE,
        sizeof(float) * 5,
        (void *) 0
    );

    glEnableVertexAttribArray(this->color_attrib);
    glVertexAttribPointer(
        this->color_attrib,
        3,
        GL_FLOAT,
        GL_FALSE,
        sizeof(float) * 5,
        (void *)(sizeof(float) * 2)
    );

}

void ShaderProgram::activate() {

    // Use the program
    glUseProgram(this->handle);

}
