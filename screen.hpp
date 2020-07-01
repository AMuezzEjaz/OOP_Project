#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Screen
{
protected:
    SDL_Texture *main_background;

public:
    Screen();
    Screen(SDL_Renderer *renderer);
    virtual ~Screen();
    virtual void render(SDL_Renderer *renderer);
    virtual std::string button_hover(int, int);
};
