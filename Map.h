//
// Created by matti on 02/05/18.
//

#ifndef PROVASDL_MAP_H
#define PROVASDL_MAP_H
#include "Game.h"

class Map {
public:
    Map();
    ~Map();

    void LoadMap(int [20][25]);
    void DrawMap();
private:
    SDL_Rect src, dest;
    SDL_Texture* textures;


    int map[20][25];

};


#endif //PROVASDL_MAP_H