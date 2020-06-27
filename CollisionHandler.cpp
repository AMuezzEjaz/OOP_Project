#include "CollisionHandler.hpp"
#include "Collision.hpp"
#include "Player.hpp"
#include "Virus.hpp"
#include "GunHandler.hpp"

void CollisionHandler::checkPlayertoVirusGunCollision(Player *MSM_Player)
{
    for (int i = 0; i < objects.size(); i++)
    {
        GameObject *MSM_Object = objects[i];

        for (int j = 0; j < MSM_GunHandler::Instance()->getPlayerGun().size(); j++)
        {
            if (MSM_Object->type() != std::string("Virus") || !MSM_Object->updating())
            {
                continue;
            }

            SDL_Rect *MSM_Rect1 = new SDL_Rect();
            MSM_Rect1->x = MSM_Object->getPosition().getX();
            MSM_Rect1->y = MSM_Object->getPosition().getY();
            MSM_Rect1->w = MSM_Object->getWidth();
            MSM_Rect1->h = MSM_Object->getHeight();

            PlayerGun *MSM_PlayerGun = MSM_MSM_Handler::Instance()->getPlayerGuns()[j];

            SDL_Rect *MSM_Rect2 = new SDL_Rect();
            MSM_Rect2->x = MSM_PlayerBullet->getPosition().getX();
            MSM_Rect2->y = MSM_PlayerBullet->getPosition().getY();
            MSM_Rect2->w = MSM_PlayerBullet->getWidth();
            MSM_Rect2->h = MSM_PlayerBullet->getHeight();

            if (collisionRecttoRect(MSM_Rect1, MSM_Rect2))
            {
                if (!MSM_Object->dying() && !MSM_PlayerGun->dying())
                {
                    MSM_PlayerGun->collision();
                    MSM_Object->collision();
                }
            }

            delete MSM_Rect1;
            delete MSM_Rect2;
        }
    }
}

void CollisionHandler::checkPlayerVirusCollision(Player *MSM_Player, const std::vector<GameObject *> &objects)
{
    SDL_Rect *MSM_Rect1 = new SDL_Rect();
    MSM_Rect1->x = MSM_Player->getPosition().getX();
    MSM_Rect1->y = MSM_Player->getPosition().getY();
    MSM_Rect1->w = MSM_Player->getWidth();
    MSM_Rect1->h = MSM_Player->getHeight();

    for (int i = 0; i < objects.size(); i++)
    {
        if (objects[i]->type() != std::string("Virus") || !objects[i]->updating())
        {
            continue;
        }

        SDL_Rect *MSM_Rect2 = new SDL_Rect();
        MSM_Rect2->x = objects[i]->getPosition().getX();
        MSM_Rect2->y = objects[i]->getPosition().getY();
        MSM_Rect2->w = objects[i]->getWidth();
        MSM_Rect2->h = objects[i]->getHeight();

        if (collisionRecttoRect(MSM_Rect1, MSM_Rect2))
        {
            if (!objects[i]->dead() && !objects[i]->dying())
            {
                MSM_Player->collision();
            }
        }

        delete MSM_Rect2;
    }

    delete MSM_Rect1;
}