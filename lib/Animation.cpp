#include "Animation.h"
#include <SDL.h>
#include "Utils.h"

Animation::Animation(char* path, SDL_Renderer* renderer, int total_frames, int frame_size)
{
    this->texture = loadTexture(path, renderer);
    this->frame = 0;
    this->isActive = false;
    this->total_frames = total_frames;
    this->frame_size = frame_size;
}

void Animation::updateAnimation(Animation* animation, int FRAME_DELAY)
{
    if (!animation->getIsActive()) {
        return;
    }

    Uint32 currentTime = SDL_GetTicks();
    Uint32 elapsedTime = currentTime - animation->getStartTime();

    animation->setFrame(elapsedTime / FRAME_DELAY);

    if (animation->getFrame()>= animation->getTotal_frames()) {
        animation->setIsActive(false);
        animation->setFrame(0);
    }
}

void Animation::drawAnimation(Animation* animation, SDL_Renderer* renderer)
{
    if (animation->getIsActive())
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_Rect srcRect = {animation->getFrame() * animation->getFrame_size(), 0, animation->getFrame_size(), animation->getFrame_size()};
        SDL_Rect destRect = {animation->getX(), animation->getY(), 40, 40};
        SDL_RenderCopy(renderer, animation->getTexture(), &srcRect, &destRect);
    }
}

void Animation::startAnimation(int x, int y)
{
    this->frame = 0;
    this->x = x;
    this->y = y;
    this->isActive = true;
    this->startTime = SDL_GetTicks();
}

bool Animation::getIsActive()
{
    return this->isActive;
}

void Animation::setX(int x)
{
    this->x = x;
}

void Animation::setY(int y)
{
    this->y = y;
}

int Animation::getX()
{
    return this->x;
}

int Animation::getY()
{
    return this->y;
}

int Animation::getTotal_frames()
{
    return this->total_frames;
}

int Animation::getFrame_size()
{
    return this->frame_size;
}

SDL_Texture* Animation::getTexture()
{
    return this->texture;
}

void Animation::setFrame_size(int frame_size)
{
    this->frame_size = frame_size;
}

int Animation::getFrame()
{
    return this->frame;
}

void Animation::setIsActive(bool isActive)
{
    this->isActive = isActive;
}
void Animation::setFrame(int frame)
{
    this->frame = frame;
}

Uint32 Animation::getStartTime()
{
    return this->startTime;
}

Animation::~Animation()
{
    //std::cout << "animation  deleted" << std::endl;
}
