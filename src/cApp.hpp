#ifndef C_APP_HPP_
#define C_APP_HPP_

#include <memory>
#include <array>

#include "SDL.h"
#include "cAnimation.hpp"
#include "cEntity.hpp"
#include "cEvent.hpp"

class CApp: public CEvent {
public:
  CApp();
  
  int OnExecute();
  
  bool OnInit();
  
  void OnEvent(SDL_Event* event);
  
  void OnLoop();
  
  void OnRender();
  
  // This function may not be as needed much with C++11.
  // Still is good to have perhaps.
  void OnCleanup();
  
  // Since the app is also an event, override quit to do exit the app.
  void OnExit() override;
  
  // Override the left button down behavior.
  void OnLButtonDown(int mX, int mY) override;
  
  // Override the key down behavior to allow for resetting the game.
  void OnKeyDown(SDL_Keycode sym, SDL_Scancode scan, Uint16 mod) override;
  
private:
  bool _isRunning;
  
  std::unique_ptr<SDL_Window, void(*)(SDL_Window *)> _window;
  
  std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer *)> _renderer;
  
  CEntity _yoshiRight;
  CEntity _yoshiLeft;
};

#endif

