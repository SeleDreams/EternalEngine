#pragma once
#include <memory>
#include <functional>
#include <Rendering/Renderer.hpp>
#include <Rendering/Window/Window.hpp>

namespace EternalEngine
{
    class Game
    {
    public:
        static Game *instance() { return _singleton; }
        Game();
        ~Game();
        int init(unsigned int width = 800, unsigned int height = 600, const char *name = "Eternal Engine");
        void run();
        void exit() { _window->close(); }
        std::shared_ptr<Window> get_window() { return _window; }

    private:
        std::shared_ptr<Window> _window;
        bool _is_running;
        static Game *_singleton;
    };
};
