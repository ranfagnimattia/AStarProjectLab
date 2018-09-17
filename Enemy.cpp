//
// Created by matti on 10/09/18.
//

#include "Enemy.h"

Enemy::Enemy(char *pathSprite, int x, int y, int speed) : GameObject(pathSprite, x, y, speed) {}

Enemy::~Enemy() {
    directions.clear();
}





