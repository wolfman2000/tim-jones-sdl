#include "cApp.hpp"
#include "cSurface.hpp"

void CApp::OnRender() {
  // have a weak read only pointer for the purpose of
  // not needing .get() all the time.
  auto *renderer = _renderer.get();
  SDL_RenderClear(renderer);
  SDL_RenderSetViewport(renderer, nullptr);
  
  CSurface::OnDraw(renderer, _gridTexture.get(), 0, 0);

  // Draw each image. Note that range fors won't work since we need the index.
  SDL_Rect rect = { 0, 0, 200, 200 };
  for (int i = 0; i < _grid.size(); ++i) {
    int x = (i % 3) * 200;
    int y = (i / 3) * 200;
    
    if (_grid[i] == GridType::X) {
      CSurface::OnDraw(renderer, _xTexture.get(), x, y, &rect);
    }
    else if (_grid[i] == GridType::O) {
      CSurface::OnDraw(renderer, _oTexture.get(), x, y, &rect);
    }
  }
  
  SDL_RenderPresent(renderer);
}
