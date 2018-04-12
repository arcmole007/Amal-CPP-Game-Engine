#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}


void Game::initilize(const char *title, int x_position, int y_position, int width, int height, bool fullscreen)
{   
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystem Initilized!...." << std::endl;

        window = SDL_CreateWindow(title, x_position, y_position, width, height, flags);
        if(window)
        {
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {   
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }

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