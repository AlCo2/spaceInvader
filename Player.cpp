#include <SDL.h>
#include "Entity.h"
#include "Player.h"
#include "Bullet.h"

Player::Player(int width, int hight, int x, int y, int speed, int shootingSpeed, int damage, char* path, SDL_Renderer* renderer):Entity(width, hight, x, y, path, renderer){
    this->speed = speed;
    this->shootingSpeed = shootingSpeed;
    this->damage = damage;
}

void Player::draw(SDL_Renderer* renderer)
{
    SDL_Rect rect = {x, y, width, hight};
    SDL_RenderCopy(renderer, this->sprite, NULL, &rect);
}

void Player::moveLeft(){
    this->x -= speed;
}

void Player::moveRight(){
    this->x += speed;
}

Bullet* Player::shoot(){
    Bullet* bullet = new Bullet(this->getX() + (width / 2) - 4, this->getY(), this->shootingSpeed, 10);
    return bullet;
}

int Player::getX()
{
    return this->x;
}

int Player::getY()
{
    return this->y;
}

int Player::getWidth()
{
    return this->width;
}
