#pragma once
#include <Rendering/Viewport/Viewport.hpp>
namespace EternalEngine
{
    class RenderSurface
    {
        public:
        RenderSurface() = default;
        virtual ~RenderSurface() = default;
        virtual Viewport &viewport() = 0;
        virtual int create(unsigned int surface_width, unsigned int surface_height, const std::string &surface_name) = 0;
        virtual const char *name() const = 0;
        virtual void set_name(const std::string &new_name) = 0;
        virtual void close() = 0;
        virtual void poll_events() = 0;
        virtual bool should_close() const = 0;
        virtual void swap_buffer() = 0;
        virtual unsigned int width() const = 0;
        virtual unsigned int height() const = 0;
    };
}