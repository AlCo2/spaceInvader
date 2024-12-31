#include <iostream>
#include <vector>
#include <SDL_mixer.h>
#include "Enemy.h"
#include "Utils.h"
#include <Animation.h>

constexpr int Enemy::structure[4][7];
std::vector<std::vector<Enemy*>> Enemy::enemies;
std::vector<Animation*> Enemy::animation;
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
    for (const auto& line : structure)
    {
        std::vector<Enemy *> temp;
        Animation* normalExplosionAnimation;
        Animation* ExplosionAnimation;
        Animation* electricExplosionAnimation;
        for (auto type : line)
        {
            Enemy* enemy = NULL;
            switch(type){
                case 0:
                    break;
                case 1:
                    enemy = new Enemy(40, 40, x, y, 300, "assets/enemyPink.png", renderer);
                    electricExplosionAnimation = new Animation("assets/spritesheet/light_explosion/spritesheet.png", renderer, 16, 72);
                    enemy->setExplosionAnimation(electricExplosionAnimation);
                    temp.push_back(enemy);
                    break;
                case 2:
                    enemy = new Enemy(40, 40, x, y, 200, "assets/enemyGreen.png", renderer);
                    normalExplosionAnimation = new Animation("assets/spritesheet/shoke_explosion/spritesheet.png", renderer, 7, 140);
                    enemy->setExplosionAnimation(normalExplosionAnimation);
                    temp.push_back(enemy);
                    break;
                case 3:
                    enemy = new Enemy(40, 40, x, y, 100, "assets/enemyBlue.png", renderer);
                    normalExplosionAnimation = new Animation("assets/spritesheet/first_explosion/spritesheet.png", renderer, 11, 32);
                    enemy->setExplosionAnimation(normalExplosionAnimation);
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

void Enemy::damageEnemy(int damage)
{
    this->health -= damage;
    if (this->isDead())
    {
        this->explosionAnimation->startAnimation(this->x, this->y);
        Enemy::animation.push_back(this->explosionAnimation);
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

Enemy::~Enemy(){
    //std::cout << "Enemy deleted" << std::endl;
}
