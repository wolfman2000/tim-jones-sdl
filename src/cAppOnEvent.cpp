#include "cApp.hpp"

void CApp::OnEvent(SDL_Event *event) {
  if (event->type == SDL_QUIT) {
    _isRunning = false;
  }
}
