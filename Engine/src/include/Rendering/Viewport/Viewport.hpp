#pragma once
#include <memory>

namespace EternalEngine
{
    class Viewport
    {
    public:
        Viewport();
        ~Viewport();
        int create_viewport(int width, int height);
        void resize_viewport(int new_width, int new_height);
        unsigned int width() const { return _width; }
        unsigned int height() const { return _height; }
        void clear_viewport();

    private:
        unsigned int _width, _height;
    };
}