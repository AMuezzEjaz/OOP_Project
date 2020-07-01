#pragma once
#include "GameObject.hpp"
#include "TextureHandler.hpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "game.hpp"

class movement : public GameObject
{
public:
    movement();
    movement(SDL_Renderer *renderer, const char *texturesheet, int x, int y, bool see);
    ~movement();
    void virtual update();
    void reset();
};