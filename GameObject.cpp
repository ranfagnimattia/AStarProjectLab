//
// Created by matti on 02/05/18.
//

#include "GameObject.h"
#include "TextureManager.h"
GameObject::GameObject(char* pathSprite,int x,int y,int spd): pathSprite(pathSprite),xpos(x),ypos(y), speed(spd){
   objTexture= TextureManager::LoadTexture(pathSprite);
}

void GameObject::Render() {
    TextureManager::Draw(objTexture,srcRect,destRect);
}

void GameObject::setObjTexture(char* path) {
    pathSprite = path;
    objTexture=TextureManager::LoadTexture(pathSprite);
}

void GameObject::setSpeed(int speed) {
    GameObject::speed = speed;
}

int GameObject::getXpos() const {
    return xpos;
}

int GameObject::getYpos() const {
    return ypos;
}

char *GameObject::getPathSprite() const {
    return pathSprite;
}


int GameObject::getSpeed() const {
    return speed;
}

void GameObject::setPosition(int x, int y ) {
    xpos=x;
    ypos=y;
}
bool GameObject::checkCollision(const GameObject *obj, int maxdistance) {
    bool result=false;
    if(maxdistance >= abs(xpos - obj->getXpos()))
        result = true;
    return result;
}

GameObject::~GameObject() { }

void GameObject::Update(int x, int y) {
    srcRect.h = 16;
    srcRect.w = 16;
    srcRect.x = 160;
    srcRect.y = 240;

    destRect.h = 32;
    destRect.w = 32;

    destRect.y = xpos *32;
    destRect.x = ypos *32;
}
