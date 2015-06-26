#include "cApp.hpp"

void CApp::OnCleanup() {
  _testTexture.reset();
  SDL_Quit();
}
