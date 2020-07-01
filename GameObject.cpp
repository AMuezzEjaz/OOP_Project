#include "GameObject.hpp"
#include "TextureHandler.hpp"
#include "game.hpp"

GameObject::GameObject()
{
    xpos = 0;
    ypos = 0;
    Flip = SDL_FLIP_NONE;
    viewtime = SDL_GetTicks();
}

GameObject::GameObject(SDL_Renderer *renderer, const char *texturesheet, int x, int y, bool see)
{
    characterTexture = TextureHandler::loadTexture(renderer, texturesheet);
    init_xpos = x;
    init_ypos = y;

    xpos = x;
    ypos = y;
    srcRect.h = 1955;
    srcRect.w = 1278;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 0.75;
    destRect.h = srcRect.h * 0.35;
    flipit = see;
}

void GameObject::update()
{
    xpos++;
    ypos++;
    srcRect.h = 500;
    srcRect.w = 500;
    srcRect.x = 0;
    srcRect.y = 0;
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
    if (name_type != "heart")
    {
        if (flipit)
        {
            Flip = SDL_FLIP_HORIZONTAL;
        }
        else
        {
            Flip = SDL_FLIP_NONE;
        }

        SDL_RenderCopyEx(Game::renderer, characterTexture, &srcRect, &destRect, 0, NULL, Flip);
        Flip = SDL_FLIP_NONE;
    }
}

//GameObject::~GameObject() {}
