//
// Created by matti on 02/05/18.
//

#ifndef PROVASDL_MAP_H
#define PROVASDL_MAP_H

#include <string>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

class Map {
public:
    ~Map();

    void drawMap();
    int getMap( int x, int y);
    static Map* Istance(int nmap=1);

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }


protected:
    explicit Map(int nummap);

private:
    static Map* instance;
    bool loadMap(std::string path, int& height, int& width);

    int width;
    int height;
    SDL_Rect ground,grass,wood, src, dest;
    SDL_Texture* textures;
    int* lvlmap;
};


#endif //PROVASDL_MAP_H
