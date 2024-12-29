#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <SDL.h>
#include "Entity.h"

class Enemy : public Entity{

private:
    int health;
public:
    Enemy(int width, int hight, int x, int y, int health);
    void drawEnemy(SDL_Renderer* renderer);
    void damageEnemy(int damage);
    void kill();
    bool isDead();
};

#endif // ENEMY_H_INCLUDED
