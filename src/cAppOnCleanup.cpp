#include "cApp.hpp"

void CApp::OnCleanup() {
  _backgroundTexture.reset();
  _yoshiTexture.reset();
  SDL_Quit();
}
