#include "Game.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include "Player.h"
#include "Animation.h"
#include "Enemy.h"
#include <algorithm>

#define WIDTH 600
#define HIGHT 400

enum KEY{
D,
A
};

Game::Game(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}

AppState Game::run()
{
    SDL_Event event;
    Mix_Music* music = NULL;
    Mix_Chunk* enemyKilledSound = NULL;
    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
    bool isRunning = true;

    Player player = Player(64, 64, WIDTH/2, HIGHT-64, 4, 2, 50, "assets/spaceShip.png", renderer);

    Enemy::initEnemies(renderer);

    SDL_Texture* background = loadTexture("assets/gameBackground.jpg", renderer);


    music = Mix_LoadMUS("sounds/song.mpeg");
    enemyKilledSound = Mix_LoadWAV("sounds/enemykilled.wav");
    Enemy::enemyKilledSound = enemyKilledSound;

    bool keys[] = {false, false};

    Uint32 lastUpdateTime = 0;
    Animation explosionAnimation = Animation("assets/spritesheet/first_explosion/spritesheet.png", renderer, 11, 32);

    while(isRunning)
    {
        // clear screen
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
        if( Mix_PlayingMusic() == 0 )
        {
            Mix_PlayMusic( music, -1 );
        }

        for (Animation* explosionAnimation : Enemy::animation)
        {
            if (!explosionAnimation->getIsActive())
            {
                auto it = std::find(Enemy::animation.begin(), Enemy::animation.end(), explosionAnimation);
                Enemy::animation.erase(it);
                delete explosionAnimation;
            }
            Animation::updateAnimation(explosionAnimation, 100);
            Animation::drawAnimation(explosionAnimation, renderer);
        }
        Bullet::moveBullets(Enemy::enemies, &explosionAnimation);
        Enemy::drawEnemies(renderer);
        Bullet::drawBullets(renderer);
        player.draw(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(5);
    }
    Mix_FreeMusic(music);
}
