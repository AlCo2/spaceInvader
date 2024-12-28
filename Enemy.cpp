#include "Enemy.h"


Enemy::Enemy(int width, int hight, int x, int y, int health):Entity(width, hight, x, y){
    this->health = health;
};

void Enemy::drawEnemy(SDL_Surface* surface)
{
    SDL_Rect rect = {x, y, width, hight};
    SDL_FillRect(surface, &rect, 0xffffff);
}
