//
// Created by matti on 10/09/18.
//

#ifndef ASTARLABSDL_PLAYER_H
#define ASTARLABSDL_PLAYER_H


#include "GameObject.h"

class Player : public GameObject {
public:
    Player(char *pathSprite1, char *pathSprite2, int x, int y, int speed);

    virtual ~Player();

    virtual void Update() override;

};


#endif //ASTARLABSDL_PLAYER_H
