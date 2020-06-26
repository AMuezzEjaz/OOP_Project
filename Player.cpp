#include "Player.hpp"
#include "game.hpp"
#include "InputHandler.hpp"
#include "GunHandler.hpp"

using namespace std;

Player::Player() : GunObject(),
                   MSM_invulnerable(false),
                   MSM_invulnerableTime(200),
                   MSM_invulnerableCounter(0)
{
}

void Player::collision()
{
    if (!MSM_invulnerable && !MSM_Game::Instance()->getLevelComplete())
    {
        MSM_textureID = "largeexplosion";
        MSM_currentFrame = 0;
        MSM_numFrames = 9;
        MSM_width = 60;
        MSM_height = 60;
        MSM_Dying = true;
    }
}

void Player::load() // ----------> Mubeen
{
}

void Player::draw()
{
    gunObject::draw();
}

void Player::handleAnimation()
{
    if (MSM_invulnerable)
    {
        if (MSM_invulnerableCounter == MSM_invulnerableTime)
        {
            MSM_invulnerable = false;
            MSM_invulnerableCounter = 0;
            MSM_alpha = 255;
        }
        else
        {
            if (MSM_alpha == 255)
            {
                MSM_alpha = 0;
            }
            else
            {
                MSM_alpha = 255;
            }
        }

        MSM_invulnerableCounter++;
    }

    if (!MSM_Dead)
    {
        if (MSM_velocity.getX() < 0)
        {
            MSM_angle = -10.0;
        }
        else if (MSM_velocity.getX() > 0)
        {
            MSM_angle = 10.0;
        }
        else
        {
            MSM_angle = 0.0;
        }
    }

    MSM_currentFrame = int(((SDL_GetTicks() / (100)) % m_numFrames));
}

void Player::update()
{
    if (MSM_Game::Instance()->getLevelComplete())
    {
        if (MSM_position.getX() >= MSM_Game::Instance()->getGameWidth())
        {
            MSM_Game::Instance()->setCurrentLevel(MSM_Game::Instance()->getCurrentLevel() + 1);
        }
        else
        {
            MSM_velocity.setY(0);
            MSM_velocity.setX(3);
            GunObject::update();
            handleAnimation();
        }
    }
    else
    {
        if (!MSM_Dying)
        {
            MSM_velocity.setX(0);
            MSM_velocity.setY(0);

            handleInput();

            GunObject::update();

            handleAnimation();
        }
        else
        {
            MSM_currentFrame = int(((SDL_GetTicks() / (100)) % MSM_numFrames));

            if (MSM_deathCounter == MSM_deathTime)
            {
                ressurect();
            }
            MSM_deathCounter++;
        }
    }
}

void Player::ressurect()
{
    MSM_Game::Instance()->setPlayerLives(MSM_Game::Instance()->getPlayerLives() - 1);

    MSM_position.setX(10);
    MSM_position.setY(200);
    MSM_Dying = false;

    MSM_textureID = "player";

    MSM_currentFrame = 0;
    MSM_numFrames = 5;
    MSM_width = 101;
    MSM_height = 46;

    MSM_deathCounter = 0;
    MSM_invulnerable = true;
}

void Player::clean()
{
    GunObject::clean();
}

void Player::handleInput()
{
    if (!MSM_Dead)
    {
        if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
        {
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
        {
        }

        if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
        {
        }
        else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
        {
        }
        if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
        {
            if (MSM_GunCounter == MSM_GunFiringSpeed)
            {
                MSM_GunCounter = 0;
            }

            MSM_GunCounter++;
        }
        else
        {
            MSM_GunCounter = MSM_GunFiringSpeed;
        }
    }
}