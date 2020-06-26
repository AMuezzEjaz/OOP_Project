#include "C:\mingw_dev_lib\include\SDL2\SDL.h"
#include "GameObject.hpp"

class GunObject : public GameObject
{
public:
    virtual ~GunObject() {}
    virtual void load(); // Mubeen needs to add the required functionality along with the argument
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void collision() {}

protected:
    GunObject();
    void DyingAnimation();
    int MSM_GunFiringSpeed;
    int MSM_GunCounter;
    int MSM_moveSpeed;
    int MSM_deathTime;
    int MSM_deathCounter;
};