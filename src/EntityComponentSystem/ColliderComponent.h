#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include <string>
#include "SDL.h"
#include "EntityComponentSystem.h"
#include "Components.h"
#include "../TextureManager.h"


class ColliderComponent : public Component
{
    public:
        SDL_Rect collider;

        //basiclly tag the player or enemy
        std::string tag;

        TransformComponent* transform;
        ColliderComponent(std::string t)
        {
            tag = t;
        }

        void init()override
        {
            if(!entity->hasComponent<TransformComponent>())
            {
                entity->addComponent<TransformComponent>();
            }

            transform = &entity->getComponent<TransformComponent>();

            Game::colliders.push_back(this);
        }

        void update() override
        {
            collider.x = static_cast<int>(transform->position.x);
            collider.y = static_cast<int>(transform->position.y);
            collider.w = transform->width * transform->scale;
            collider.h = transform->height * transform->scale;
        }


};

#endif //COLLIDERCOMPONENT_H