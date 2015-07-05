#include "cApp.hpp"

#include <unordered_map>

// Allow unordered maps to use enum classes.
// http://stackoverflow.com/a/24847480/445373
struct EnumClassHash {
  template <typename T>
  std::size_t operator()(T t) const {
    return static_cast<std::size_t>(t);
  }
};


void CApp::OnLoop() {
  for (auto *entity: CEntity::_entityList) {
    if (entity != nullptr) {
      entity->OnLoop();
    }
  }
}
