//
// Created by matti on 10/09/18.
//

#include "Player.h"

Player::Player(char *pathSprite1, char *pathSprite2, int x, int y, int speed) : GameObject(pathSprite1, pathSprite2, x,
                                                                                           y, speed) {}

Player::~Player() {

}

void Player::Update() {
    srcRect.h=32;
    srcRect.w=32;
    srcRect.x=0;
    srcRect.y=0;

    destRect.x=xpos;
    destRect.y=ypos;
    destRect.w=srcRect.w*2;
    destRect.h=srcRect.h*2;
}
