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
  return OnLoad(renderer, file, 0, 0, 0, false);
}

std::unique_ptr<SDL_Texture, void(*)(SDL_Texture *)> CSurface::OnLoad(SDL_Renderer *renderer, std::string file, Uint8 red, Uint8 green, Uint8 blue) {
  return OnLoad(renderer, file, red, green, blue, true);
}

std::unique_ptr<SDL_Texture, void(*)(SDL_Texture *)> CSurface::OnLoad(SDL_Renderer *renderer, std::string file, Uint8 red, Uint8 green, Uint8 blue, bool isColorKeyNeeded) {
  std::unique_ptr<SDL_Texture, void(*)(SDL_Texture *)> optimized(nullptr, SDL_DestroyTexture);
  
  std::unique_ptr<SDL_Surface, void(*)(SDL_Surface *)> tmp = OnLoad(file);
  if (tmp != nullptr) {
    auto *surface = tmp.get();
    if (isColorKeyNeeded) {
      SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, red, green, blue));
    }
    optimized.reset(SDL_CreateTextureFromSurface(renderer, surface));
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
