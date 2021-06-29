#include <Game.hpp>
#include <assert.h>
#include <Rendering/Viewport/Viewport.hpp>
#include <chrono>

#ifdef USE_GLFW
#include <Platforms/WindowGLFW.hpp>
#define WINDOW_CLASS WindowGLFW
#endif

using namespace EternalEngine;

Game *Game::_singleton = nullptr;

Game::Game()
{
    assert(!Game::instance());
    Game::_singleton = this;
    _is_running = false;
    _render_surface = std::shared_ptr<Window>(nullptr);
}

Game::~Game()
{
    Game::_singleton = nullptr;
}

int Game::init(unsigned int width, unsigned int height, const char *name)
{
    _render_surface = std::shared_ptr<RenderSurface>(dynamic_cast<RenderSurface *>(new WINDOW_CLASS()));
    if (!_render_surface)
    {
        return 0;
    }
    return _render_surface->create(width, height, name);
}

void Game::run()
{
    _is_running = true;
    std::chrono::high_resolution_clock::time_point current_time;
    std::chrono::high_resolution_clock::time_point previous_time = std::chrono::high_resolution_clock::now();
    float delta;
    while (_is_running)
    {
        current_time = std::chrono::high_resolution_clock::now();
        delta = std::chrono::duration<float,std::milli>(current_time - previous_time).count() / 1000;
        previous_time = current_time;
        _render_surface->viewport().clear_viewport();
        _scene->update(delta);
        _render_surface->poll_events();
        _render_surface->swap_buffer();
        _is_running = !_render_surface->should_close();
    }
}