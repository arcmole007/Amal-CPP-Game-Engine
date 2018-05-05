#include "GameObject.h"
#include "TextureManager.h"

//constructot of gameObject
//@param texture sheet or the spritesheet
//@param renderer
//@param initial position of x and y
GameObject::GameObject(const char* texture_sheet, int x, int y)
{
    
    object_texture = TextureManager::LoadTexture(texture_sheet);
    x_position = x;
    y_position = y;
}

//Deconstructor
GameObject::~GameObject()
{}

//This is we update the process of our game object
void GameObject::Update()
{   
    //This make the object move diagnaolly and x and y increase respectively
    x_position++;
    y_position++;

    //create the source rectangle size and position
    source_rectangle.h = 32;
    source_rectangle.w = 32;
    source_rectangle.x = 0;
    source_rectangle.x = 0;

    //creating the destination rectangle size and position
    destination_rectangle.x = x_position;
    destination_rectangle.y = y_position;
    destination_rectangle.w = source_rectangle.w;
    destination_rectangle.h = source_rectangle.h;
}

//Method for the game object to draw itself to 
//the screen
void GameObject::Render()
{   
    //we use copy because we just copy the renderer from
    //?????
    SDL_RenderCopy(Game::renderer, object_texture, &source_rectangle, &destination_rectangle);
}