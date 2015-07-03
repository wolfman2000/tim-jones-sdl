#include "cSurface.hpp"

#include <memory>

#include "SDL_image.h"

CSurface::CSurface() {
  
}

std::unique_ptr<SDL_Surface, void(*)(SDL_Surface *)> CSurface::OnLoad(std::string file) {
  std::unique_ptr<SDL_Surface, void(*)(SDL_Surface *)> tmp(nullptr, SDL_FreeSurface);
  
  tmp.reset(IMG_Load(file.c_str()));
  return tmp;
}

std::unique_ptr<SDL_Texture, void(*)(SDL_Texture *)> CSurface::OnLoad(SDL_Renderer *renderer, std::string file) {
  std::unique_ptr<SDL_Texture, void(*)(SDL_Texture *)> optimized(nullptr, SDL_DestroyTexture);
  
  std::unique_ptr<SDL_Surface, void(*)(SDL_Surface *)> tmp = OnLoad(file);
  if (tmp != nullptr) {
    optimized.reset(SDL_CreateTextureFromSurface(renderer, tmp.get()));
  }
  
  return optimized;
}

bool CSurface::OnDraw(SDL_Renderer * dest, SDL_Texture * src, int x, int y) {
  if (dest == nullptr || src == nullptr) {
    return false;
  }
  
  SDL_RenderCopy(dest, src, nullptr, nullptr);
  
  return true;
}

bool CSurface::OnDraw(SDL_Renderer * dest, SDL_Texture * src, int x, int y, SDL_Rect *clip) {
  if (dest == nullptr || src == nullptr) {
    return false;
  }
  
  SDL_Rect destR = { x, y, 640, 480 };
  if (clip != nullptr) {
    destR.w = clip->w;
    destR.h = clip->h;
  }

  SDL_RenderCopy(dest, src, clip, &destR);
  return true;
}
