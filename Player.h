//
// Created by matti on 10/09/18.
//

#ifndef ASTARLABSDL_PLAYER_H
#define ASTARLABSDL_PLAYER_H


#include "GameObject.h"

class Player : public GameObject {
public:
    Player(char *pathSprite, int x, int y, int speed);
    virtual ~Player();
    virtual void Update(int x,int y) override;



};


#endif //ASTARLABSDL_PLAYER_H
