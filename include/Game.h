#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL.h>
#include "Utils.h"

class Game{
private:
    SDL_Renderer* renderer;
public:
    Game(SDL_Renderer* renderer);
    AppState run();
};

#endif // GAME_H_INCLUDED
