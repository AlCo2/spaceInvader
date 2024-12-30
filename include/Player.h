#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <SDL.h>
#include "Entity.h"
#include "Bullet.h"
#include "SDL_mixer.h"

class Player : public Entity{
private:
    int speed;
    int shootingSpeed;
    int damage;
    Mix_Chunk* shootSound = NULL;

public:
    Player(int width, int hight, int x, int y, int speed, int shootingSpeed, int damage, char* path,SDL_Renderer* renderer);
    void draw(SDL_Renderer* renderer);
    void moveLeft();
    void moveRight();
    Bullet* shoot();

    int getX();
    int getY();
    int getWidth();
};

#endif // PLAYER_H_INCLUDED
