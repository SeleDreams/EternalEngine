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
        private:
            int width, height;
    };
}