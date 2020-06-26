#pragma once
#include "game.hpp"
#include "SDL.h"
#include "SDL_image.h"

class TextureHandler
{
public:
    //whatever texture to load
    static SDL_Texture *LoadTexture(SDL_Renderer *renderer, const char *file);
}