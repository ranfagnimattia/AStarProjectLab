//
// Created by matti on 10/09/18.
//

#include "Player.h"

Player::Player(char *pathSprite, int x, int y, int speed) : GameObject(pathSprite, x, y, speed) {}

Player::~Player() {

}

void Player::Update(int x, int y) {
    //GameObject::Update(x, y);
}

