#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texture_sheet, SDL_Renderer* ren, int x, int y)
{
    renderer = ren;
    object_texture = TextureManager::LoadTexture(texture_sheet, ren);
    x_position = x;
    y_position = y;
}

GameObject::~GameObject()
{}

//This is we update the process of our game object
void GameObject::Update()
{
    x_position++;
    y_position++;

    source_rectangle.h = 64;
    source_rectangle.w = 64;
    source_rectangle.x = 0;
    source_rectangle.x = 0;

    destination_rectangle.x = x_position;
    destination_rectangle.y = y_position;
    destination_rectangle.w = source_rectangle.w;
    destination_rectangle.h = source_rectangle.h;
}

//Method for the game object to draw itself to 
//the screen
void GameObject::Render()
{
    SDL_RenderCopy(renderer, object_texture, &source_rectangle, &destination_rectangle);
}