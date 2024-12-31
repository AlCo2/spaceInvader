#include <iostream>
#include <vector>
#include <SDL_mixer.h>
#include "Enemy.h"
#include "Utils.h"
#include <Animation.h>

constexpr int Enemy::structure[4][7];
std::vector<std::vector<Enemy*>> Enemy::enemies;
Mix_Chunk* Enemy::enemyKilledSound;

Enemy::Enemy(int width, int hight, int x, int y, int health, char* path, SDL_Renderer* renderer):Entity(width, hight, x, y, path, renderer){
    this->health = health;
}

Enemy::Enemy(int width, int hight, int health, char* path, SDL_Renderer* renderer):Entity(width, hight, path, renderer)
{
    this->health = health;
}

void Enemy::initEnemies(SDL_Renderer* renderer)
{
    int x = 30;
    int y = 20;
    Animation normalExplosionAnimation = Animation("assets/spritesheet/first_explosion/spritesheet.png", renderer, 11, 32);
    Animation electricExplosionAnimation = Animation("assets/spritesheet/light_explosion/spritesheet.png", renderer, 16, 72);
    for (const auto& line : structure)
    {
        std::vector<Enemy *> temp;
        for (auto type : line)
        {
            Enemy* enemy = NULL;
            switch(type){
                case 0:
                    break;
                case 1:
                    enemy = new Enemy(40, 40, x, y, 300, "assets/enemyPink.png", renderer);
                    enemy->setExplosionAnimation(&electricExplosionAnimation);
                    temp.push_back(enemy);
                    break;
                case 2:
                    enemy = new Enemy(40, 40, x, y, 200, "assets/enemyGreen.png", renderer);
                    enemy->setExplosionAnimation(&normalExplosionAnimation);
                    temp.push_back(enemy);
                    break;
                case 3:
                    enemy = new Enemy(40, 40, x, y, 100, "assets/enemyBlue.png", renderer);
                    enemy->setExplosionAnimation(&normalExplosionAnimation);
                    temp.push_back(enemy);
                    break;
            }
            x += 85,5;
        }
        enemies.push_back(temp);
        x = 30;
        y += 40;
    }
}

void Enemy::setExplosionAnimation(Animation* explosionAnimation)
{
    this->explosionAnimation = explosionAnimation;
}

void Enemy::drawEnemies(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i=0;i<enemies.size();i++)
    {
        for (int j=0;j<enemies[i].size();j++)
        {
            if (enemies[i][j]->isDead())
                continue;
            SDL_Rect rect = {enemies[i][j]->getX(), enemies[i][j]->getY(), enemies[i][j]->getWidth(), enemies[i][j]->getHight()};
            SDL_RenderCopy(renderer, enemies[i][j]->getSprite(), NULL, &rect);
        }
    }
}

void Enemy::draw(SDL_Renderer* renderer)
{
    if (isDead())
        return;
    SDL_Rect rect = {x, y, width, hight};
    SDL_RenderCopy(renderer, this->sprite, NULL, &rect);
}

void Enemy::damageEnemy(int damage, Animation* explosionAnimation)
{
    this->health -= damage;
    if (this->isDead())
    {
        explosionAnimation->startAnimation(this->x, this->y);
        Mix_PlayChannel(-1, Enemy::enemyKilledSound, 0);
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
