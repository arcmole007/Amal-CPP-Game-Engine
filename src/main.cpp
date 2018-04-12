#include <iostream>

#include <SDL.h>

#include "Game.h"


Game *game = nullptr;
//The main program for the engine
int main(int argv, char** args)
{

    game = new Game();

    game->initilize("Amal Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600, false);

    while(game->run()){
        game->handleEvents();
        game->update();
        game->render();

    }
    game->clean();
    return 0;
}