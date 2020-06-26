#include "TextureHandler.hpp"

SDL_Texture *TextureHandler::loadTexture(SDL_Renderer *renderer, const char *texture)
{
    SDL_Surface *pTempSurface = IMG_Load(texture);

    SDL_Texture *finalTexture = SDL_CreateTextureFromSurface(renderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    return finalTexture;
}

// everything went ok, add the texture to list
// if (pTexture != 0)
// {
//     m_textureMap[id] = pTexture;
//     return true;
// }
// // reaching here means something went wrong
// return false;
//

//oid TextureHandler::draw(std::string id, int x, int y, int width, int height, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
//
//   // source
//   SDL_Rect srcRect;
//   // destination
//   SDL_Rect destRect;
//
//   srcRect.x = 0;
//   srcRect.y = 0;
//   srcRect.w = destRect.w = width;
//   srcRect.h = destRect.h = height;
//   destRect.x = x;
//   destRect.y = y;
//   SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
//

//xtureHandler::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
//
//_Rect srcRect;
//_Rect destRect;
//Rect.x = width * currentFrame;
//Rect.y = height * (currentRow - 1);
//Rect.w = destRect.w = width;
//Rect.h = destRect.h = height;
//tRect.x = x;
//tRect.y = y;
//_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
//