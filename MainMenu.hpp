#include <vector>
#include "Menu_master.hpp"
//#include "GameObject.hpp"

class MainMenu : public Menu_master
{
public:
    virtual ~MainMenu() {}
    virtual void update();
    virtual void render();
    virtual bool afterEntering();
    virtual bool afterExiting();
    virtual std::string getState() const { return MSM_menu; }

private:
    virtual void setCallbacks(const std::vector<Callback> &callbacks);
    static void MSM_startPlay();
    static void MSM_exitMenu();
    static const std::string MSM_menu;
    //std::vector<GameObject *> MSM_gameObjects;
};
