#include "cAnimation.hpp"

CAnimation::CAnimation(): _currentFrame(0), _frameInc(1), _frameRate(100), _oldTime(0), _maxFrames(0), _isOscillate(false) {
  
}

void CAnimation::OnAnimate() {
  if (_oldTime + _frameRate > SDL_GetTicks()) {
    return;
  }
  
  _oldTime = SDL_GetTicks();
  
  _currentFrame += _frameInc;
  
  if (IsOscillate()) {
    if (_frameInc > 0) {
      if (_currentFrame >= _maxFrames - 1) {
        _frameInc = -_frameInc;
      }
    }
    else {
      if (_currentFrame <= 0) {
        _frameInc = -_frameInc;
      }
    }
  }
  else {
    if (_currentFrame >= _maxFrames) {
      _currentFrame = 0;
    }
  }
}

void CAnimation::SetFrameRate(int rate) {
  _frameRate = rate;
}

bool CAnimation::IsOscillate() const {
  return _isOscillate;
}

void CAnimation::SetOscillate(bool isOscillate) {
  _isOscillate = isOscillate;
}

int CAnimation::GetMaxFrames() const {
  return _maxFrames;
}

void CAnimation::SetMaxFrames(int frames) {
  _maxFrames = frames;
}

int CAnimation::GetCurrentFrame() const {
  return _currentFrame;
}

void CAnimation::SetCurrentFrame(int frame) {
  if (frame < 0 || frame >= GetMaxFrames()) {
    return;
  }
  
  _currentFrame = frame;
}
