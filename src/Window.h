#ifndef WINDOW_H
#define WINDOW_H

//Reguler include library we need
#include <iostream>
#include <string>

//SDL include we need
#include "SDL.h"

//Class window is reponsible to 
//Create a window for the game
class Window{

    //all the public methods that used for window class
    public:
        //Constructo for window
        //We need paramater the game_title, width & height of the window
        Window(const std::string &game_title, int width, int height);

        //Deconstructor for the window
        //Where we destroy and quit the window
        ~Window();

        //inline is used if the method only return one varible
        //Here we return if the game is close
        inline bool is_Closed() const {return game_is_closed;}

    //private method
    private:
        //Method to initilize all the window 
        bool Initilize();

    //private attributes
    private:

        //game title appear at the window
        std::string game_title;

        //width & height of the window
        int width = 800;
        int height = 600;

        //check if the game is closed
        bool game_is_closed = false;

        //Our SDL window
        SDL_Window *window = nullptr;
};

#endif //WINDOW_H