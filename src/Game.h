#ifndef GAME_H
#define GAME_H

//Common libarary
#include <iostream>
#include <vector>

//all the include that used SDL library
#include <SDL.h>
#include <SDL_image.h>

class ColliderComponent;
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

        static void AddTile(int source_x, int source_y, int x_position, int y_position);

        static SDL_Renderer* renderer;

        static SDL_Event event;

        static std::vector<ColliderComponent*> colliders;

    //attributes for the class
    private:

        //This is to check the time that upadate
        int count = 0;

        //check either game is runnnig
        bool game_is_runnning;

        //This is where define the window
        //That why we don't need the class window 
        //as it already provide by the SDL library
        SDL_Window *window;

        //This is where we define our renderer
        //SDL_Renderer *renderer;

        //Here we declare the texture for the player
        SDL_Texture* player_texture;

        //Here we try to create a rectangle
        //and this is the source ???
        //@note not really sure what the hell is this
        SDL_Rect source_rectangle;

        //Here we create the rectangle destination
        //@note a output of the rectangle
        SDL_Rect destination_rectangle;

};



#endif //GAME_H