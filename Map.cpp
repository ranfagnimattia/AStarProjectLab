//
// Created by matti on 02/05/18.
//

#include <string>
#include <fstream>
#include "Map.h"
#include "TextureManager.h"

const int Map::width= 20;
const int Map::height = 15;
int Map::lvlmap[300] = {
// 0001020304050607080910111213141516171819
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   // 00
        1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,   // 01
        1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 02
        1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 03
        1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 04
        1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   // 05
        1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   // 06
        1,9,9,9,9,9,9,9,9,1,1,1,9,9,9,9,9,9,9,1,   // 07
        1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   // 08
        1,9,1,9,9,9,9,9,9,9,1,1,9,9,9,9,9,9,9,1,   // 09
        1,9,1,1,1,1,9,1,1,9,1,1,1,1,1,1,1,1,1,1,   // 10
        1,9,9,9,9,9,1,9,1,9,1,9,9,9,9,9,1,1,1,1,   // 11
        1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 12
        1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 13
        1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 14
};

Map::Map(): textures(TextureManager::LoadTexture("../images/textures.png")) {
    //lvlmap= new int[width*height];


    ground.h = ground.w = grass.h = grass.w = wood.h = wood.w = 16;

    wood.x=0;
    grass.x=32;
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
                case 0:
                TextureManager::Draw(textures,grass,dest);
                    break;
                case 1:
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
    //delete[] lvlmap;
}

bool Map::loadMap(std::string path) {
    char tile;
    std::fstream mapFile;
    mapFile.open(path);

    for(int y=0; y < height; y++) {
        for(int x=0; x < width; x++) {
            mapFile.get(tile);
            lvlmap[y * width + x] = atoi(&tile);
        }
    }
    return false;
}
