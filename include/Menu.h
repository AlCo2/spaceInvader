#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SDL.h>
#include "Utils.h"

class Menu{
private:
    SDL_Renderer* renderer;

public:
    Menu(SDL_Renderer* renderer);

    AppState run();

};

#endif // MENU_H_INCLUDED
