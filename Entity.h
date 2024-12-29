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
    Entity(int width, int hight, int x, int y, SDL_Texture* sprite);
    int getWidth();
    int getHight();
    int getY();
    int getX();
};

#endif // ENTITY_H_INCLUDED
