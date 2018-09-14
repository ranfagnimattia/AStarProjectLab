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
    ~Map();

    void drawMap();
    int getMap( int x, int y );
    static Map* Istance(int x=20,int y=15);

    const int width;
    const int height;

protected:
    Map(int x, int y);

private:
    static Map* instance;
    bool loadMap(std::string path);
    void load();

    SDL_Rect ground,grass,wood, src, dest;
    SDL_Texture* textures;
    int* lvlmap;
};


#endif //PROVASDL_MAP_H
