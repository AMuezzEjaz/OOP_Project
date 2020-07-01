#include "menu_screen.hpp"

menu_screen::menu_screen(SDL_Renderer *renderer)
{
    main_background = TextureHandler::loadTexture(renderer, bgscreen);
    play = new Button("assets/play_button.png", 240, 269, 335, 74, 1, renderer);
    how_to_play = new Button("assets/help_button.png", 240, 469, 335, 74, 1, renderer);
}

menu_screen::menu_screen(){};

menu_screen::~menu_screen(){};

void menu_screen::render(SDL_Renderer *renderer)
{
    SDL_RenderCopyEx(renderer, main_background, 0, 0, 0, NULL, SDL_FLIP_NONE);
    play->Render(renderer);
    how_to_play->Render(renderer);
}

std::string menu_screen::button_hover(int xmouse, int ymouse)
{
    play->set_hovering(xmouse, ymouse);
    how_to_play->set_hovering(xmouse, ymouse);

    if (play->get_hovering())
    {
        return "play button";
    }
    else if (how_to_play->get_hovering())
    {
        return "how to play";
    }
    else
    {
        return "no hover";
    }
}