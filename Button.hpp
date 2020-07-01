#pragma once
#include "TextureHandler.hpp"

class Button
{
private:
    SDL_Texture *characterTexture;
    SDL_Rect srcRect, desRect;
    int m_xpos;
    int m_ypos;
    int m_width;
    int m_height;
    bool m_hovering;
    bool m_clicked;

public:
    Button();
    Button(const char *texturesheet, int x, int y, int width, int height, int magnification, SDL_Renderer *renderer);
    ~Button();
    void virtual Update();
    void Render(SDL_Renderer *renderer);

    bool get_hovering();
    void set_hovering(int, int);

    int get_height();
    int get_width();
    int get_Xpos();
    int get_Ypos();
};