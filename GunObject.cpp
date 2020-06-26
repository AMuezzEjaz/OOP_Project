#include "GunObject.hpp"
#include "TextureHandler.hpp"
#include "game.hpp"

GunObject::GunObject() : GameObject(), MSM_GunFiringSpeed(0), MSM_GunCounter(0), MSM_moveSpeed(0), MSM_deathTime(0), MSM_deathCounter(0)
{
}

void GunObject::load() // Mubeen needs to do this
{
}

void GunObject::draw()
{
}

void ShooterObject::update()
{
}

void ShooterObject::doDyingAnimation()
{
}