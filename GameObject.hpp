#pragma once
#include "game.hpp"
//#include "Vector2D.h"
//#include <memory>

class GameObject
{
public:
    GameObject();
    virtual ~GameObject(){};
    GameObject(SDL_Renderer *renderer, const char *texturesheet, int x, int y, bool see);

    //virtual void draw() = 0;

    void virtual update();
    void Render();

    int virtual get_xpos() { return xpos; }
    int virtual get_ypos() { return ypos; }

    int getWidth() {}
    int getHeight() {}

    //   void scroll(float scrollSpeed)
    //   {
    //       // Add this later
    //   }
    bool collision;
    SDL_Rect srcRect, destRect;
    Uint32 viewtime;

    //bool updating() { return MSM_Updating; }
    //bool dead() { return MSM_Dead; }
    //bool dying() { return MSM_dying; }

    SDL_Rect getDestRect() { return destRect; }
    std::string get_type() { return name_type; }
    bool flipit;

protected:
    int init_xpos;
    int init_ypos;
    int xpos;
    int ypos;
    SDL_Texture *characterTexture;
    SDL_Renderer *renderer;
    SDL_RendererFlip Flip;
    std::string name_type;
};