#include "cSurface.hpp"

#include <memory>

CSurface::CSurface() {
  
}

std::unique_ptr<SDL_Surface, void(*)(SDL_Surface *)> CSurface::OnLoad(std::string file) {
  std::unique_ptr<SDL_Surface, void(*)(SDL_Surface *)> tmp(nullptr, SDL_FreeSurface);
  
  tmp.reset(SDL_LoadBMP(file.c_str()));
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

bool CSurface::OnDraw(SDL_Surface * surfDest, SDL_Surface * surfSrc, int x, int y) {
  if (surfSrc == nullptr || surfDest == nullptr) {
    return false;
  }
  
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;
  SDL_BlitSurface(surfSrc, nullptr, surfDest, &dest);
  
  return true;
}

bool CSurface::OnDraw(SDL_Renderer * dest, SDL_Surface * src, int x, int y) {
  if (dest == nullptr || src == nullptr) {
    return false;
  }
  
  std::unique_ptr<SDL_Texture, void(*)(SDL_Texture *)> surface(SDL_CreateTextureFromSurface(dest, src), SDL_DestroyTexture);
  SDL_RenderCopy(dest, surface.get(), nullptr, nullptr);
  
  return true;
}

bool CSurface::OnDraw(SDL_Renderer * dest, SDL_Texture * src, int x, int y) {
  if (dest == nullptr || src == nullptr) {
    return false;
  }
  
  SDL_RenderCopy(dest, src, nullptr, nullptr);
  
  return true;
}
