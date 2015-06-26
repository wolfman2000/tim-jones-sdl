#ifndef C_SURFACE_HPP_
#define C_SURFACE_HPP_

#include <string>
#include <memory>
#include "SDL.h"

class CSurface {
public:
  CSurface();
  
  static std::unique_ptr<SDL_Surface, void(*)(SDL_Surface *)> OnLoad(std::string file);
  
  static bool OnDraw(SDL_Surface * surfDest, SDL_Surface * surfSrc, int x, int y);
};

#endif

