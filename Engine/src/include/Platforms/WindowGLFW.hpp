#pragma once
#include <Rendering/Window/Window.hpp>
#include <Rendering/Viewport/Viewport.hpp>
#include <GLFW/glfw3.h>

namespace EternalEngine
{
    class WindowGLFW : public Window
    {
    public:
        WindowGLFW();
        ~WindowGLFW();

        virtual Viewport &viewport() { return _viewport; }
        virtual int create_window(unsigned int window_width, unsigned int window_height, const std::string &window_name);
        virtual const char *name() const;
        virtual void close() { glfwSetWindowShouldClose(_window, 1); }
        virtual void set_name(const std::string &new_name);
        virtual void poll_events();

        virtual void set_full_screen(bool fullscreen_state);

        virtual bool full_screen() const { return glfwGetWindowMonitor(_window) != nullptr; }
        virtual bool should_close() const { return glfwWindowShouldClose(_window); }

        virtual void swap_buffer() { glfwSwapBuffers(_window); }

        virtual unsigned int width() const { return _width; }
        virtual unsigned int height() const { return _height; }
        virtual void resize_window(unsigned int new_width, unsigned int new_height);

    private:
        void create_viewport();
        std::string _name;
        GLFWwindow *_window;
        Viewport _viewport;
        unsigned int _width, _height;
        bool _full_screen;
    };
}