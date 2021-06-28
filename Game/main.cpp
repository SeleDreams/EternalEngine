
#include <stdio.h>
#include <Game.hpp>

int main(int argc, char **argv)
{
    EternalEngine::Game game;
    if (!game.init(800,600,"My Game"))
    {
        printf("An error occurred while initializing the game !");
    }
    game.get_window()->resize_window(1280,720);
    game.run();
}