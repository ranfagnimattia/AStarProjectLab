//
// Created by matti on 10/09/18.
//

#ifndef ASTARLABSDL_PLAYER_H
#define ASTARLABSDL_PLAYER_H


#include <SDL_events.h>
#include "GameObject.h"

class Player : public GameObject {
public:
    Player(char *pathSprite, int x, int y, int speed);
    virtual ~Player();

};


#endif //ASTARLABSDL_PLAYER_H
