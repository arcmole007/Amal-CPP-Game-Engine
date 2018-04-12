#include "Window.h"

//Constructor of the window 
Window::Window(const std::string &game_title, int width, int height):
        game_title(game_title),
        width(width),
        height(height)
{
    if(!Initilize())
    {
        game_is_closed = true;
    }
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}


bool Window::Initilize()
{   
    //it not successful
    if(SDL_Init(SDL_INIT_VIDEO) !=0)
    {
        std::cerr << "Failed to inilize SDL. \n";
        return 0;
    }

    window = SDL_CreateWindow(game_title.c_str(), SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, width, height, 0);

    if(window == nullptr)
    {
        std::cerr << "Failed to create window. \n";
        return 0;
    }

    return true;
}