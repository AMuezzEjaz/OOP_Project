#include "C:\mingw_dev_lib\include\SDL2\SDL.h"
#include "GameStateHandler.hpp"
#include <vector>

class Game
{
private:
    bool MSM_ChangingState;

    SDL_Window *MSM_Window;
    SDL_Renderer *MSM_Renderer;

    //GameStateHandler *MSM_GameStateHandler;

    bool MSM_Running;

    static Game *MSM_Instance;

    int MSM_gameWidth;
    int MSM_gameHeight;
    float MSM_scrollSpeed;

    int MSM_playerLives;

    int MSM_currentLevel;
    int MSM_nextLevel;
    bool MSM_LevelComplete;

    std::vector<std::string> MSM_levelFiles;

    Game();
    ~Game();

    Game(const Game &);
    Game &operator=(const Game &);

public:
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
    void update();
    void executeEvents();
    void clean();

    SDL_Renderer *getRenderer() const { return MSM_Renderer; }
    SDL_Window *getWindow() const { return MSM_Window; }
    //GameStateHandler *getState() { return MSM_GameStateHandler; }

    void setPlayerLives(int lives) { MSM_playerLives = lives; }
    int getPlayerLives() { return MSM_playerLives; }

    void setCurrentLevel(int currentLevel);
    const int getCurrentLevel() { return MSM_currentLevel; }

    void setNextLeve(int nextLevel) { MSM_nextLevel = nextLevel; }
    const int getNextLevel() { return MSM_nextLevel; }

    void setLevelComplete(bool levelComplete) { MSM_LevelComplete = levelComplete; }
    const bool getLevelComplete() { return MSM_LevelComplete; }

    bool running() { return MSM_Running; }

    void quit() { MSM_Running = false; }

    int getGameWidth() const { return MSM_gameWidth; }
    int getGameHeight() const { return MSM_gameHeight; }
    int getScrollSpeed() const { return MSM_scrollSpeed; }

    bool changingState() { return MSM_ChangingState; }
    void changingState(bool newstate) { MSM_ChangingState = newstate; }

    std::vector<std::string> getLevelFiles() { return MSM_levelFiles; }
};
