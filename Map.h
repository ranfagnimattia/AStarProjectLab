//
// Created by matti on 02/05/18.
//

#ifndef PROVASDL_MAP_H
#define PROVASDL_MAP_H

#include "TextureManager.h"

class Map {
public:
    Map();
    ~Map();

    void drawMap();
    static int getMap( int x, int y );

    static const int width;
    static const int height;

private:
    SDL_Rect ground,grass,wood, src, dest;
    SDL_Texture* textures;
    static int lvlmap[300];
};


#endif //PROVASDL_MAP_H
