#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Game.h"

class GameObject{
    public:
        //constructor defination
        GameObject(const char* texture_sheet, int x, int y);
        //deconstructor defination
        ~GameObject();

        //update the process of the game object
        void Update();

        //draw object to the screen
        void Render();

    private:
        //x and y position
        int x_position;
        int y_position;

        //defination of texture
        SDL_Texture* object_texture;

        //defination of rectangle
        SDL_Rect source_rectangle;
        SDL_Rect destination_rectangle;

        //definaton of renderer
       // SDL_Renderer* renderer;
};

#endif //GAMEOBJECT_H