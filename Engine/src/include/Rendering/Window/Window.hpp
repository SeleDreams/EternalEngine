#pragma once
#include <string>
#include <Rendering/Viewport/Viewport.hpp>
#include "RenderSurface.hpp"

namespace EternalEngine
{
    class Window : public RenderSurface
    {
    public:
        Window() = default;
        virtual ~Window() = default;

        virtual void set_full_screen(bool fullscreen_state) = 0;
        virtual bool full_screen() const = 0;
        virtual void resize_window(unsigned int new_width, unsigned int new_height) = 0;
    };
}