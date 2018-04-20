#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#include "EntityComponentSystem.h"
#include "TransformComponent.h"
#include "SDL.h"

class TileComponent : public Component
{
    public:
        TransformComponent *transform;
        SpriteComponent *sprite;

        SDL_Rect tile_rectangle;
        int tile_ID;
        const char* path;

        TileComponent() = default;

        TileComponent(int x, int y, int w, int h, int id)
        {
            tile_rectangle.x = x;
            tile_rectangle.y = y;
            tile_rectangle.w = w;
            tile_rectangle.h = h;
            tile_ID = id;

            switch(tile_ID)
            {
                case 0 : path = "../assets/images/dirt32.png"; break;
                case 1 : path = "../assets/images/grass32.png"; break;
                case 2 : path = "../assets/images/water32.png"; break;
                default: break;
            }
        }

        void init() override
        {
            entity->addComponent<TransformComponent>((float)tile_rectangle.x, (float)tile_rectangle.y, tile_rectangle.w, tile_rectangle.h, 1);
            transform = &entity->getComponent<TransformComponent>();

            entity->addComponent<SpriteComponent>(path);
            sprite = &entity->getComponent<SpriteComponent>();
        }


};
#endif //TILECOMPONENT_H