#include <cstdint>
#include <string>
#include <GLFW/glfw3.h>

class Window {

    GLFWwindow* handle;

public:

    Window();
    ~Window();

    void setTitle(std::string title);
    void setResolution(uint16_t width, uint16_t height);
    void getResolution(uint16_t* width, uint16_t* height) const;

};