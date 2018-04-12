#ifndef GAME_H
#define GAME_H

//Common libarary
#include <iostream>

//all the include that used SDL library
#include <SDL.h>


//Class game is where the loop for the game 
//happen duh
class Game{

    public:
        //Constructor
        //Inside here we initialize everythings
        //also where we put window
        Game();

        //Deconstructor
        //This is where we closed or suspend our game
        ~Game();

        void initilize(const char* title, int x_position, int y_position, int width, int height, bool fullscreen);
        //This method handle all the events or
        //the keyinput that we gonna use
        void handleEvents();

        //Method to update the process
        void update();

        //Method to render or draw in the screen
        void render();

        //Using for memory management
        void clean();

        //check either the game is running
        bool run(){return game_is_runnning;}

    //attributes for the class
    private:

        int count = 0;
        //check either game is runnnig
        bool game_is_runnning;

        //This is where define the window
        //That why we don't need the class window 
        //as it already provide by the SDL library
        SDL_Window *window;

        SDL_Renderer *renderer;

};



#endif //GAME_H