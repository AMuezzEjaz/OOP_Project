#include <vector>
#include "gameState_master.hpp"

class GameStateHandler
{
public:
    GameStateHandler() {}
    ~GameStateHandler() {}
    void update();
    void render();
    void pushState(GameState_master *MSM_State);
    void changeState(GameState_master *MSM_State);
    void popState();
    void clean();
    std::vector<GameState_master *> &getGameStates() { return MSM_gameStates; }

private:
    std::vector<GameState_master *> MSM_gameStates;
};