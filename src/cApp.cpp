#include "cApp.hpp"

CApp::CApp(): _isRunning(true), _window(nullptr, SDL_DestroyWindow), _renderer(nullptr, SDL_DestroyRenderer), _testTexture(nullptr, SDL_DestroyTexture) {

}

int CApp::OnExecute() {
  if (OnInit() == false) {
    return -1;
  }
  
  SDL_Event event;
  while (_isRunning) {
    while (SDL_PollEvent(&event)) {
      OnEvent(&event);
    }
    
    OnLoop();
    OnRender();
  }
  
  OnCleanup();
  
  return 0;
}

void CApp::OnExit() {
  _isRunning = false;
}

int main() {
  CApp theApp;
  
  return theApp.OnExecute();
}
