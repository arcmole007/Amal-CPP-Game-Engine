#ifndef GAME_H
#define GAME_H

//Common libarary
#include <iostream>

//all the include that used SDL library
#include <SDL.h>

#include "Window.h"

//Class game is where the loop for the game 
//happen duh
class Game{

    public:
        //Constructor
        //Inside here we initialize everythings
        //also where we put window
        Game(Window* window);

        

        //Deconstructor
        //This is where we closed or suspend our game
        virtual ~Game();

        void handleEvents();
        void update();
        void render();
        void clean();

        bool run();


    private:

        bool game_is_runnning;
        Window* window;


      




};



#endif //GAME_H