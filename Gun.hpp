#include "GunObject.hpp"
#include "TextureHandler.hpp"
#include "game.hpp"
#include <iostream>

class PlayerGun : public GunObject
{
public:
    PlayerGun() : GunObject()
    {
        MSM_deathTime = 5;
    }

    virtual ~PlayerGun() {}

    virtual std::string type() { return "PlayerGun"; }

    virtual void load() // --------------> Mubeen
    {
    }

    virtual void draw()
    {
        GunObject::draw();
    }

    virtual void collision()
    {
        MSM_textureID = "smallexplosion";
        MSM_currentFrame = 0;
        MSM_numFrames = 2;
        MSM_width = 20;
        MSM_height = 20;
        MSM_Dying = true;
    }

    virtual void update()
    {
        if (!MSM_Dying)
        {
            GunObject::update();
        }
        else
        {
            DyingAnimation();
        }
    }

    virtual void clean()
    {
        GunObject::clean();
    }
};
