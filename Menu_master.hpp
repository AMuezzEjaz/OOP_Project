#include "gameState_master.hpp"
//inheriting for changing state
class Menu_master : public GameState_master
{
public:
    virtual ~Menu_master() {}

protected:
    typedef void (*Callback)();
    virtual void setCallbacks(const std::vector<Callback> &callbacks) = 0;
    std::vector<Callback> MSM_callbacks;
};