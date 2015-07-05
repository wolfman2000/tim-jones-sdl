#include "cApp.hpp"

CApp::CApp(): _isRunning(true), _window(nullptr, SDL_DestroyWindow), _renderer(nullptr, SDL_DestroyRenderer), _gridTexture(nullptr, SDL_DestroyTexture), _xTexture(nullptr, SDL_DestroyTexture), _oTexture(nullptr, SDL_DestroyTexture), _grid(), _playerNumber(PlayerNumber::One) {
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

void CApp::Reset() {
  for (auto &square: _grid) {
    square = GridType::None;
  }
  _playerNumber = PlayerNumber::One;
}

void CApp::SetCell(int id, GridType type) {
  if (id < 0 || id >= _grid.size()) {
    return;
  }
  
  _grid[id] = type;
}

int main() {
  CApp theApp;
  
  return theApp.OnExecute();
}
