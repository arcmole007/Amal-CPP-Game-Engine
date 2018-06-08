#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"
#include "Animation.h"
#include <map>

class SpriteComponent : public Component
{   
    private:
        TransformComponent *transform;
        SDL_Texture *texture;
        SDL_Rect source_rectangle;
        SDL_Rect destination_rectangle;

        // check if the sprite is animated
        bool animated = false;
        //number of frames
        int frames = 0;
        //delay of frames in miliseconds
        int speed = 100;

    public:

        int animation_index = 0;

        std::map<const char*, Animation> animations;

        SDL_RendererFlip sprite_flip = SDL_FLIP_NONE;

        //Constructor
        SpriteComponent() = default;

        //Overloading constructor
        SpriteComponent(const char* path)
        {
            setTexture(path);
        }

        SpriteComponent(const char* path, bool is_animated)
        {
            //if the method is called, automatically we make the animated = true
            animated = is_animated;

            Animation idle = Animation(0, 3, 100);
            Animation walk = Animation(1, 8, 100);

            animations.emplace("Idle", idle);
            animations.emplace("walk", walk);

            Play("Idle");
           
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
            //check if animated is true
            if(animated)
            {
                source_rectangle.x = source_rectangle.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
            }

            source_rectangle.y = animation_index * transform->height;

            destination_rectangle.x = static_cast<int>(transform->position.x);
            destination_rectangle.y = static_cast<int>(transform->position.y);
            destination_rectangle.w = transform->height * transform->scale;
            destination_rectangle.h = transform->height * transform->scale;
        }

        void draw() override
        {
            TextureManager::Draw(texture, source_rectangle, destination_rectangle, sprite_flip);
        }

        void Play(const char* animation_name)
        {
            frames = animations[animation_name].frames;
            animation_index = animations[animation_name].index;
            speed = animations[animation_name].speed;
        }
        
};

#endif //SPRITECOMPONENT_H