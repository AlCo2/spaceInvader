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

void Bullet::drawBullets(SDL_Surface* surface){
    for (Bullet* bullet:bullets)
    {
        bullet->draw(surface);
    }
}

void Bullet::moveBullets()
{
    for (auto i=bullets.begin();i<bullets.end();++i)
    {
        //if (this->isEnemyHit())
        //{
         //   (*i)->deleteBullet();
          //  bullets.erase(i);
        //}
        if ((*i)->isBulletOut())
        {
            (*i)->deleteBullet();
            bullets.erase(i);
        }
        else
            (*i)->move();
    }
}

//bool Bullet::isEnemyHit(Enemy &enemy)
//{
//    if (this->y == enemy.getY())
//        return true;
//    return false;
//}

bool Bullet::isBulletOut()
{
    return this->getY() < 0;
}

void Bullet::draw(SDL_Surface* surface)
{
    SDL_Rect rect = {x, y, bulletSize / 2, bulletSize};
    SDL_FillRect(surface, &rect, 0xFF0000);
}

void Bullet::deleteBullet()
{
    delete this;
}

void Bullet::move()
{
    this->y-=speed;
}
