#ifndef C_APP_HPP_
#define C_APP_HPP_

#include <memory>
#include <array>

#include "SDL.h"
#include "cEvent.hpp"

enum class GridType {
  None,
  X,
  O
};

enum class PlayerNumber {
  One,
  Two
};

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
  
  // App specific item to reset the game.
  void Reset();
  
  // App specific item to set a cell.
  void SetCell(int id, GridType type);
private:
  bool _isRunning;
  
  std::unique_ptr<SDL_Window, void(*)(SDL_Window *)> _window;
  
  std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer *)> _renderer;
  
  std::unique_ptr<SDL_Texture, void(*)(SDL_Texture *)> _gridTexture;
  
  std::unique_ptr<SDL_Texture, void(*)(SDL_Texture *)> _xTexture;
  
  std::unique_ptr<SDL_Texture, void(*)(SDL_Texture *)> _oTexture;
  
  // Top left to bottom right is the grid.
  std::array<GridType, 9> _grid;
  
  PlayerNumber _playerNumber;
};

#endif

