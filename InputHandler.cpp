#include "InputHandler.hpp"
#include "game.hpp"
#include <iostream>

InputHandler *InputHandler::MSM_Instance = 0;

InputHandler::Inputhandler() : MSM_keystates(0), MSM_mousePosition(new Vector2D(0, 0))
{
    for (int i = 0; i < 2; i++)
    {
        MSM_mouseButtonStates.push_back(false);
    }
}

InputHandler::~InputHandler()
{
    delete MSM_keystate;
    delete MSM_mousePosition;

    MSM_mouseButtonStates.clear();
}

void InputHandler::clean()
{
    // delete any assets created.... none so far
}

void InputHandler::reset()
{
    MSM_mouseButtonStates[LEFT] = false;
    MSM_mouseButtonStates[RIGHT] = false;
}

bool InputHandler::isKeyDown(SDL_Scancode key) const
{
    if (MSM_keystate != 0)
    {
        if (MSM_keystate[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool InputHandler::getMouseButtonState(int buttonNumber) const
{
    return MSM_mouseButtonStates[buttonNumber];
}

Vector2D *InputHandler::getMousePosition() const
{
    return MSM_mousePosition;
}

void InputHandler::update()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            Game::Instance()->quit();
        }
        else if (e.type == SDL_MOUSEMOTION)
        {
            onMouseMove(e);
        }
        else if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            onMouseButtonDown(e);
        }
        else if (e.type == SDL_MOUSEBUTTONUP)
        {
            onMouseButtonUp(e);
        }
        else if (e.type == SDL_KEYDOWN)
        {
            KeyDown();
        }
        else if (e.type == SDL_KEYUP)
        {
            KeyUp();
        }
    }
}

void InputHandler::KeyDown()
{
    MSM_keystate = SDL_GetKeyboardState(0);
}

void InputHandler::KeyUp()
{
    MSM_keystate = SDL_GetKeyboardState(0);
}

void InputHandler::onMouseMove(SDL_Event &e)
{
    MSM_mousePosition->setX(e.motion.x);
    MSM_mousePosition->setY(e.motion.y);
}

void InputHandler::onMouseButtonDown(SDL_Event &e)
{
    if (e.button.button == SDL_BUTTON_LEFT)
    {
        MSM_mouseButtonStates[LEFT] = true;
    }
    if (e.button.button == SDL_BUTTON_RIGHT)
    {
        MSM_mouseButtonStates[RIGHT] = true;
    }
}

void InputHandler::onMouseButtonUp(SDL_Event &e)
{
    if (e.button.button == SDL_BUTTON_LEFT)
    {
        MSM_mouseButtonStates[LEFT] = false;
    }
    if (e.button.button == SDL_BUTTON_RIGHT)
    {
        MSM_mouseButtonStates[RIGHT] = false;
    }
}
