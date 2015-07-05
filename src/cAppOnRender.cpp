#include "cApp.hpp"
#include "cSurface.hpp"

void CApp::OnRender() {
  // have a weak read only pointer for the purpose of
  // not needing .get() all the time.
  auto *renderer = _renderer.get();
  SDL_RenderClear(renderer);
  SDL_RenderSetViewport(renderer, nullptr);
  
  for (auto *entity: CEntity::_entityList) {
    if (entity != nullptr) {
      entity->OnRender(renderer);
    }
  }
  
  SDL_RenderPresent(renderer);
}
