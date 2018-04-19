#include "Map.h"
#include "TextureManager.h"

//This is the array that will be modified to get the tile map
int lvl1[20][25] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    
};

Map::Map()
{
    //loading all the tiles
    dirt = TextureManager::LoadTexture("../assets/images/dirt.png"); //0
    grass = TextureManager::LoadTexture("../assets/images/grass.png");//1
    water = TextureManager::LoadTexture("../assets/images/water.png");//2

    LoadMap(lvl1);

    source_map_rectangle.x = 0;
    source_map_rectangle.y = 0;
    source_map_rectangle.w = 64;
    source_map_rectangle.h = 64;

    destination_map_rectangle.w = 64;
    destination_map_rectangle.h = 64;
}
    

void Map::LoadMap(int arr[20][25])
{
    for(int row = 0; row < 20; row++)
    {
        for(int column = 0; column < 25; column++)
        {
            map[row][column] = arr[row][column];
        }
    }
}

void Map::Drawmap()
{   
    int type = 0;
    for(int row = 0; row < 20; row++)
    {
        for(int column = 0; column < 25; column++)
        {
            type = map[row][column];

            destination_map_rectangle.x = column * 64;
            destination_map_rectangle.y = row * 64;

            //std::cout << type << std::endl;
            
            switch(type)
            {   
                case 0:TextureManager::Draw(water, source_map_rectangle, destination_map_rectangle);break;
                case 1:TextureManager::Draw(grass, source_map_rectangle, destination_map_rectangle); break;
                case 2:TextureManager::Draw(dirt, source_map_rectangle, destination_map_rectangle); break;
                default:break;
            }
        }
    }

    //std::cout << "Map is drawn" << std::endl;
}

