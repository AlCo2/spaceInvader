#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED
#include <SDL.h>

class Animation{

private:
    int frame;
    int frame_size;
    int total_frames;
    int x;
    int y;
    Uint32 startTime;
    bool isActive;
    SDL_Texture* texture;

public:
    Animation(char* path, SDL_Renderer* renderer, int total_frames, int frame_size);

    static void updateAnimation(Animation* animation, int FRAME_DELAY);
    static void drawAnimation(Animation animation, SDL_Renderer* renderer);
    void startAnimation(int x, int y);

    Uint32 getStartTime();
    bool getIsActive();
    int getX();
    int getFrame();
    int getY();
    int getFrame_size();
    int getTotal_frames();
    SDL_Texture* getTexture();

    void setY(int y);
    void setX(int x);
    void setFrame(int frame);
    void setFrame_size(int frame_size);
    void setIsActive(bool isActive);

};
#endif // ANIMATION_H_INCLUDED
