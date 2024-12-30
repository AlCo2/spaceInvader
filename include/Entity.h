#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED
#include <SDL.h>

class Entity{
protected:
    SDL_Texture* sprite;
    int width;
    int hight;
    int x;
    int y;
public:
    Entity(int width, int hight, int x, int y);
    Entity(int width , int hight, char* path, SDL_Renderer* renderer);
    Entity(int width, int hight, int x, int y, char* path, SDL_Renderer* renderer);
    int getWidth();
    int getHight();
    SDL_Texture* getSprite();
    int getY();
    int getX();
};

#endif // ENTITY_H_INCLUDED
