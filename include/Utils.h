#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include <SDL.h>

typedef struct Explosion{
    int frame;
    int x, y;
    Uint32 startTime;
    bool isActive = false;
}Explosion;

SDL_Texture* loadTexture(char* path, SDL_Renderer* renderer);
void updateAnimation(Explosion *explosion);


#endif // UTILS_H_INCLUDED
