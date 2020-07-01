#include "Player.hpp"
Player::Player(SDL_Renderer *renderer, const char *texturesheet, int x, int y, bool see)
{
    characterTexture = TextureHandler::loadTexture(renderer, texturesheet);
    init_xpos = x;
    init_ypos = y;

    xpos = x;
    ypos = y;
    name_type = "player";
    flipit = see;
}

void Player::update(Uint32 framerate)
{
    if (right > -1 & right < 10)
    {
        int temp = srcRect.x;
        srcRect.x = 64 * int(((SDL_GetTicks() / 50) % 5));

        if (temp != srcRect.x)
        {
            right++;
            if (in_right)
            {

                if (xpos + 18 < 800 - 100)
                {
                    xpos += 18;
                    destRect.x = xpos;
                }
            }
            else if (in_left)
            {
                if (xpos - 18 > 0)
                {
                    xpos -= 18;
                    destRect.x = xpos;
                }
            }
        }
        if (right >= 5)
        {
            right = -1;
            in_right = false;
            in_left = false;
        }
    }
    if (up > -1 & up < 10)
    {
        int temp = srcRect.x;
        srcRect.x = 64 * int(((SDL_GetTicks() / 50) % 5));

        if (temp != srcRect.x)
        {
            up++;
            if (in_up)
            {
                if (ypos + 18 < 800 - 100)
                {
                    ypos += 18;
                    destRect.y = ypos;
                }
            }
            else if (in_down)
            {
                if (ypos - 18 > 0)
                {
                    ypos -= 18;
                    destRect.y = xpos;
                }
            }
        }
        if (up >= 5)
        {
            up = -1;
            in_up = false;
            in_down = false;
        }
    }

    else
    {
        srcRect.h = 64;
        srcRect.w = 65;
        srcRect.x = 65;
        srcRect.y = 711;

        destRect.x = xpos;
        destRect.y = ypos - 100;
        destRect.w = srcRect.w * 2;
        destRect.h = srcRect.h * 2;
    }
}

void Player::goleft()
{
    Flip = SDL_FLIP_HORIZONTAL;
    right = 0;
    flipit = true;
    in_left = true;
}

void Player::goright()
{

    //flipped = false;
    flipit = false;
    if (Flip == SDL_FLIP_HORIZONTAL)
    {
        Flip = SDL_FLIP_NONE;
    }
    right = 0;
    in_right = true;
}

void Player::reset()
{
    xpos = init_xpos;
    ypos = init_ypos;
    right = -1;
    left = -1;
    down = -1;
    up = -1;
    hit = -1;
    in_up = false;
    in_down = false;
    in_left = false;
    in_right = false;
}
