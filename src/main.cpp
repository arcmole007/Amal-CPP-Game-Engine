#include <iostream>

#include <SDL.h>

//all the objects that we used
#include "Game.h"

//define the game object
Game *game = nullptr;
//The main program for the engine
//"int argv,char** args" -> this particular signature is
//required because SDL alters default program entry point resolving
//in normal circumstances,only one "int main()","void main()"
int main(int argv, char** args)
{
    //create a new game object
    game = new Game();

    //we initialize the title,position of the window and the size and the fullscreen 
    game->initilize("Amal Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600, false);

    //game loop
    //check if the game is running
    //do all the process(update,render)
    while(game->run()){
        //this is we handle all the events that happen in the game
        game->handleEvents();
        //this is we update the game process
        game->update();
        //this is we all the objects inside screen
        game->render();

    }
    //when the game is close it will automaticlly clean all the memory
    game->clean();
    return 0;
}