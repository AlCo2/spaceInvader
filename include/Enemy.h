#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <SDL.h>
#include <vector>
#include <SDL_mixer.h>
#include "Entity.h"
#include "Animation.h"


class Enemy : public Entity{

private:
    int health;
    Animation* explosionAnimation;

    static constexpr int structure[4][7] = {
        {0, 0, 1, 1, 1, 0, 0},
        {2, 2, 2, 2, 2, 2, 2},
        {3, 2, 0, 3, 0, 2, 3},
        {3, 3, 3, 3, 3, 3, 3}
    };
public:
    static Mix_Chunk* enemyKilledSound;
    static std::vector<std::vector<Enemy*>> enemies;
    static void initEnemies(SDL_Renderer* renderer);
    static void drawEnemies(SDL_Renderer* renderer);

    Enemy(int width, int hight, int x, int y, int health, char* path, SDL_Renderer* renderer);
    Enemy(int width, int hight, int health, char* path, SDL_Renderer* renderer);
    void draw(SDL_Renderer* renderer);
    void damageEnemy(int damage, Animation* explosionAnimation);
    void setExplosionAnimation(Animation* explosionAnimation);
    void kill();
    bool isDead();
};

#endif // ENEMY_H_INCLUDED
