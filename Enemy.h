//
// Created by matti on 10/09/18.
//

#ifndef ASTARLABSDL_ENEMY_H
#define ASTARLABSDL_ENEMY_H

#include <deque>
#include "GameObject.h"
#include "MapSearchNode.h"

class Enemy : public GameObject {
public:
    Enemy(char *pathSprite, int x, int y, int speed);
    virtual ~Enemy();

    std::deque<MapSearchNode*> directions;
};


#endif //ASTARLABSDL_ENEMY_H
