#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "TextureHandler.hpp"
#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

#include "screen.hpp"
#include "menu_screen.hpp"
#include "LTimer.hpp"

class Game
{
private:
    int count = 0;
    int health = 3;
    bool MSM_ChangingState;

    //The window renderer
    SDL_Window *MSM_Window;

    //GameStateHandler *MSM_GameStateHandler;

    Uint32 lastP;
    Screen *currentscreen;
    //do the same for the other screens

    std::string button_hover;
    bool MSM_Running;

    static Game *MSM_Instance;

    SDL_Color textcolor;
    TTF_Font *gFont = NULL;
    LTimer timer;

    int MSM_gameWidth;
    int MSM_gameHeight;
    float MSM_scrollSpeed;

    int MSM_playerLives;

    //the music to play
    Mix_Music *gameplay = NULL;

    //the sound effects to use
    Mix_Chunk *button = NULL;

    // int MSM_currentLevel;
    // int MSM_nextLevel;
    // bool MSM_LevelComplete;

    //vector string containing all level file updates
    std::vector<std::string> MSM_levelFiles;

    //to handle all texture changes in game
    int imageframe;
    TextureHandler game_texturehandler;

    SDL_Rect dest, src;
    SDL_Texture *background;
    Game(const Game &);
    Game &operator=(const Game &);

public:
    //window to be rendered to
    static SDL_Renderer *renderer;
    Game();
    ~Game();
    static Game *Instance()
    {
        if (MSM_Instance == 0)
        {
            MSM_Instance = new Game();
            return MSM_Instance;
        }
        return MSM_Instance;
    }

    bool init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    void render();
    void update(Uint32);
    void executeEvents(); //same as handling events
    void clean();

    SDL_Renderer *getRenderer() const { return renderer; }
    SDL_Window *getWindow() const { return MSM_Window; }

    //  GameStateHandler *getState() { return MSM_GameStateHandler; }

    //   void setPlayerLives(int lives) { MSM_playerLives = lives; }
    //   int getPlayerLives() { return MSM_playerLives; }

    //  void setCurrentLevel(int currentLevel);
    //  const int getCurrentLevel() { return MSM_currentLevel; }

    //   void setNextLevel(int nextLevel) { MSM_nextLevel = nextLevel; }
    //   const int getNextLevel() { return MSM_nextLevel; }

    //  void setLevelComplete(bool levelComplete) { MSM_LevelComplete = levelComplete; }
    //  const bool getLevelComplete() { return MSM_LevelComplete; }

    bool running() { return MSM_Running; }

    //same functionality as clean
    void quit() { MSM_Running = false; }

    void loadMedia();
    void resetgame();
    // movement *get_police();
    int getGameWidth() const { return MSM_gameWidth; }
    int getGameHeight() const { return MSM_gameHeight; }
    int getScrollSpeed() const { return MSM_scrollSpeed; }

    //   bool changingState() { return MSM_ChangingState; }
    //   void changingState(bool newstate) { MSM_ChangingState = newstate; }
    bool collisiondetect(SDL_Rect a, SDL_Rect b);
    std::vector<std::string> getLevelFiles() { return MSM_levelFiles; }
};

typedef Game MSM_Game;
