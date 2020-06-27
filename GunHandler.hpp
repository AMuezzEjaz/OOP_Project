#include <iostream>
#include <vector>
#include "Virus.hpp"

class GunHandler
{
public:
    static GunHandler *Instance()
    {
        if (MSM_Instance == 0)
        {
            MSM_Instance = new GunHandler();
            return MSM_Instance;
        }
        return MSM_Instance;
    }

    void addPlayerGuns(int x, int y, int width, int height, std::string textureID, int numFrames);

    void updateGuns();
    void drawGuns();

    void clearGuns();

    const std::vector<PlayerBullet *> getPlayerGuns() { return MSM_playerGuns; }

private:
    GunHandler();
    ~GunHandler();

    GunHandler(const GunHandler &);
    GunHandler &operator=(const GunHandler &);

    static GunHandler *MSM_Instance;

    std::vector<PlayerGun *> MSM_playerGuns;
};

typedef GunHandler MSM_GunHandler;
