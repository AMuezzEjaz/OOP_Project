#include <iostream>
#include <vector>
#include "GunObject.hpp"
#include "GameObjectHandler.hpp"

class Player : public GunObject
{
public:
    Player();
    virtual ~Player() {}

    virtual void load(); // ------> Mubeen

    virtual void draw();
    virtual void update();
    virtual void clean();

    virtual void collision();

private:
    void ressurect();

    void handleInput();

    void handleAnimation();

    int MSM_invulnerable;
    int MSM_invulnerableTime;
    int MSM_invulnerableCounter;
};

class PlayerCreator : public BaseCreator
{
    GameObject *createGameObject() const
    {
        return new Player();
    }
};