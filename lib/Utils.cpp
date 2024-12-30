#include "Utils.h"
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

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
