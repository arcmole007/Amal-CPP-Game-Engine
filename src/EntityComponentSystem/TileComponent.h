#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#include "EntityComponentSystem.h"
#include "TransformComponent.h"
#include "SDL.h"

class TileComponent : public Component
{
    public:

        SDL_Texture* texture;
        SDL_Rect source_rectangle, destination_rectangle;
        TileComponent() = default;

        ~TileComponent()
        {
            SDL_DestroyTexture(texture);
        }

        TileComponent(int src_x, int src_y, int x_pos, int y_pos, const char* path)
        {
            texture = TextureManager::LoadTexture(path);

            source_rectangle.x = src_x;
            source_rectangle.y = src_y;
            source_rectangle.w = source_rectangle.h = 32;

            destination_rectangle.x = x_pos;
            destination_rectangle.y = y_pos;
            destination_rectangle.w = destination_rectangle.h = 64;
        }

        void draw()override
        {
            TextureManager::Draw(texture, source_rectangle, destination_rectangle, SDL_FLIP_NONE);
        }
        // TransformComponent *transform;
        // SpriteComponent *sprite;

        // SDL_Rect tile_rectangle;
        // int tile_ID;
        // const char* path;

        // TileComponent() = default;

        // TileComponent(int x, int y, int w, int h, int id)
        // {
        //     tile_rectangle.x = x;
        //     tile_rectangle.y = y;
        //     tile_rectangle.w = w;
        //     tile_rectangle.h = h;
        //     tile_ID = id;

        //     switch(tile_ID)
        //     {
        //         case 0 : path = "../assets/images/Tile-x-dark-green.png"; break;
        //         case 1 : path = "../assets/images/Tile-x-light-green.png"; break;
        //         case 2 : path = "../assets/images/Sea-+.png"; break;
        //         default: break;
        //     }
        // }

        // void init() override
        // {
        //     entity->addComponent<TransformComponent>((float)tile_rectangle.x, (float)tile_rectangle.y, tile_rectangle.w, tile_rectangle.h, 1);
        //     transform = &entity->getComponent<TransformComponent>();

        //     entity->addComponent<SpriteComponent>(path);
        //     sprite = &entity->getComponent<SpriteComponent>();
        // }


};
#endif //TILECOMPONENT_H