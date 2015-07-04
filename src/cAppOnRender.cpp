#include "cApp.hpp"
#include "cSurface.hpp"

void CApp::OnRender() {
  // have a weak read only pointer for the purpose of
  // not needing .get() all the time.
  auto *renderer = _renderer.get();
  SDL_RenderClear(renderer);
  SDL_RenderSetViewport(renderer, nullptr);
  
//  SDL_Rect corner = {0, 0, 20, 20};
//  SDL_RenderSetViewport(renderer, &corner);
  
  CSurface::OnDraw(renderer, _gridTexture.get(), 0, 0);
  
//  SDL_RenderSetViewport(renderer, nullptr);
  
  SDL_RenderPresent(renderer);
}
