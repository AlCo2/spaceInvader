#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int width, int hight, int x, int y, int health, char* path,SDL_Renderer* renderer):Entity(width, hight, x, y, path, renderer){
    this->health = health;
};

void Enemy::drawEnemy(SDL_Renderer* renderer)
{
    if (isDead())
        return;
    SDL_Rect rect = {x, y, width, hight};
    SDL_RenderCopy(renderer, this->sprite, NULL, &rect);
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
