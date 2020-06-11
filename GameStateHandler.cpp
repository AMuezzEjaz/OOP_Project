#include "GameStateHandler.hpp"
#include <iostream>

void GameStateHandler::clean()
{
    if (MSM_gameStates.empty() == false)
    {
        MSM_gameStates.back()->exiting();
        delete MSM_gameStates.back();
        MSM_gameStates.clear();
    }
}

void GameStateHandler::update()
{
    if (MSM_gameStates.empty() == false)
    {
        MSM_gameStates.back()->update();
    }
}

void GameStateHandler::render()
{
    if (MSM_gameStates.empty() == false)
    {
        MSM_gameStates.back()->render();
    }
}

void GameStateHandler::pushState(GameState_master *MSM_State)
{
    MSM_gameStates.push_back(MSM_State);
    MSM_gameStates.back()->entering();
}

void GameStateHandler::popState()
{
    if (MSM_gameStates.empty() == false)
    {
        MSM_gameStates.back()->exiting();
        MSM_gameStates.pop_back();
    }
    MSM_gameStates.back()->resume();
}

void GameStateHandler::changeState(GameState_master *MSM_State)
{
    if (MSM_gameStates.empty() == false)
    {
        if (MSM_gameStates.back()->getState() == MSM_State->getState())
        {
            return;
        }
        MSM_gameStates.back()->exiting();
        MSM_gameStates.pop_back();
    }
    MSM_State->entering();
    MSM_gameStates.push_back(MSM_State);
}
