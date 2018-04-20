#ifndef MAP_H
#define MAP_H

//#include "Game.h"
#include <string>

class Map{
    public:
        Map();
        ~Map();

        static void LoadMap(std::string path, int size_x, int size_y);
        //void Drawmap();
    private:
        //SDL_Rect source_map_rectangle;
        //SDL_Rect destination_map_rectangle;
        //SDL_Texture* dirt;
        //SDL_Texture* grass;
        //SDL_Texture* water;

        //int map[20][25];

};      
#endif //MAP_H