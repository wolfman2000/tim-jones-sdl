#ifndef C_ANIMATION_HPP_
#define C_ANIMATION_HPP_

#include "SDL.h"

class CAnimation {
public:
  CAnimation();
  
  void OnAnimate();
  
  void SetFrameRate(int rate);
  
  void SetCurrentFrame(int frame);
  
  int GetCurrentFrame() const;
  
  int GetMaxFrames() const;
  
  void SetMaxFrames(int frames);
  
  bool IsOscillate() const;
  
  void SetOscillate(bool isOscillate);
  
private:
  int _currentFrame;
  int _frameInc;
  int _frameRate; // milliseconds?
  long _oldTime;
  int _maxFrames;
  bool _isOscillate;
};

#endif

