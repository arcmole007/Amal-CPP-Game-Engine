#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

//We don't need to call the SDL
#include "Game.h"

//class for texture manager
class TextureManager{

    public:
        //static because ????
        //@param filename where the file located
        //@param renderer to render
        static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);


    private:

};

#endif //TEXTUREMANAGER_H