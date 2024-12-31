#include <SDL.h>
#include <SDL_mixer.h>

using namespace std;

#define WIDTH 600
#define HIGHT 400

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    SDL_Window* window = SDL_CreateWindow("SpaceInvader", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return 0;
}
