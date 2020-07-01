#pragma once
#include <iostream>
#include "Button.hpp"
#include "screen.hpp"

class menu_screen : public Screen
{
private:
    Button *play;
    Button *how_to_play;
    const char *bgscreen = "assets/main_menu.png";

public:
    menu_screen();
    menu_screen(SDL_Renderer *renderer);
    void render(SDL_Renderer *renderer);
    std::string button_hover(int, int);
    virtual ~menu_screen();
};