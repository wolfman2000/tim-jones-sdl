#include "cApp.hpp"
#include "cSurface.hpp"
#include "resource_path.hpp"

#include "SDL_image.h"

bool CApp::OnInit() {
  // We don't HAVE to initialize everything, but it is convenient.
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    return false;
  }
  
  _window.reset(SDL_CreateWindow("Tim Jones Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0));
  
  if (_window == nullptr) {
    return false;
  }
  
  if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
    return false;
  }

  _renderer.reset(SDL_CreateRenderer(_window.get(), -1, SDL_RENDERER_ACCELERATED));
  if (_renderer == nullptr) {
    return false;
  }
  
  std::string startingPath = getResourcePath();
  
  if (_yoshiRight.OnLoad(_renderer.get(), startingPath + "yoshi.bmp", 64, 64, 8) == false) {
    return false;
  }
  
  if (_yoshiLeft.OnLoad(_renderer.get(), startingPath + "yoshiLeft.bmp", 64, 64, 8) == false) {
    return false;
  }
  
  _yoshiLeft.SetX(100.f);
  
  CEntity::_entityList.push_back(&_yoshiRight);
  CEntity::_entityList.push_back(&_yoshiLeft);
  
  return true;
}
