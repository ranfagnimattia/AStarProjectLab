//
// Created by matti on 22/04/18.
//
#ifndef PROVASDL_GAME_H
#define PROVASDL_GAME_H
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <list>
#include <iostream>
#include "Subject.h"
#include "Player.h"
#include "Map.h"
#include "Enemy.h"

class Game : public Subject {
public:
    Game();
    virtual ~Game() override;

    void init(const char* title,int xpos,int ypos,int width,int height,bool fullscreen);
    void render();
    void clean(); //avoid memory leak and optimize
    void update();

    void notify();
    virtual void registerObserver(Observer *o) override;
    virtual void unregisterObserver(Observer *o) override;

    bool isRunning();
    void setRunning(bool b) {running = b;}
    void handleEvents();


    static SDL_Renderer *renderer;


private:
    bool running;
    SDL_Window *window;
    Player* player;
    std::list<Enemy *> enemies;
    std::list<Observer*> observers;
    int gameTimerStart;
    int enemiescount;
    //int count = 0;
    //int countmove=0;
};


#endif //PROVASDL_GAME_H
