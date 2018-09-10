//
// Created by matti on 10/09/18.
//

#ifndef ASTARLABSDL_ENEMY_H
#define ASTARLABSDL_ENEMY_H


#include "GameObject.h"

class Enemy : public GameObject {
public:
    Enemy(char *pathSprite1, char *pathSprite2, int x, int y, int speed);

    virtual ~Enemy();

    virtual void Update() override;

};


#endif //ASTARLABSDL_ENEMY_H
