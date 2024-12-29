#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"


Entity::Entity(int width , int hight, int x, int y)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->hight = hight;
}
Entity::Entity(int width , int hight, int x, int y, char* path, SDL_Renderer* renderer)
{
    SDL_Surface* loadedSurface = IMG_Load(path);
    if (!loadedSurface) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
    }
    this->sprite = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (!this->sprite)
    {
        printf("Unable to create texture from %s! SDL_Error: %s\n", path, SDL_GetError());
    }
    SDL_FreeSurface(loadedSurface);
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
