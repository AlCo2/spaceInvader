#include "Menu.h"
#include "Game.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Utils.h"


Menu::Menu(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}

AppState Menu::run()
{
    TTF_Init();
    SDL_Event event;
    bool isRunning = true;
    TTF_Font* optionFont = TTF_OpenFont("assets/arialbd.ttf", 25);
    TTF_Font* titleFont = TTF_OpenFont("assets/arialbd.ttf", 50);
    int selectedOption = 0;
    SDL_Color yellow = {255, 255, 0, 255};
    SDL_Color white = {255, 255, 255, 255};

    SDL_Texture* background = loadTexture("assets/menu.jpg", renderer);

    while(isRunning)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background, NULL, NULL);
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                return AppState::EXIT;
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_UP:
                        if (selectedOption > 0)
                            selectedOption--;
                        break;
                    case SDLK_DOWN:
                        if (selectedOption < 1)
                            selectedOption +=1;
                        break;
                    case SDLK_RETURN:
                        if (selectedOption == 0)
                        {
                            return AppState::GAME;
                        }
                        else if (selectedOption == 1)
                        {
                            return AppState::EXIT;
                        }
                        break;
                }
            }
        }
        renderText(renderer, titleFont, "Space Invaders", 150, 50, white);
        renderText(renderer, optionFont, "Start Game", 200, 200, selectedOption==0?yellow:white);
        renderText(renderer, optionFont, "Exit", 200, 250, selectedOption==1?yellow:white);

        SDL_RenderPresent(renderer);
    }
}
