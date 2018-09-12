//
// Created by matti on 02/05/18.
//

#include "Map.h"
#include "TextureManager.h"

const int Map::width = 20;
const int Map:: height = 15;
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
    src.x=0;
    src.y=0;

    src.w=32;
    src.h=32;
    dest.w=32;
    dest.h=32;
}
void Map::drawMap() {
    int type = 0;
    for(int row = 0; row < width ; row++) {
        for(int column=0; column < height ; column++) {
            type = lvlmap[row * height + column];
            dest.x=column * 32;
            dest.y=row*32;
            switch(type) {
                case 0:
                src.x=32;
                TextureManager::Draw(textures,src,dest);
                    break;
                case 1:
                src.x=0;
                TextureManager::Draw(textures,src,dest);
                    break;
                case 9:
                src.x=64;
                TextureManager::Draw(textures,src,dest);
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
        return lvlmap[y * height + x];
}

Map::~Map() {
}