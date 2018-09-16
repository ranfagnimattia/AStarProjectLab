//
// Created by matti on 22/04/18.
//
#ifndef PROVASDL_GAME_H
#define PROVASDL_GAME_H
#include <iostream>
#include <list>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Player.h"
#include "Enemy.h"
#include "Map.h"


class Game {
public:
    Game();
    virtual ~Game();

    void init(const char* title,int xpos,int ypos,int width,int height,bool fullscreen);
    void render();
    void clean(); //avoid memory leak and optimize
    void update();

    bool isRunning();
    void setRunning(bool b) {running = b;}
    void handleEvents();

    static SDL_Renderer *renderer;

private:
    bool running;
    SDL_Window *window;
    Player* player;
    std::list<Enemy*> enemies;
    int gameTimerStart;
    int enemiescount;
};


#endif //PROVASDL_GAME_H
