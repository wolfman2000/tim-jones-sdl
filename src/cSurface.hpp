#ifndef C_SURFACE_HPP_
#define C_SURFACE_HPP_

#include <string>
#include <memory>
#include "SDL.h"

class CSurface {
public:
  CSurface();
  
  static std::unique_ptr<SDL_Surface, void(*)(SDL_Surface *)> OnLoad(std::string file);
  
  static std::unique_ptr<SDL_Texture, void(*)(SDL_Texture *)> OnLoad(SDL_Renderer *renderer, std::string file);
  
  static std::unique_ptr<SDL_Texture, void(*)(SDL_Texture *)> OnLoad(SDL_Renderer *renderer, std::string file, Uint8 red, Uint8 green, Uint8 blue);
  
  static bool OnDraw(SDL_Renderer * dest, SDL_Texture * src, int x, int y);
  
  static bool OnDraw(SDL_Renderer * dest, SDL_Texture * src, int x, int y, SDL_Rect *clip);
private:
  static std::unique_ptr<SDL_Texture, void(*)(SDL_Texture *)> OnLoad(SDL_Renderer *renderer, std::string file, Uint8 red, Uint8 green, Uint8 blue, bool isColorKeyNeeded);
};

#endif

