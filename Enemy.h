#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <SDL.h>
#include "Entity.h"

class Enemy : public Entity{
private:
    int health;
public:
    Enemy(int width, int hight, int x, int y, int health);

    void drawEnemy(SDL_Surface* surface)
    {
        SDL_Rect rect = {width, hight, x, y};
        SDL_FillRect(surface, &rect, 0xffffff);
    }
};

#endif // ENEMY_H_INCLUDED
