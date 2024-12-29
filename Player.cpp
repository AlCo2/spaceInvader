#include <SDL.h>
#include "Entity.h"
#include "Player.h"
#include "Bullet.h"

Player::Player(int width, int hight, int x, int y, int speed, int shootingSpeed, int damage):Entity(width, hight, x, y){
    this->speed = speed;
    this->shootingSpeed = shootingSpeed;
    this->damage = damage;
}

void Player::draw(SDL_Renderer* renderer)
{
    SDL_Rect rect = {x, y, width, hight};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
    //SDL_FillRect(surface, &rect, 0x008000);
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
