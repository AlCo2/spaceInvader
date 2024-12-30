#include <iostream>
#include <vector>
#include "Enemy.h"


constexpr int Enemy::structure[4][7];
std::vector<std::vector<Enemy*>> Enemy::enemies;

Enemy::Enemy(int width, int hight, int x, int y, int health, char* path,SDL_Renderer* renderer):Entity(width, hight, x, y, path, renderer){
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
        for (auto enemy : line)
        {
            switch(enemy){
                case 0:
                    break;
                case 1:
                    Enemy* enemy = new Enemy(40, 40, x, y, 100, "assets/enemySpace.png", renderer);
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

void Enemy::drawEnemies(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i=0;i<enemies.size();i++)
    {
        for (int j=0;j<enemies[i].size();j++)
        {
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
