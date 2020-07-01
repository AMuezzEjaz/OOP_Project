#include "movement.hpp"

movement::movement()
{
}

movement::movement(SDL_Renderer *renderer, const char *texturesheet, int x, int y, bool see)
{
    characterTexture = TextureHandler::loadTexture(renderer, texturesheet);

    init_xpos = x;
    init_ypos = y;
    xpos = x;
    ypos = y;
    viewtime = SDL_GetTicks();
    flipit = see;
    name_type = "police";
    collision = false;
}

void movement::update()
{
    if (flipit == false)
    {
        xpos++;
    }
    else
    {
        xpos--;
    }

    ypos++;
    ypos = 100 * sin((double)SDL_GetTicks() / 500) + 200;
    srcRect.h = 32;
    srcRect.w = 60;
    srcRect.x = 65;
    srcRect.y = 202;
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;

    Uint32 moment = SDL_GetTicks();
    if (((int)moment - viewtime > (rand() % 3500 + 1000)))
    {
        flipit = true;
        viewtime = moment;
    }
}
movement::~movement() {}

void movement::reset()
{
    xpos = init_xpos;
    ypos = init_ypos;
    viewtime = SDL_GetTicks();
    name_type = "police";
    collision = false;
}