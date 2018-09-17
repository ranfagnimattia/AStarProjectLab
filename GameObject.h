//
// Created by matti on 02/05/18.
//

#ifndef PROVASDL_GAMEOBJECT_H
#define PROVASDL_GAMEOBJECT_H

#include <SDL_system.h>

class GameObject{

public:
    GameObject(char * pathSprite,int x=0, int y=0,int speed=1);
    virtual ~GameObject();

    void Render();

    virtual void Update();

    //getter and setter
    int getXpos() const;
    int getYpos() const;
    void setObjTexture(char * path);
    void setSpeed(int speed);
    bool checkCollision(const GameObject* obj, int maxdistance=30);
    int getSpeed() const;
    //void collisionMovement(GameObject* obj, int maxdistance=30, int range=15, int shakes=2,bool collided=false);
    char *getPathSprite() const;
    void setPosition(int x,int y);

protected:
    int xpos;
    int ypos;
    int speed;
    char* pathSprite;
    SDL_Texture* objTexture;
    SDL_Rect srcRect,destRect;
};




#endif //PROVASDL_GAMEOBJECT_H
