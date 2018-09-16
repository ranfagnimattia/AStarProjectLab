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

Map::Map(int nummap): textures(TextureManager::LoadTexture("../images/textures.png")) {
    switch(nummap) {
        case 1:
            loadMap("/home/matti/Documenti/PROGRAMMAZIONEUNI/AStarLabSDL/maps/map1.map",height,width);
            //loadMap("../maps/map1.map",height,width);
            break;
        case 2:
            loadMap("/home/matti/Documenti/PROGRAMMAZIONEUNI/AStarLabSDL/maps/map2.map",height,width);
            //loadMap("../maps/map2.map",height,width);
            break;
        case 3:
            loadMap("/home/matti/Documenti/PROGRAMMAZIONEUNI/AStarLabSDL/maps/map3.map",height,width);
            //loadMap("../maps/map1.map",height,width);
            break;
        default:
            loadMap("/home/matti/Documenti/PROGRAMMAZIONEUNI/AStarLabSDL/maps/map3.map",height,width);
            //loadMap("../maps/map1.map",height,width);
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
    instance = nullptr;
}

Map* Map::Istance(int nmap) {
    if(!instance)
        instance = new Map(nmap);
    return instance;
}


bool Map::loadMap(std::string path, int& height, int& width) {
    std::string line;
    std::ifstream mapFile(path);
    std::list<int> arrayUtil;
    bool successful = false;

    if(mapFile.is_open()) {

        width = 0;

        getline((mapFile),line);
        char cstr[line.size() +1];
        strcpy(cstr,line.c_str());

        char * tiles = strtok(cstr," ");
        while(tiles != NULL) {
            arrayUtil.push_back(atoi(tiles));
            tiles = strtok(NULL," ");
            width++;
        }

        height = 1;

        while(getline(mapFile,line)) {
            strcpy(cstr,line.c_str());
            char * tiles = strtok(cstr," ");
            while(tiles != NULL) {
                arrayUtil.push_back(atoi(tiles));
                tiles = strtok(NULL," ");

            }
            height++;
        }
        successful=true;
        lvlmap = new int[width * height];
        int i=0;
        for(int el : arrayUtil) {
            lvlmap[i] = el;
            i++;
        }
    }
    return successful;
}

