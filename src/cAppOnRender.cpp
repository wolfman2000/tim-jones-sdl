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
  
//  CSurface::OnDraw(renderer, _testTexture.get(), 0, 0);
  
//  SDL_RenderSetViewport(renderer, nullptr);
  SDL_Rect src ={ 0, 0, 50, 50 };
  CSurface::OnDraw(renderer, _testTexture.get(), 100, 100, &src);
  
  SDL_RenderPresent(renderer);
}
