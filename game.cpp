#include "Game.hpp"
#include "TextureHandler.hpp"
#include "InputHandler.hpp"
#include "MainMenu.hpp"
#include "GameOver.hpp"
#include <iostream>

using namespace std;

Game *Game::MSM_Instance = 0;

Game::Game() : MSM_Window(0), MSM_Renderer(0), MSM_Running(false), /*MSM_GameStateHandler(0), */ MSM_playerLives(3), MSM_scrollSpeed(0.8), MSM_LevelComplete(false), MSM_ChangingState(false)
{
    MSM_levelFiles.push_back("assets/game_map.png");

    MSM_currentLevel = 1;
}

Game::~Game()
{
    MSM_Renderer = 0;
    MSM_Window = 0;
}
bool Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;

    MSM_gameWidth = 994;
    MSM_gameHeight = 571;

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "SDL init is successful" << endl;

        MSM_Window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (MSM_Window != 0)
        {
            cout << "Window created successfully" << endl;
            MSM_Renderer = SDL_CreateRenderer(MSM_Window, -1, SDL_RENDERER_ACCELERATED);

            if (MSM_Renderer != 0)
            {
                cout << "Renderer creation is successful" << endl;
                SDL_SetRenderDrawColor(MSM_Renderer, 0, 0, 0, 255);
            }
            else
            {
                cout << "Renderer init failed" << endl;
                return false;
            }
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
    //MSM_GameStateHandler->changeState(new MainMenu()); //cwede

    MSM_Running = true;
    return true;
}
void Game::setCurrentLevel(int currentLevel)
{
    MSM_currentLevel = currentLevel;
    //MSM_GameStateHandler->changeState(new GameOver()); //skdj
    MSM_LevelComplete = false;
}

void Game::render()
{
    SDL_RenderClear(MSM_Renderer);
    //MSM_GameStateHandler->render();
    SDL_RenderPresent(MSM_Renderer);
}

void Game::update()
{
    //MSM_GameStateHandler->update();
}

void Game::executeEvents()
{
    InputHandler::Instance()->update();
}

void Game::clean()
{
    cout << "Destroying Memory" << endl;

    InputHandler::Instance()->clean();

    //MSM_GameStateHandler->clean();

    //MSM_GameStateHandler = 0;
    //delete MSM_GameStateHandler;

    TextureHandler::Instance()->clearTextures(); //dwdowdn

    SDL_DestroyWindow(MSM_Window);
    SDL_DestroyRenderer(MSM_Renderer);
    SDL_Quit();
}