#include "cApp.hpp"

void CApp::OnEvent(SDL_Event *event) {
  CEvent::OnEvent(event);
}

void CApp::OnKeyDown(SDL_Keycode sym, SDL_Scancode scan, Uint16 mod) {
  if (sym == SDLK_r) {
    Reset();
  }
}

void CApp::OnLButtonDown(int mX, int mY) {
  int id = ( mX / 200 ) + (( mY / 200) * 3);
  
  if (_grid[id] != GridType::None) {
    return;
  }
  
  if (_playerNumber == PlayerNumber::One) {
    SetCell(id, GridType::X);
    _playerNumber = PlayerNumber::Two;
  }
  else {
    SetCell(id, GridType::O);
    _playerNumber = PlayerNumber::One;
  }
}

void CApp::OnExit() {
  _isRunning = false;
}
