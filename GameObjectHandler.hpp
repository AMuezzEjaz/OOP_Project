#include <string>
#include <map>
#include <iostream>
#include "GameObject.hpp"

class BaseCreator
{
public:
    virtual GameObject *createGameObject() const = 0;
    virtual ~BaseCreator() {}
};

class GameObjectHandler
{
public:
    static GameObjectHandler *Instance()
    {
        if (MSM_Instance == 0)
        {
            MSM_Instance = new GameObjectHandler();
        }
        return MSM_Instance;
    }
    bool registerType(std::string typeID, BaseCreator *MSM_Creator)
    {
        std::map<std::string, BaseCreator *>::iterator it = MSM_creators.find(typeID);
        if (it != MSM_creators.end())
        {
            delete MSM_Creator;
        }
        MSM_creators[typeID] = MSM_Creator;
        return true;
    }

    GameObject *create(std::string typeID)
    {
        std::map<std::string, BaseCreator *>::iterator it = MSM_creators.find(typeID);
        if (it == MSM_creators.end())
        {
            std::cout << typeID << ": Type not found." << std::endl;
            return NULL;
        }
        BaseCreator *MSM_Creator = (*it).second;
        return MSM_Creator->createGameObject();
    }

private:
    GameObjectHandler() {}
    ~GameObjectHandler() {}
    std::map<std::string, BaseCreator *> MSM_creators;
    static GameObjectHandler *MSM_Instance;
};

typedef GameObjectHandler MSM_GameObjectHandler;