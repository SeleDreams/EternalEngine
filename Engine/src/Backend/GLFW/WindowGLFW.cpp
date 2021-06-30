#include <Backend/GLFW/WindowGLFW.hpp>

using namespace EternalEngine;

WindowGLFW::WindowGLFW()
{
    _window = nullptr;
}

WindowGLFW::~WindowGLFW()
{
    if (_window)
    {
        glfwDestroyWindow(_window);
    }
    glfwTerminate();
}

void WindowGLFW::resize_window(unsigned int new_width,unsigned int new_height)
{
    _width = new_width;
    _height = new_height;
    glfwSetWindowSize(_window, _width, _height);
}

void WindowGLFW::set_full_screen(bool fullscreen_state)
{
    if (fullscreen_state)
    {
        int monitors = 0;
        GLFWmonitor *monitor = glfwGetPrimaryMonitor();
        int monitorWidth, monitorHeight;
        glfwGetMonitorPhysicalSize(monitor, &monitorWidth, &monitorHeight);
        glfwSetWindowMonitor(_window, monitor, 0, 0, monitorWidth, monitorHeight, GLFW_DONT_CARE);
    }
    else
    {
        glfwSetWindowMonitor(_window, NULL, 0, 0, _width, _height, GLFW_DONT_CARE);
    }
}

const char *WindowGLFW::name() const
{
    return _name.c_str();
}

void WindowGLFW::set_name(const std::string &new_name)
{
    _name = new_name;
    glfwSetWindowTitle(_window,_name.c_str());
}

int WindowGLFW::create(unsigned int window_width, unsigned int window_height, const std::string &window_name)
{
    if (!glfwInit())
    {
        printf("GLFW initialization failed !\n");
        return 0;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    _width = window_width;
    _height = window_height;
    _window = glfwCreateWindow(window_width, window_height, window_name.c_str(), NULL, NULL);

    if (!_window)
    {
        printf("GLFW window creation failed !`n");
        glfwTerminate();
        return 0;
    }
    set_name(window_name);
    create_viewport();
    return 1;
}

void WindowGLFW::poll_events()
{
    glfwPollEvents();
}

void WindowGLFW::create_viewport()
{
    int viewportWidth, viewportHeight;
    glfwGetFramebufferSize(_window, &viewportWidth, &viewportHeight);
    glfwMakeContextCurrent(_window);
    _viewport.create_viewport(viewportWidth, viewportHeight);
}
