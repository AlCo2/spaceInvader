#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <SDL.h>
#include "Entity.h"
#include "Bullet.h"


class Player : public Entity{
private:
    int speed;
    int shootingSpeed;
    int damage;

public:
    Player(int width, int hight, int x, int y, int speed, int shootingSpeed, int damage);
    void draw(SDL_Surface* surface);
    void moveLeft();
    void moveRight();
    Bullet* shoot();

    int getX();
    int getY();
    int getWidth();
};

#endif // PLAYER_H_INCLUDED
