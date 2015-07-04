#include "cApp.hpp"

void CApp::OnCleanup() {
  _gridTexture.reset();
  _xTexture.reset();
  _oTexture.reset();
  SDL_Quit();
}
