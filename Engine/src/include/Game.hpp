#pragma once
#include <memory>
#include <functional>
#include <Rendering/Renderer.hpp>

namespace EternalEngine
{
    class Game
    {
        public:
            static Game *instance() { return _singleton; }
            Game();
            ~Game();
            bool run(unsigned int width, unsigned int height,std::function<bool()> buffer_swap_callback);
        private:
            Viewport _viewport;
            bool _is_running;
            std::function<bool()> _buffer_swap_callback;
            static Game *_singleton;
    };
};
