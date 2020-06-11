#include <string>
#include <vector>

class GameState_master
{
public:
    virtual ~GameState_master() {}
    virtual void update() = 0;
    virtual void render() = 0;
    virtual bool entering() = 0;
    virtual bool exiting() = 0;
    virtual void resume() {}
    virtual std::string getState() const = 0;

protected:
    GameState_master() : MSM_loadingDone(false), MSM_exiting(false)
    {
    }
    bool MSM_loadingDone;
    bool MSM_exiting;
    std::vector<std::string> MSM_textureList;
};