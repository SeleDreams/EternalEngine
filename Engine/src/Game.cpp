#include <Game.hpp>
#include <assert.h>
#include <Rendering/Viewport/Viewport.hpp>

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
    _window = std::shared_ptr<Window>(nullptr);
}

Game::~Game()
{
    Game::_singleton = nullptr;
}

int Game::init(unsigned int width, unsigned int height, const char *name)
{
    _window = std::shared_ptr<Window>(dynamic_cast<Window *>(new WINDOW_CLASS()));
    if (!_window)
    {
        return 0;
    }
    return _window->create_window(width, height, name);
}

void Game::run()
{
    _is_running = true;
    while (_is_running)
    {
        _window->viewport().clear_viewport();
        _window->poll_events();
        _window->swap_buffer();
        _is_running = !_window->should_close();
    }
}