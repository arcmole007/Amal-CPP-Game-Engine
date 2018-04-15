#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Game.h"

class GameObject{
    public:
        GameObject(const char* texture_sheet, SDL_Renderer* ren, int x, int y);
        ~GameObject();

        void Update();
        void Render();
    private:
        int x_position;
        int y_position;

        SDL_Texture* object_texture;
        SDL_Rect source_rectangle;
        SDL_Rect destination_rectangle;
        SDL_Renderer* renderer;
};

#endif //GAMEOBJECT_H