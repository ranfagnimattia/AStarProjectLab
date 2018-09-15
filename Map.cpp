//
// Created by matti on 02/05/18.
//

#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include "Map.h"
#include "TextureManager.h"

Map* Map::instance = nullptr;

Map::Map(int x,int y, int nummap): width(x),height(y),textures(TextureManager::LoadTexture("../images/textures.png")) {
    lvlmap= new int[width*height];
    switch(nummap) {
        case 1:
            loadMap("../maps/map1.map");
            break;
        case 2:
            loadMap("../maps/map2.map");
            break;
        case 3:
            loadMap("../maps/map1.map");
            break;
        default:
            loadMap("../maps/map1.map");
            break;
    }

    ground.h = ground.w = grass.h = grass.w = wood.h = wood.w = 16;

    wood.x=32;
    grass.x=0;
    ground.x=64;

    wood.y=0;
    grass.y=0;
    ground.y=0;

    //src.w=32;
    //src.h=32;

    dest.w = dest.h = 32;
    dest.x = dest.y = 0;
}
void Map::drawMap() {
    int type = 0;
    for(int row = 0; row < height ; row++) {
        for(int column=0; column < width ; column++) {

            type = lvlmap[row * width + column];

            dest.x=column * 32;
            dest.y=row * 32;

            switch(type) {
                case 1:
                TextureManager::Draw(textures,grass,dest);
                    break;
                case 2:
                TextureManager::Draw(textures,wood,dest);
                    break;
                case 9:
                TextureManager::Draw(textures,ground,dest);
                    break;
                default:
                    break;
            }
        }
    }
}

int Map::getMap( int x, int y )
{
    if( x < 0 || x >= width || y < 0 || y >= height) return 9;
        return lvlmap[y * width + x];
}

Map::~Map() {
    delete[] lvlmap;
}

Map* Map::Istance(int x,int y, int nmap) {
    if(!instance)
        instance = new Map(x,y, nmap);
    return instance;
}


//UNIT TEST SU GRANDEZZE WIDTH E HEIGHT
void Map::loadMap(std::string path) {
    std::ifstream mapFile(path);
    if(mapFile.is_open()) {
        int i;
        int index = 0;
        while(mapFile >> i ) {
            lvlmap[index] = i;
            index++;
        }
        mapFile.close();
    }

}

