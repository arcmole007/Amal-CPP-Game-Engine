#ifndef MAP_H
#define MAP_H

#include "Game.h"

class Map{
    public:
        Map();
        ~Map();

        void LoadMap(int arr[20][25]);
        void Drawmap();
    private:
        SDL_Rect source_map_rectangle;
        SDL_Rect destination_map_rectangle;
        SDL_Texture* dirt;
        SDL_Texture* grass;
        SDL_Texture* water;

        int map[20][25];

};      
#endif //MAP_H