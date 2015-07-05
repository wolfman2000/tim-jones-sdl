#ifndef C_ENTITY_HPP_
#define C_ENTITY_HPP_

#include <vector>
#include <memory>
#include "SDL.h"
#include "cAnimation.hpp"
#include "cSurface.hpp"

class CEntity {
public:
  CEntity();
  
  virtual ~CEntity();
  
  // keep up with all entities.
  static std::vector<CEntity *> _entityList;
  
  virtual bool OnLoad(SDL_Renderer *renderer, std::string file, int w, int h, int frames);
  
  virtual void OnLoop();
  virtual void OnRender(SDL_Renderer *renderer);
  virtual void OnCleanup();
  
  void SetX(float x);
  float GetX() const;
  
  void SetY(float y);
  float GetY() const;
  
protected:
  CAnimation _animControl;
  std::unique_ptr<SDL_Texture, void (*)(SDL_Texture *)> _surfEntity;
  
private:
  float _x;
  float _y;
  int _width;
  int _height;
  int _animState;
  
};

#endif
