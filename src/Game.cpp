//Include our header for game class
#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

//we can use gameObject class to define all
//the object like playerr and enemy
GameObject* player;
GameObject* enemy;
Map* map;


//we use only this renderer isntead copy alots of pointer
SDL_Renderer* Game::renderer = nullptr;

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

       // SDL_Surface* temporary_surface = IMG_Load("../assets/images/idle-larry.png");

       // player_texture =SDL_CreateTextureFromSurface(renderer, temporary_surface);

        //SDL_FreeSurface(temporary_surface);

       // player_texture = TextureManager::LoadTexture("../assets/images/idle-larry.png", renderer);

       //create the objects by passing the filename location,
       //renderer, and position x and y
        player = new GameObject("../assets/images/larry1.png", 0, 0);
        enemy = new GameObject("../assets/images/zombie.png",  50,50);
        
        map = new Map();

    }
    else
    {
        game_is_runnning = false;
    }
}

//Method to hadnle events like keyinput
//and quit the game
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

//Method for all the update the process
void Game::update()
{   
    //calculate the time during update
    count++;
    //destination_rectangle.h = 64;
   // destination_rectangle.w = 256;
    //destination_rectangle.x = count;

    //std::cout << count << std::endl;

    //all the objects process update
    player->Update();
    enemy->Update();
    
    
}

//Method to draw to the screen
void Game::render()
{   
    //clear all the renderer
    SDL_RenderClear(renderer);
    map->Drawmap();
    
    //everything must sandwich between SDL_rendereClear and present
    //SDL_RenderCopy(renderer, player_texture, NULL, &destination_rectangle);

    //all the objects draw to the screen
    player->Render();
    enemy->Render();
    



    //this is where we add stuff to render
    SDL_RenderPresent(renderer);
}

//Method to clear the memory
//using use in the deconstructor
void Game::clean()
{   
    //Destroy the window
    SDL_DestroyWindow(window);
    //destroy the renderer
    SDL_DestroyRenderer(renderer);
    //quit the game
    SDL_Quit();

    std::cout << "Game cleaned!" << std::endl;
}