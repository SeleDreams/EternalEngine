#pragma once
#include <string>
#include <Rendering/Viewport/Viewport.hpp>
namespace EternalEngine
{
    class Window
    {
    public:
        Window() = default;
        virtual ~Window() = default;

        virtual Viewport &viewport() = 0;
        virtual int create_window(unsigned int window_width, unsigned int window_height, const std::string &window_name) = 0;
        virtual const char *name() const = 0;
        virtual void set_name(const std::string &new_name) = 0;
        virtual void close() = 0;
        virtual void poll_events() = 0;

        virtual void set_full_screen(bool fullscreen_state) = 0;
        virtual bool full_screen() const = 0;
        virtual bool should_close() const = 0;
        virtual void swap_buffer() = 0;

        virtual unsigned int width() const = 0;

        virtual unsigned int height() const = 0;

        virtual void resize_window(unsigned int new_width, unsigned int new_height) = 0;
    };
}