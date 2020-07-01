#include "TextureHandler.hpp"
SDL_Texture *TextureHandler::loadTexture(SDL_Renderer *renderer, const char *texturesheet)
{
    SDL_Surface *pTempSurface = IMG_Load(texturesheet);
    SDL_Texture *finalTexture = SDL_CreateTextureFromSurface(renderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    return finalTexture;
};