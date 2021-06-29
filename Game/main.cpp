
#include <stdio.h>
#include <Game.hpp>
#include <Rendering/Window/Window.hpp>
int main(int argc, char **argv)
{
    EternalEngine::Game game;
    if (!game.init(800,600,"My Game"))
    {
        printf("An error occurred while initializing the game !");
    }
    EternalEngine::Window *main_window = dynamic_cast<EternalEngine::Window*>(game.render_surface().get());
    if (main_window)
    {
        main_window->resize_window(1280,720);
    }
    game.run();
}