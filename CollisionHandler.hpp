#include <iostream>
#include <vector>

class Player;
class GameObject;

class CollisionHandler
{
public:
    void checkPlayertoVirusGunCollision(Player *MSM_Player);
    void checkPlayerVirusCollision(Player *MSM_Player, const std::vector<GameObject *> &objects);
};