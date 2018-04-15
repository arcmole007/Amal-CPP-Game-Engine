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

    //we try to caps or limiting the frame per second as 60
    const int FPS = 60;

    //Here we get the frame delay
    // 1000 / 60 = 17 frame delay
    const int FRAME_DELAY = 1000 / FPS;

    //We need to find the no frame when start
    Uint32 frame_start;

    //and we need to find the time for the frame
    int frame_time;

    //create a new game object
    game = new Game();

    //we initialize the title,position of the window and the size and the fullscreen 
    game->initilize("Amal Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600, false);

    //game loop
    //check if the game is running
    //do all the process(update,render)
    while(game->run()){

        //we now need to find out the time when the frame start
        //ticking
        frame_start = SDL_GetTicks();

        //this is we handle all the events that happen in the game
        game->handleEvents();
        //this is we update the game process
        game->update();
        //this is we all the objects inside screen
        game->render();

        //we get the current frame time by 
        //minus the time now and the time when start
        //hence, get the time after all update, render happened
        frame_time = SDL_GetTicks() - frame_start;

        //when the our frame time is more than fps that we caps
        //the delay happen to make it slow 
       if(FRAME_DELAY > frame_time)
        {
            SDL_Delay(FRAME_DELAY - frame_time);
        }

    }
    //when the game is close it will automaticlly clean all the memory
    game->clean();
    return 0;
}