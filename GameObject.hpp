#include "loadParameters.hpp"
#include "Vector2D.h"
#include <string>
#include <memory>

class GameObject
{
public:
    virtual ~GameObject() {}
    virtual void load(std::unique_ptr<LoadParameters> const &MSM_Parameters) = 0;
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual clean() = 0;
    virtual void collision() = 0;
    virtual std::string type() = 0;
    Vector2D &getPosition() { return MSM_position; }
    Vector2D &getVelocity() { return MSM_velocity; }

    int getWidth() { return MSM_width; }
    int getHeight() { return MSM_Height; }

    void scroll(float scrollSpeed)
    {
        // Add this later
    }

    bool updating() { return MSM_Updating; }
    bool dead() { return MSM_Dead; }
    bool dying() { return MSM_dying; }

protected:
    GameObject() : MSM_position(0, 0), MSM_velocity(0, 0), MSM_acceleration(0, 0), MSM_width(0), MSM_height(0), MSM_currentRow(0), MSM_currentFrame(0), MSM_Updating(false), MSM_Dead(false), MSM_Dying(false), MSM_angle(0), MSM_alpha(255)
    {
    }
    Vector2D MSM_position;
    Vector2D MSM_velocity;
    Vector2D MSM_acceleration;
}