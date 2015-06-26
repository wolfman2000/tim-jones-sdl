#include "cSurface.hpp"

#include <memory>

CSurface::CSurface() {
  
}

std::unique_ptr<SDL_Surface, void(*)(SDL_Surface *)> CSurface::OnLoad(std::string file) {
  std::unique_ptr<SDL_Surface, void(*)(SDL_Surface *)> tmp(nullptr, SDL_FreeSurface);
  
  tmp.reset(SDL_LoadBMP(file.c_str()));
  return tmp;
}
