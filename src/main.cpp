#include <SDL.h>
#include <SDL_mixer.h>
#include <Menu.h>
#include <Game.h>

using namespace std;

#define WIDTH 600
#define HIGHT 400

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    SDL_Window* window = SDL_CreateWindow("SpaceInvader", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    AppState state = AppState::MENU;
    Game game = Game(renderer);
    Menu menu = Menu(renderer);

    while (state != AppState::EXIT)
    {
        if (state == AppState::MENU)
        {
            state = menu.run();
        }
        else if (state == AppState::GAME)
        {
            state = game.run();
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return 0;
}
