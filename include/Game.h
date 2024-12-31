#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL.h>

class Game{
private:
    SDL_Renderer* renderer;
public:
    Game(SDL_Renderer* renderer);
    void run();
};

#endif // GAME_H_INCLUDED
