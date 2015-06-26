#ifndef C_APP_HPP_
#define C_APP_HPP_

#include "SDL.h"

class CApp {
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
private:
  bool _isRunning;
};

#endif

