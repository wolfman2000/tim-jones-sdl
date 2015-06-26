#include "cSurface.hpp"

#include <memory>

CSurface::CSurface() {
  
}

std::unique_ptr<SDL_Surface, void(*)(SDL_Surface *)> CSurface::OnLoad(std::string file) {
  std::unique_ptr<SDL_Surface, void(*)(SDL_Surface *)> tmp(nullptr, SDL_FreeSurface);
  
  tmp.reset(SDL_LoadBMP(file.c_str()));
  return tmp;
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