#include "cEntity.hpp"

std::vector<CEntity *> CEntity::_entityList;

CEntity::CEntity(): _animControl(), _surfEntity(nullptr, SDL_DestroyTexture), _x(0.f), _y(0.f), _width(0), _height(0), _animState(0) {
  
}

CEntity::~CEntity() {
  
}

bool CEntity::OnLoad(SDL_Renderer *renderer, std::string file, int w, int h, int frames) {
  _surfEntity = CSurface::OnLoad(renderer, file, 255, 0, 255);
  if (_surfEntity == nullptr) {
    return false;
  }
  
  this->_width = w;
  this->_height = h;
  this->_animControl.SetMaxFrames(frames);
  
  return true;
}

void CEntity::OnLoop() {
  _animControl.OnAnimate();
}

void CEntity::OnRender(SDL_Renderer *renderer) {
  if (_surfEntity == nullptr || renderer == nullptr) {
    return;
  }
  
  SDL_Rect clip = { _animState * _width, _animControl.GetCurrentFrame() * _height, _width, _height };
  CSurface::OnDraw(renderer, _surfEntity.get(), _x, _y, &clip);
}

void CEntity::OnCleanup() {
  _surfEntity.reset();
}

void CEntity::SetX(float x) {
  _x = x;
}

float CEntity::GetX() const {
  return _x;
}

void CEntity::SetY(float y) {
  _y = y;
}

float CEntity::GetY() const {
  return _y;
}
