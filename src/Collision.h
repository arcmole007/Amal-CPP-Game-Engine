#ifndef COLLISION_H
#define COLLISION_H

#include "SDL.h"

class ColliderComponent;

class Collision
{
    public:
        static bool AABB(const SDL_Rect& rectangle_a, const SDL_Rect& rectangle_b);
        static bool AABB(const ColliderComponent& collider_a, const ColliderComponent& collider_b);
};
#endif //COLLISION_H