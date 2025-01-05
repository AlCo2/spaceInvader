#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED
#include <vector>
#include <SDL.h>
#include "Enemy.h"
#include "Animation.h"

class Bullet{

private:
    int x;
    int y;
    int speed;
    int bulletSize;
    bool isBulletOut();

public:
    static std::vector<Bullet*> bullets;

    Bullet(int x, int y, int speed, int bulletSize);
    void move();
    void draw(SDL_Renderer* renderer);
    static void drawBullets(SDL_Renderer* renderer);
    static void moveBullets(std::vector<std::vector<Enemy*>> enemies, Player* player, Animation* explosionAnimation);
    bool isEnemyHit(Enemy* enemy);
    void deleteBullet();
    int getX();
    int getY();
};


#endif // BULLET_H_INCLUDED
