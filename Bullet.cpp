#include <SDL.h>
#include "Bullet.h"
#include <vector>
#include <iostream>
#include "Enemy.h"

std::vector<Bullet*> Bullet::bullets;

Bullet::Bullet(int x, int y, int speed, int bulletSize)
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->bulletSize = bulletSize;
}

int Bullet::getX(){
    return this->x;
}

int Bullet::getY()
{
    return this->y;
}

void Bullet::drawBullets(SDL_Renderer* renderer){
    for (Bullet* bullet:bullets)
    {
        bullet->draw(renderer);
    }
}

void Bullet::moveBullets(Enemy* enemy)
{
    for (auto i=bullets.begin();i<bullets.end();++i)
    {
        if (!enemy->isDead() && (*i)->isEnemyHit(enemy))
        {
            //TODO: Kill the enemy and delete it from screen
            enemy->damageEnemy(50);
            (*i)->deleteBullet();
            bullets.erase(i);
        }
        else if ((*i)->isBulletOut())
        {
            (*i)->deleteBullet();
            bullets.erase(i);
        }
        else
            (*i)->move();
    }
}

bool Bullet::isEnemyHit(Enemy* enemy)
{
    if (this->y == enemy->getY() + enemy->getHight() && this->getX() >= enemy->getX() && this->getX() <= enemy->getX() + enemy->getWidth())
        return true;
    return false;
}

bool Bullet::isBulletOut()
{
    return this->getY() < 0;
}

void Bullet::draw(SDL_Renderer* renderer)
{
    SDL_Rect rect = {x, y, bulletSize / 2, bulletSize};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Bullet::deleteBullet()
{
    delete this;
}

void Bullet::move()
{
    this->y-=speed;
}
