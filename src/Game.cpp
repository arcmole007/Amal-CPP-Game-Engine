#include "Game.h"

//Constructor for our game class
Game::Game()
{

}

//deconstructor for our game class
Game::~Game()
{

}

//Method to initlize everythings
//basically, replace constructor functions
void Game::initilize(const char *title, int x_position, int y_position, int width, int height, bool fullscreen)
{   
    //flags is the way to check if the fullscren is true or false
    //if = 0 mean it false
    int flags = 0;

    //if the fullscreen is true we called the SLD lib for fullscreen
    if(fullscreen)
    {
        //flags will become SDL lib fullscreen
        flags = SDL_WINDOW_FULLSCREEN;
    }

    //here we intilize all the SDL 
    //if is == 0 mean that the SDL is called correctly
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystem Initilized!...." << std::endl;

        //here we called the SDL window point it in the window
        window = SDL_CreateWindow(title, x_position, y_position, width, height, flags);
        if(window)
        {
            std::cout << "Window created!" << std::endl;
        }

        //here we create the renderer
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {   
            //this we set the background color of the screen as white color
            //255,255,255,255 = white
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        //if the SDL INIT EV == 0
        //game is running correctly
        game_is_runnning = true;
    }
    else
    {
        game_is_runnning = false;
    }
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT: game_is_runnning = false; break;
        default: break;
    }
}

void Game::update()
{
    count++;
    std::cout << count << std::endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //this is where we add stuff to render
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}