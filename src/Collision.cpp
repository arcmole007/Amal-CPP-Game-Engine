#include "collision.h"
#include "EntityComponentSystem\ColliderComponent.h"

bool Collision::AABB(const SDL_Rect& rectangle_a, const SDL_Rect& rectangle_b)
{
    if(
        rectangle_a.x + rectangle_a.w >= rectangle_b.x &&
        rectangle_b.x + rectangle_b.w >= rectangle_a.x &&
        rectangle_a.y + rectangle_a.h >= rectangle_b.y &&
        rectangle_b.y + rectangle_b.h >= rectangle_b.y
    )
    {
        return true;
    }

    return false;
}

bool Collision::AABB(const ColliderComponent& collider_a, const ColliderComponent& collider_b)
{   

    if(AABB(collider_a.collider, collider_b.collider))
    {
        //std::cout << collider_a.tag << " hit " << collider_b.tag << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}