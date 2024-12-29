#include <SDL.h>
#include <iostream>
#include "Player.h"
#include <vector>
#include "Enemy.h"
using namespace std;

#define WIDTH 600
#define HIGHT 400

enum KEY{
D,
A
};

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Event event;
    SDL_Window* window = SDL_CreateWindow("SpaceInvader", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    bool isRunning = true;

    SDL_Rect clear_rect = {0, 0, WIDTH, HIGHT};

    Player player = Player(50, 50, 100, HIGHT-50, 4, 2, 50);
    Enemy* enemy = new Enemy(50, 50, 100, 40, 100);

    bool keys[] = {false, false};

    while(isRunning)
    {
        // clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                isRunning = false;

            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_d:
                        keys[KEY::D] = true;
                        break;
                    case SDLK_a:
                        keys[KEY::A] = true;
                        break;
                    case SDLK_SPACE:
                        Bullet* bullet = player.shoot();
                        Bullet::bullets.push_back(bullet);
                        break;
                }
            }
            else if (event.type == SDL_KEYUP)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_d:
                        keys[KEY::D] = false;
                        break;
                    case SDLK_a:
                        keys[KEY::A] = false;
                        break;
                }
            }
        }

        if (keys[KEY::A])
        {
            if (player.getX() > 0 )
                player.moveLeft();
        }

        if (keys[KEY::D])
        {
            if (player.getX() < WIDTH - player.getWidth())
                player.moveRight();
        }
        Bullet::moveBullets(enemy);
        Bullet::drawBullets(renderer);
        enemy->drawEnemy(renderer);
        player.draw(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(5);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return 0;
}
