#include "cApp.hpp"
#include "cSurface.hpp"

void CApp::OnRender() {
  // have a weak read only pointer for the purpose of
  // not needing .get() all the time.
  auto *renderer = _renderer.get();
  SDL_RenderClear(renderer);
  SDL_RenderSetViewport(renderer, nullptr);
  
  CSurface::OnDraw(renderer, _backgroundTexture.get(), 0, 0);
  
  SDL_Rect yoshi = { 0, _animYoshi.GetCurrentFrame() * 64, 64, 64 };
  CSurface::OnDraw(renderer, _yoshiTexture.get(), 290, 220, &yoshi);
  
  SDL_RenderPresent(renderer);
}
