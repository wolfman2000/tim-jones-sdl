#include "cApp.hpp"

void CApp::OnCleanup() {
  for (auto *entity: CEntity::_entityList) {
    if (entity != nullptr) {
      entity->OnCleanup();
    }
  }
  
  CEntity::_entityList.clear();
  
  SDL_Quit();
}
