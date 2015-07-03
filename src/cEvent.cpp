#include "cEvent.hpp"

CEvent::CEvent() {
  
}

CEvent::~CEvent() {
  
}

void CEvent::OnEvent(SDL_Event *event) {
  switch (event->type) {
    case SDL_WINDOWEVENT_ENTER:
      OnMouseFocus();
      break;
    case SDL_WINDOWEVENT_LEAVE:
      OnMouseBlur();
      break;
    case SDL_WINDOWEVENT_FOCUS_GAINED:
      OnInputFocus();
      break;
    case SDL_WINDOWEVENT_FOCUS_LOST:
      OnInputBlur();
      break;
    case SDL_WINDOWEVENT_HIDDEN:
      OnMinimize();
      break;
    case SDL_WINDOWEVENT_RESTORED:
      OnRestore();
      break;
    case SDL_KEYDOWN:
      OnKeyDown(event->key.keysym.sym, event->key.keysym.scancode, event->key.keysym.mod);
      break;
    case SDL_KEYUP:
      OnKeyUp(event->key.keysym.sym, event->key.keysym.scancode, event->key.keysym.mod);
      break;
    case SDL_MOUSEMOTION: {
      SDL_MouseMotionEvent motion = event->motion;
      auto state = motion.state;
      bool isLeft = (state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;
      bool isRight = (state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0;
      bool isMiddle = (state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0;
      OnMouseMove(motion.x, motion.y, motion.xrel, motion.yrel, isLeft, isRight, isMiddle);
      break;
    }
    case SDL_MOUSEBUTTONDOWN: {
      SDL_MouseButtonEvent button = event->button;
      switch (button.button) {
        case SDL_BUTTON_LEFT:
          OnLButtonDown(button.x, button.y);
          break;
        case SDL_BUTTON_RIGHT:
          OnRButtonDown(button.x, button.y);
          break;
        case SDL_BUTTON_MIDDLE:
          OnMButtonDown(button.x, button.y);
          break;
      }
      break;
    }
    case SDL_MOUSEBUTTONUP: {
      SDL_MouseButtonEvent button = event->button;
      switch (button.button) {
        case SDL_BUTTON_LEFT:
          OnLButtonUp(button.x, button.y);
          break;
        case SDL_BUTTON_RIGHT:
          OnRButtonUp(button.x, button.y);
          break;
        case SDL_BUTTON_MIDDLE:
          OnMButtonUp(button.x, button.y);
          break;
      }
      break;
    }
    case SDL_JOYAXISMOTION:
      OnJoyAxis(event->jaxis.which, event->jaxis.axis, event->jaxis.value);
      break;
    case SDL_JOYBALLMOTION:
      OnJoyBall(event->jball.which, event->jball.ball, event->jball.xrel, event->jball.yrel);
      break;
    case SDL_JOYHATMOTION:
      OnJoyHat(event->jhat.which, event->jhat.hat, event->jhat.value);
      break;
    case SDL_JOYBUTTONDOWN:
      OnJoyButtonDown(event->jbutton.which, event->jbutton.button);
      break;
    case SDL_JOYBUTTONUP:
      OnJoyButtonUp(event->jbutton.which, event->jbutton.button);
      break;
    case SDL_QUIT:
      OnExit();
      break;
    case SDL_SYSWMEVENT:
      // Explicitly ignore this...whatever it does.
      break;
    case SDL_WINDOWEVENT_RESIZED:
      OnResize(event->window.data1, event->window.data2);
      break;
    case SDL_WINDOWEVENT_EXPOSED:
      OnExpose();
      break;
    default:
      OnUser(event->user.type, event->user.code, event->user.data1, event->user.data2);
      break;
  }
}

void CEvent::OnInputFocus() {
  //Pure virtual, do nothing
}

void CEvent::OnInputBlur() {
  //Pure virtual, do nothing
}

void CEvent::OnKeyDown(SDL_Keycode sym, SDL_Scancode scan, Uint16 mod) {
  //Pure virtual, do nothing
}

void CEvent::OnKeyUp(SDL_Keycode sym, SDL_Scancode scan, Uint16 mod) {
  //Pure virtual, do nothing
}

void CEvent::OnMouseFocus() {
  //Pure virtual, do nothing
}

void CEvent::OnMouseBlur() {
  //Pure virtual, do nothing
}

void CEvent::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
  //Pure virtual, do nothing
}

void CEvent::OnMouseWheel(bool Up, bool Down) {
  //Pure virtual, do nothing
}

void CEvent::OnLButtonDown(int mX, int mY) {
  //Pure virtual, do nothing
}

void CEvent::OnLButtonUp(int mX, int mY) {
  //Pure virtual, do nothing
}

void CEvent::OnRButtonDown(int mX, int mY) {
  //Pure virtual, do nothing
}

void CEvent::OnRButtonUp(int mX, int mY) {
  //Pure virtual, do nothing
}

void CEvent::OnMButtonDown(int mX, int mY) {
  //Pure virtual, do nothing
}

void CEvent::OnMButtonUp(int mX, int mY) {
  //Pure virtual, do nothing
}

void CEvent::OnJoyAxis(Uint8 which,Uint8 axis,Sint16 value) {
  //Pure virtual, do nothing
}

void CEvent::OnJoyButtonDown(Uint8 which,Uint8 button) {
  //Pure virtual, do nothing
}

void CEvent::OnJoyButtonUp(Uint8 which,Uint8 button) {
  //Pure virtual, do nothing
}

void CEvent::OnJoyHat(Uint8 which,Uint8 hat,Uint8 value) {
  //Pure virtual, do nothing
}

void CEvent::OnJoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel) {
  //Pure virtual, do nothing
}

void CEvent::OnMinimize() {
  //Pure virtual, do nothing
}

void CEvent::OnRestore() {
  //Pure virtual, do nothing
}

void CEvent::OnResize(int w,int h) {
  //Pure virtual, do nothing
}

void CEvent::OnExpose() {
  //Pure virtual, do nothing
}

void CEvent::OnExit() {
  //Pure virtual, do nothing
}

void CEvent::OnUser(Uint8 type, int code, void* data1, void* data2) {
  //Pure virtual, do nothing
}
