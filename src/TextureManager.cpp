//header file
#include "TextureManager.h"

//we return SDL_Texture
//
SDL_Texture* TextureManager::LoadTexture(const char* texture)
{   
    //passing the texture
    SDL_Surface* temporary_surface = IMG_Load(texture);
    //make a error checking if the image loaction is not exist
    if(temporary_surface == nullptr)
    {
        std::cerr << "Image not found!!" << std::endl;
    }

    //create a texture
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, temporary_surface);

    //clear the surface
    SDL_FreeSurface(temporary_surface);

    //we return texture
    return tex;
}

void TextureManager::Draw(SDL_Texture* tex,SDL_Rect source, SDL_Rect destination)
{
    SDL_RenderCopy(Game::renderer, tex, &source, &destination);
}