#include "GunHandler.hpp"
#include "game.hpp"

GunHandler *GunHandler::MSM_Instance = new GunHandler();

GunHandler::GunHandler()
{
}

void GunHandler::addPlayerGuns(int x, int y, int width, int height, std::string textureID, int numFrames)
{
    PlayerGun *MSM_playerGuns = new PlayerGun();
    MSM_playerGuns->load(); // --------------------------------->  load textures here

    MSM_playerGuns.push_back(MSM_playerGuns);
}

void GunHandler::clearGuns()
{
    MSM_playerGuns.clear();
}

void GunHandler::updateGuns()
{
    for (std::vector<PlayerGun *>::iterator MSM_it = MSM_playerGuns.begin(); MSM_it != MSM_playerGuns.end();)
    {
        if ((*MSM_it)->getPosition().getX() < 0 || (*MSM_it)->getPosition().getX() > MSM_Game::Instance()->getGameWidth() || (*MSM_it)->getPosition().getY() < 0 || (*MSM_it)->getPosition().getY() > MSM_Game::Instance()->getGameHeight() || (*MSM_it)->dead())
        {
            delete *MSM_it;
            MSM_it = MSM_playerGuns.erase(MSM__it);
        }
        else
        {
            (*MSM_it)->update();
            ++MSM_it;
        }
    }
}

void GunHandler::drawGuns()
{
    for (int p = 0; p < MSM_playerGuns.size(); p++)
    {
        MSM_playerGuns[p]->draw();
    }
}