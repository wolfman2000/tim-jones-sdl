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

Winner CApp::GetWinner() {
  if (
      (_grid[0] == GridType::X && _grid[1] == GridType::X && _grid[2] == GridType::X) ||
      (_grid[3] == GridType::X && _grid[4] == GridType::X && _grid[5] == GridType::X) ||
      (_grid[6] == GridType::X && _grid[7] == GridType::X && _grid[8] == GridType::X) ||
      (_grid[0] == GridType::X && _grid[3] == GridType::X && _grid[6] == GridType::X) ||
      (_grid[1] == GridType::X && _grid[4] == GridType::X && _grid[7] == GridType::X) ||
      (_grid[2] == GridType::X && _grid[5] == GridType::X && _grid[8] == GridType::X) ||
      (_grid[0] == GridType::X && _grid[4] == GridType::X && _grid[8] == GridType::X) ||
      (_grid[2] == GridType::X && _grid[4] == GridType::X && _grid[6] == GridType::X)) {
    return Winner::X;
  }
  
  if (
      (_grid[0] == GridType::O && _grid[1] == GridType::O && _grid[2] == GridType::O) ||
      (_grid[3] == GridType::O && _grid[4] == GridType::O && _grid[5] == GridType::O) ||
      (_grid[6] == GridType::O && _grid[7] == GridType::O && _grid[8] == GridType::O) ||
      (_grid[0] == GridType::O && _grid[3] == GridType::O && _grid[6] == GridType::O) ||
      (_grid[1] == GridType::O && _grid[4] == GridType::O && _grid[7] == GridType::O) ||
      (_grid[2] == GridType::O && _grid[5] == GridType::O && _grid[8] == GridType::O) ||
      (_grid[0] == GridType::O && _grid[4] == GridType::O && _grid[8] == GridType::O) ||
      (_grid[2] == GridType::O && _grid[4] == GridType::O && _grid[6] == GridType::O)) {
    return Winner::O;
  }
  
  // No obvious winner. Determine if we have a draw.
  std::unordered_map<GridType, int, EnumClassHash> scores;
  scores[GridType::X] = 0;
  scores[GridType::O] = 0;
  
  for (auto &square: _grid) {
    ++scores[square];
  }
  
  if (scores[GridType::X] == 5 || scores[GridType::O] == 5) {
    return Winner::Draw;
  }
  
  return Winner::None;
}

void CApp::OnLoop() {
  if (_winner == Winner::None) {
    _winner = GetWinner();
  }
  
  
}
