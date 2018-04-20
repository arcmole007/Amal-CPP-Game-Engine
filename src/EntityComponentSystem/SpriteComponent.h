#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"

class SpriteComponent : public Component
{   
    private:
        TransformComponent *transform;
        SDL_Texture *texture;
        SDL_Rect source_rectangle;
        SDL_Rect destination_rectangle;

    public:
        //Constructor
        SpriteComponent() = default;

        //Overloading constructor
        SpriteComponent(const char* path)
        {
            setTexture(path);
        }

        //Deconstructor
        ~SpriteComponent()
        {
            SDL_DestroyTexture(texture);

        }


        void setTexture(const char* path)
        {
            texture = TextureManager::LoadTexture(path);
        }
        
        void init() override
        {   
            transform = &entity->getComponent<TransformComponent>();

            source_rectangle.x = 0;
            source_rectangle.y = 0;
            source_rectangle.w = transform->width;
            source_rectangle.h = transform->height;

            destination_rectangle.w = transform->width * transform->scale;
            destination_rectangle.h = transform->height* transform->scale;
        }

        void update() override
        {
            destination_rectangle.x = static_cast<int>(transform->position.x);
            destination_rectangle.y = static_cast<int>(transform->position.y);
            destination_rectangle.w = transform->height * transform->scale;
            destination_rectangle.h = transform->height * transform->scale;
        }

        void draw() override
        {
            TextureManager::Draw(texture, source_rectangle, destination_rectangle);
        }
        
};

#endif //SPRITECOMPONENT_H