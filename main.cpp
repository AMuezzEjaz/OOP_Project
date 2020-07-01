#include "game.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <stdint.h>
#include <iostream>
#include <string>
#include <sstream>

//Prefered FPS
const int FPS = 60;
//Delay for User viewing
const int DELAY = 1000.0f / FPS;
Game *game = NULL;

int main(int argc, char **argv[])
{

    Uint32 frameStart;
    int frameTime;

    std::cout << "Game Init Attempt..." << std::endl;
    //checking initialization of game
    if (MSM_Game::Instance()->init("COVID 19", 100, 100, 640, 480, false))
    {
        std::cout << "Game Init Success!" << std::endl;

        //while the game is working
        while (MSM_Game::Instance()->running())
        {
            frameStart = SDL_GetTicks();

            MSM_Game::Instance()->executeEvents(); //handles events
            MSM_Game::Instance()->update(DELAY);
            MSM_Game::Instance()->render();

            frameTime = SDL_GetTicks() - frameStart;

            if (frameTime < DELAY)
            {
                SDL_Delay((int)(DELAY - frameTime));
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
}
