#pragma once
#include "GameObject.hpp"
#include "TextureHandler.hpp"
#include "game.hpp"

class Player : public GameObject
{
private:
    int hit;
    int up;
    int down;
    int left;
    int right;

    bool in_left;
    bool in_right;
    bool in_up;
    bool in_down;

public:
    Player(SDL_Renderer *renderer, const char *texturesheet, int x, int y, bool see);
    ~Player();
    void virtual update(Uint32);
    int health;
    void goup();
    void godown();
    void goleft();
    void goright();
    void reset();
};