#include "cApp.hpp"

void CApp::OnEvent(SDL_Event *event) {
  CEvent::OnEvent(event);
}

void CApp::OnKeyDown(SDL_Keycode sym, SDL_Scancode scan, Uint16 mod) {

}

void CApp::OnLButtonDown(int mX, int mY) {
}

void CApp::OnExit() {
  _isRunning = false;
}
