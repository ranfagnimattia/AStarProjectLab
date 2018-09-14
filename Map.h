//
// Created by matti on 02/05/18.
//

#ifndef PROVASDL_MAP_H
#define PROVASDL_MAP_H

#include <string>
#include <SDL_rect.h>
#include <SDL_render.h>

class Map {
public:
    Map();
    ~Map();

    void drawMap();
    static int getMap( int x, int y );

    static const int width;
    static const int height;

private:
    bool loadMap(std::string path);

    SDL_Rect ground,grass,wood, src, dest;
    SDL_Texture* textures;
    static int lvlmap[300];
};


#endif //PROVASDL_MAP_H
