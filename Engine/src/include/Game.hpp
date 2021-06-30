#pragma once
#include <memory>
#include <functional>
#include <SceneManagement/Scene.hpp>
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
        void exit() { _render_surface->close(); }
        std::shared_ptr<RenderSurface> render_surface() { return _render_surface; }
        std::shared_ptr<Scene> main_scene() { return _scene; }
    private:
        std::shared_ptr<Scene> _scene;
        std::shared_ptr<RenderSurface> _render_surface;
        bool _is_running;
        static Game *_singleton;
    };
};
