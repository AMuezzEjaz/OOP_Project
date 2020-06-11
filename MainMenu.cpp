#include <iostream>
#include "MainMenu.hpp"
#include "TextureHandler.hpp"
#include "game.hpp"
#include "InputHandler.hpp"
//#include "PlayState.hpp"
//#include "MenuButton.hpp"
#include <assert.h>

const std::string MainMenu::MSM_menu = "MENU";

void MainMenu::MSM_startPlay()
{
    MSM_Game::Instance()->getState()->changeState(new Playstate());
}

void MainMenu::MSM_exitMenu()
{
    MSM_Game::Instance()->quit();
}

void MainMenu::update()
{
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ENTER))
    {
        MSM_startPlay();
    }
    if (MSM_gameObjects.empty() == false)
    {
        for (int i = 0; i < MSM_gameObjects.size(); i++)
        {
            if (MSM_gameObjects[i] 1 = 0)
            {
                MSM_gameObjects[i]->update();
            }
        }
    }
}

void MainMenu::render()
{
    if (MSM_loadingDone && MSM_gameObjects.empty() == false)
    {
        for (int i = 0; i < MSM_gameObjects.size(); i++)
        {
            MSM_gameObjects[i]->draw();
        }
    }
}

bool MainMenu::afterEntering()
{
    // Add stuff later on
    return true;
}

bool MainMenu::afterExiting()
{
    MSM_exiting = true;
    if (MSM_loadingDone && MSM_gameObjects.empty() == false)
    {
        MSM_gameObjects.back()->clean();
        MSM_gameObjects.pop_back();
    }
    MSM_gameObjects.clear();
    // clear textureHandler
    InputHandler::Instance()->reset();
    return true;
}

/*void MainMenu::setCallbacks(const std::vector<Callback> &callbacks)
{
    if (MSM_gameObjects.empty() == false)
    {
        for (int i = 0; i < MSM_gameObjects.size(); i++)
        {
            if (dynamic_cast<MenuButton *>(MSM_gameObjects[i]))
            {
                MenuButton *MSM_Button = dynamic_cast<MenuButton *>(MSM_gameObjects[i]);
                MSM_Button->setCallback(callbacks[MSM_Button->getCallback()]);
            }
        }
    }
}*/