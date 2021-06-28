#include <Game.hpp>
#include <assert.h>

using namespace EternalEngine;

Game *Game::_singleton = nullptr;

Game::Game()
{
    assert(!Game::instance());
    Game::_singleton = this;
}

Game::~Game()
{
    Game::_singleton = nullptr;
}

bool Game::run(unsigned int width, unsigned int height,std::function<bool()> buffer_swap_callback)
{
    _viewport.create_viewport(width, height);
    _is_running = true;
    while (_is_running && buffer_swap_callback())
    {
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}