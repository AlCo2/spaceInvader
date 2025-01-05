#include <SDL.h>
#include "Bullet.h"
#include <vector>
#include <iostream>
#include "Enemy.h"
#include "Animation.h"

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

void Bullet::moveBullets(std::vector<std::vector<Enemy*>> enemies, Player* player, Animation* explosionAnimation)
{
    for (auto i=bullets.begin();i<bullets.end();++i)
    {
        for (int x=0;x<enemies.size();x++)
        {
            for (int y=0;y<enemies[x].size();y++)
            {
                if (!enemies[x][y]->isDead() && (*i)->isEnemyHit(enemies[x][y]))
                {
                    enemies[x][y]->damageEnemy(player);
                    (*i)->deleteBullet();
                    bullets.erase(i);
                    return;
                }
                else if ((*i)->isBulletOut())
                {
                    (*i)->deleteBullet();
                    bullets.erase(i);
                    return;
                }
            }
        }
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
    SDL_Rect rect = {x, y - 10, bulletSize / 2, bulletSize};
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
