#include "Enemy.h"


Enemy::Enemy(int width, int hight, int x, int y, int health):Entity(width, hight, x, y){
    this->health = health;
};
