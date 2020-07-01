#pragma once
#include "game.hpp"

//#include "GameOver.hpp"
#include "movement.hpp"
#include <iostream>
#include "Player.hpp"
#include "linkedlist.hpp"

linkedlist keep;
movement *police;
Player *player;
GameObject *bg;
using namespace std;

Game *Game::MSM_Instance = 0;

SDL_Renderer *MSM_Game::renderer = NULL;

Game::Game() : MSM_Window(0), MSM_Running(false), MSM_playerLives(3), MSM_scrollSpeed(0.8), MSM_ChangingState(false)
{
    MSM_levelFiles.push_back("assets/game_map.png");
    src.h = 500;
    src.w = 500;
    src.x = 0;
    src.y = 0;
    dest.x = 0;
    dest.y = 0;
    dest.w = src.w * 4;
    dest.h = src.h * 4;
    const char *address = "assets/game_map.png";
    background = TextureHandler::loadTexture(renderer, address);
    lastP = 0;
    //level indication
    //MSM_currentLevel = 1;
}

Game::~Game()
{
    renderer = 0;
    MSM_Window = 0;
}
bool Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;

    MSM_gameWidth = 800;
    MSM_gameHeight = 600;

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "SDL init is successful" << endl;
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }
        MSM_Window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (MSM_Window != 0)
        {
            cout << "Window created successfully" << endl;
            renderer = SDL_CreateRenderer(MSM_Window, -1, SDL_RENDERER_ACCELERATED);

            if (renderer != 0)
            {
                cout << "Renderer creation is successful" << endl;
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            }
            else
            {
                cout << "Renderer init failed" << endl;
                return false;
            }

            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags))
            {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
            }

            //Initialize SDL_ttf
            if (TTF_Init() == -1)
            {
                printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
            }
            if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
            {
                printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
            }
            else
            {
                cout << "Window init failed" << endl;
                return false;
            }
        }
        else
        {
            cout << "SDL init failed" << endl;
            return false;
        }

        //MSM_GameStateHandler = new GameStateHandler();
        //MSM_GameStateHandler->changeState(new MainMenu());

        return true;
    }

    //    void Game::setCurrentLevel(int currentLevel)
    //    {
    //        MSM_currentLevel = currentLevel;
    //        MSM_GameStateHandler->changeState(new GameOver());
    //        MSM_LevelComplete = false;
    //    }

    this->loadMedia();
    srand(time(NULL));
    Mix_PlayMusic(gameplay, -1);

    //health status object needed
    police = new movement(renderer, "assets/police.png", 0, rand() % 450 + 1, false);
    player = new Player(renderer, "assets/character.png", 0, 500, false);
    bg = new GameObject(renderer, "assets/game_map.png", 0, 0, false);
    keep.cnode(new movement(renderer, "assets/police.png", 0, rand() % 450 + 1, false));
}
void Game::render()
{
    SDL_RenderClear(renderer);
    currentscreen->render(renderer);

    //texture changing updates here

    SDL_RenderPresent(renderer);
}

void Game::executeEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            MSM_Running = false;
            Mix_HaltMusic();
            break;
        }

        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_LEFT)
            {
                player->goleft();
            }
            else if (event.key.keysym.sym == SDLK_RIGHT)
            {
                player->goright();
            }
        }

        if (event.type == SDL_KEYUP)
        {
            if (event.key.keysym.sym == SDLK_UP)
            {
                player->goup();
            }
        }

        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_DOWN)
            {
                player->godown();
            }
        }

        if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP)
        {
            int x, y;
            SDL_GetMouseState(&x, &y);

            button_hover = currentscreen->button_hover(x, y);

            if (event.type == SDL_MOUSEBUTTONDOWN && button_hover != "no hover")
            {
                if (button_hover == "play button")
                {
                    Mix_PlayChannel(-1, button, 0);
                    // currentscreen = the game screen ;
                    if (!timer.isStarted())
                    {
                        timer.start();
                    }
                }

                if (button_hover == "help button")
                {
                    //currentscreen = how to play screen;
                    Mix_PlayChannel(-1, button, 0);
                }
            }
        }
    }
}

void Game::update(Uint32 framerate)
{
}

bool Game::collisiondetect(SDL_Rect a, SDL_Rect b)
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;
    //If any of the sides from A are outside of B
    if (bottomA <= topB)
    {
        return false;
    }

    if (topA >= bottomB)
    {
        return false;
    }

    if (rightA <= leftB)
    {
        return false;
    }

    if (leftA >= rightB)
    {
        return false;
    }
    return true;
}

void Game::clean()
{
    cout << "Destroying Memory" << endl;
    delete player;
    if (police != NULL)
    {
        delete police;
    }

    //InputHandler::Instance()->clean();

    //MSM_GameStateHandler->clean();

    //MSM_GameStateHandler = 0;
    //delete MSM_GameStateHandler;

    //remove global font
    TTF_CloseFont(gFont);
    gFont = NULL;

    delete bg;
    SDL_DestroyWindow(MSM_Window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Game::loadMedia()
{
    gameplay = Mix_LoadMUS("sounds/backgroundmusic.mp3 ");
    if (gameplay == NULL)
    {
        printf("Failed to load game play music! SDL_mixer Error: %s\n", Mix_GetError());
    }

    button = Mix_LoadWAV("sounds/buttonclick.mp3");

    if (button == NULL)
    {
        printf("Failed to load button sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    }
}

//movement Game::get_police()
/*{
    Uint32 timenow = SDL_GetTicks();
    movement *moveit = NULL;
    bool allow = 0 + (rand() % (1 - 0 + 1)) == 1;
    if (timenow - lastP >= 3000)
    {

        if (allow)
        {
            moveit = new movement(renderer, "assets/police.PNG", rand() % 200 + 550, rand() % 350 + 100, allow);
        }
        else
        {
            moveit = new movement(renderer, "assets/virus.PNG", rand() % 200 + 1, rand() % 350 + 100, allow);
        }
        lastP = timenow;
    }
}*/

void Game::resetgame()
{
    player->reset();
    police->reset();

    if (timer.isStarted())
    {
        timer.stop();
    }
}