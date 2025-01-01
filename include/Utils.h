#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include <SDL.h>
#include <string>
#include "SDL_ttf.h"


enum AppState { MENU, GAME, EXIT };

SDL_Texture* loadTexture(char* path, SDL_Renderer* renderer);

void renderText(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, int x, int y, SDL_Color color);

#endif // UTILS_H_INCLUDED
