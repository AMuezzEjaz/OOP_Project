#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>

class TextureHandler
{
public:
    //whatever texture to load
    static SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *file);
};