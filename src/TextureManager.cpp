//header file
#include "TextureManager.h"

//we return SDL_Texture
//
SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* ren)
{   
    //passing the texture
    SDL_Surface* temporary_surface = IMG_Load(texture);
    if(temporary_surface == nullptr)
    {
        std::cerr << "Image not found!!" << std::endl;
    }

    //create a texture
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, temporary_surface);

    //clear the surface
    SDL_FreeSurface(temporary_surface);

    //we return texture
    return tex;
}