#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int width, int hight, int x, int y, int health):Entity(width, hight, x, y){
    this->health = health;
};

void Enemy::drawEnemy(SDL_Surface* surface)
{
    if (isDead())
        return;
    SDL_Rect rect = {x, y, width, hight};
    SDL_FillRect(surface, &rect, 0xffffff);
}

void Enemy::damageEnemy(int damage)
{
    this->health -= damage;
    if (!this->isDead())
    {
        this->kill();
    }

}

void Enemy::kill()
{
    delete this;
}

bool Enemy::isDead()
{
    return this->health <= 0;
}
