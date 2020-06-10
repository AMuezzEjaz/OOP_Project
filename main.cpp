#include "game.hpp"
#include <iostream>

const int FPS = 60;
const int DELAY = 1000.0f / FPS;

int main()
{
    AllocConsole();
    freopen("CON", "w", stdout);

    Unit32 frameStart, frameTime;

    std::cout << "Game Init Attempt..." << std::endl;

    if (MSM_Game::Instance()->init("game_name", 100, 100, 640, 480, false))
    {
        std::cout << "Game Init Success!" << std::endl;
        while (MSM_Game::Instance()->running())
        {
            frameStart = SDL_GetTicks();

            MSM_Game::Instance()->executeEvents();
            MSM_Game::Instance()->update();
            MSM_Game::Instance()->reder();

            frameTime = SDL_GetTicks() - frameStart;

            if (frameTime < DELAY)
            {
                SDLDelay((int)(DELAY - frameTime)) :
            }
        }
    }
}
else
{
    std::cout << "Game Init Failed - " << SDL_GetError() << std::endl;
    return -1;
}

std::cout << "Game Closing..." << std::endl;
MSM_Game::Instance()->clean();

return 0;
