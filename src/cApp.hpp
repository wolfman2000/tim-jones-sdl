#ifndef C_APP_HPP_
#define C_APP_HPP_

#include <memory>

#include "SDL.h"
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
private:
  bool _isRunning;
  
  std::unique_ptr<SDL_Window, void(*)(SDL_Window *)> _window;
  
  std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer *)> _renderer;
  
  std::unique_ptr<SDL_Texture, void(*)(SDL_Texture *)> _gridTexture;
  
  std::unique_ptr<SDL_Texture, void(*)(SDL_Texture *)> _xTexture;
  
  std::unique_ptr<SDL_Texture, void(*)(SDL_Texture *)> _oTexture;
};

#endif

