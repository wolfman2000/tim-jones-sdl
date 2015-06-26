#include "cApp.hpp"
#include "cSurface.hpp"
#include "resource_path.hpp"

bool CApp::OnInit() {
  // We don't HAVE to initialize everything, but it is convenient.
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    return false;
  }
  
  _window.reset(SDL_CreateWindow("Tim Jones Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0));
  
  if (_window == nullptr) {
    return false;
  }
  
  _renderer.reset(SDL_CreateRenderer(_window.get(), -1, SDL_RENDERER_ACCELERATED));
  if (_renderer == nullptr) {
    return false;
  }
  
  _testTexture = CSurface::OnLoad(_renderer.get(), getResourcePath() + "dot.bmp");
  if (_testTexture == nullptr) {
    return false;
  }
  
  return true;
}
