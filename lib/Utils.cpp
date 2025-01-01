#include "Utils.h"
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <SDL_ttf.h>

SDL_Texture* loadTexture(char* path, SDL_Renderer* renderer)
{
    SDL_Surface* loadedSurface = IMG_Load(path);
    if (!loadedSurface) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (!texture)
    {
        printf("Unable to create texture from %s! SDL_Error: %s\n", path, SDL_GetError());
    }
    SDL_FreeSurface(loadedSurface);
    return texture;
}

void renderText(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, int x, int y, SDL_Color color)
{
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_Rect textRect = {x, y, textSurface->w, textSurface->h};
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}
