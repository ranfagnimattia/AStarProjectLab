//
// Created by matti on 22/04/18.
//

#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"
#include "MapSearchNode.hpp"
#include "Enemy.h"

Map* map = nullptr;
SDL_Renderer* Game::renderer = nullptr;
Game::Game() {

}
Game::~Game() {

}

void Game::init(const char* title,int xpos,int ypos,int width,int height,bool fullscreen) {
    std::string initimput;
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized!!"<<std::endl;
        int flags= fullscreen?SDL_WINDOW_FULLSCREEN:0;
        window=SDL_CreateWindow(title,xpos,ypos,width,height,flags);
        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer) {
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            std::cout << "Renderer created!" << std::endl;
        }
        running = true;
    }
    else {
        running = false;

    }
    map = new Map();
    //get event to start the game (first step)
    std::cout << "Press any key and press ENTER to start the game: ";
    std:: cin >> initimput;
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    Player* player = nullptr;
    if(auto gameobj = dynamic_cast<Player*>(observers.front())) {
        player=gameobj;
    }
    switch(event.type) {
        case SDL_QUIT:
            running=false;
            break;
        //press arrows->move and notify
        case SDLK_UP:
            if(player->getYpos()+1 < Map::height)
                player->setPosition(player->getXpos(),player->getYpos()+1);
            break;
        case SDLK_DOWN:
            if(player->getYpos()-1 < Map::height)
                player->setPosition(player->getXpos(),player->getYpos()-1);
            break;
        case SDLK_LEFT:
            if(player->getXpos()-1 < Map::width)
                player->setPosition(player->getXpos()-1,player->getYpos());
            break;
        case SDLK_RIGHT:
            if(player->getXpos()+1 < Map::width)
                player->setPosition(player->getXpos()+1,player->getYpos());
            break;
        default:
            break;

    }
}

void Game::notify() {
    for(auto ob : observers) {
        //ob->Update();
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    map->drawMap();
    for(auto obs : observers) {
        if(auto gameobj = dynamic_cast<GameObject*>(obs))
            gameobj->Render();
    }
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned." << std::endl;
}

bool Game::isRunning() {return running;}


void Game::registerObserver(Observer *o) {
    observers.push_back(o);
}

void Game::unregisterObserver(Observer *o) {
    observers.remove(o);
}
