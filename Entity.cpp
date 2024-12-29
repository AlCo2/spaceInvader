#include <SDL.h>
#include "Entity.h"

Entity::Entity(int width , int hight, int x, int y)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->hight = hight;
}
Entity::Entity(int width , int hight, int x, int y, SDL_Texture* sprite)
{
    this->sprite = sprite;
    this->x = x;
    this->y = y;
    this->width = width;
    this->hight = hight;
}
int Entity::getY()
{
    return this->y;
}
int Entity::getX()
{
    return this->x;
}
int Entity::getHight()
{
    return this->hight;
}
int Entity::getWidth()
{
    return this->width;
}
